#ifndef BLUE_DECORATOR_H_
#define BLUE_DECORATOR_H_

#include "PackageColorDecorator.h"

class BlueDecorator : public PackageColorDecorator {
 public:
  BlueDecorator(Package*);
};

#endif  // BLUE_DECORATOR_H_
