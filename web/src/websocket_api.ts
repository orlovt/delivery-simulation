let socket: WebSocket | undefined = undefined;

function sendCommand(command: string, data: any) {
  if (socket!.readyState == WebSocket.OPEN) {
    data.command = command;
    socket!.send(JSON.stringify(data));
  }
}

function connect(host?: string) {
  if (host) {
    socket = new WebSocket(`ws://${host}`, "web_server");
  } else {
    socket = new WebSocket(`ws://${location.host}`, "web_server");
  }
  return new Promise<WebSocket>((resolve, reject) => {
    socket!.onopen = () => {
      resolve(socket!);
    };
  });
}

function disconnect() {
  socket!.close();
}

export { connect, disconnect, sendCommand };
