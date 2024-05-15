#ifndef GREEN_DECORATOR_H_
#define GREEN_DECORATOR_H_

#include "PackageColorDecorator.h"

class GreenDecorator : public PackageColorDecorator {
 public:
  GreenDecorator(Package*);
};

#endif  // GREEN_DECORATOR_H_
