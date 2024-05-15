#ifndef PACKAGE_COLOR_DECORATOR_H_
#define PACKAGE_COLOR_DECORATOR_H_

#include "PackageDecorator.h"

class PackageColorDecorator : public PackageDecorator {
 private:
  double hue = 0;
  double saturation = 0;
  double light = 0;

 public:
  PackageColorDecorator(Package*, double = 0, double = 0, double = 0);
  std::string getColor() const;
};

#endif  // PACKAGE_COLOR_DECORATOR_H_
