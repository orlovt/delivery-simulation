
#include "Human.h"

Human::Human(const JsonObject& details) : IEntity(details) {}

void Human::update(double dt) {
  Vector3 destination1(146, 265, -121);
  Vector3 destination2(-191, 265, -112);
  Vector3* d;
  if (b_targetDestination) {
    d = &destination2;
  } else {
    d = &destination1;
  }

  if (position.dist(*d) < 5)
    b_targetDestination = !b_targetDestination;
  direction = (*d - position).unit();
  position = position + direction * speed * dt;
}
