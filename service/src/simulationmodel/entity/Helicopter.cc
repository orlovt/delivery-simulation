#include "Helicopter.h"

Helicopter::Helicopter(const JsonObject& details) : IEntity(details) {
  generateNewDestination();
}

void Helicopter::update(double dt) {
  if (position.dist(destination) < 5) {
    generateNewDestination();
  } else {
    direction = (destination - position).unit();
    position = position + direction * speed * dt;
  }
}

void Helicopter::generateNewDestination() {
  destination = {((static_cast<double>(rand())) / RAND_MAX) * (2900) - 1400,
                 position.y,
                 ((static_cast<double>(rand())) / RAND_MAX) * (1600) - 800};
}
