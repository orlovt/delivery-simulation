import * as THREE from "three";
import $ from "jquery";
import { scene } from "./scene";
import { camera, updateControls } from "./camera";
import { connect, disconnect, sendCommand } from "./websocket_api";
import {
  addEntity,
  updateEntity,
  removeEntity,
  updateAnimations,
} from "./model";
import { loadScene } from "./sceneLoader";
import { initScheduler } from "./tripScheduler";
import { notify } from "./notifications";

const container = $("#scene-container")[0];
const simSpeedSlider = $("#sim-speed");
const stopSimulationButton = $("#stop-simulation")[0];
const addHumanButton = $("#add-human")[0];
const deliveryPopup = $("#delivery-popup");

const sceneFile = "scenes/umn.json";
const clock = new THREE.Clock();

let time = 0.0;
let simSpeed = 1.0;
let renderer = new THREE.WebGLRenderer({ antialias: true });

simSpeedSlider[0].oninput = () => {
  simSpeed = (simSpeedSlider.val() as number) / 10.0;
};

stopSimulationButton.onclick = () => {
  sendCommand("stopSimulation", {});
  disconnect();
};

let humanID = 1;
addHumanButton.onclick = () => {
  sendCommand("CreateEntity", {
    type: "human",
    name: "Human-" + humanID,
    mesh: "assets/model/human.glb",
    position: [700, 290, 400],
    scale: [0.005, 0.005, 0.005],
    rotation: [0, 0, 0, 0],
    direction: [1, 0, 0],
    speed: 10.0,
    radius: 1.0,
    start: 2.0,
    duration: 2.0,
    offset: [0, -0.5, 0],
  });
  humanID += 1;
};

window.onresize = () => {
  camera.aspect = container.clientWidth / container.clientHeight;
  camera.updateProjectionMatrix();
  renderer.setSize(container.clientWidth, container.clientHeight);
};

initScheduler();

connect().then((socket) => {
  socket.onmessage = (msg) => {
    let data = JSON.parse(msg.data);
    switch (data.event) {
      case "AddEntity":
        addEntity(data.details.id, data.details.details);
        break;
      case "UpdateEntity":
        updateEntity(data.details.id, data.details);
        break;
      case "RemoveEntity":
        removeEntity(data.details.id);
        break;
      case "Notification":
        notify(data.details.message);
        break;
      case "DeliveryScheduled":
        deliveryPopup.show();
        deliveryPopup.fadeOut(3000);
        break;
    }
  };

  loadScene(sceneFile);
  renderer.setSize(window.innerWidth, window.innerHeight);
  document.body.appendChild(renderer.domElement);

  renderer.setAnimationLoop(() => {
    let delta = clock.getDelta();
    time += delta;
    updateAnimations(delta);
    sendCommand("Update", { simSpeed: simSpeed });
    updateControls();
    renderer.render(scene, camera);
  });
});
