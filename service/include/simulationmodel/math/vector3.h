#ifndef VECTOR3_H_
#define VECTOR3_H_

#include <cmath>
#include <iostream>
#include <vector>

// a simple class used for vector math, most function are self explanatory
class Vector3 {
 public:
  double x = 0;
  double y = 0;
  double z = 0;
  /**
   * @brief Default constructor.
   */
  Vector3();
  Vector3(double a);
  /**
   * @brief Parameter constructor.
   *
   * @param[in] a x-coordinate
   * @param[in] b y-coordinate
   * @param[in] c z-coordinate
   */
  Vector3(double a, double b, double c);
  Vector3(const std::vector<double>& v);
  Vector3(const std::vector<float>& v);
  bool operator==(const Vector3& v) const;
  double& operator[](int i);
  double operator[](int i) const;
  /**
   * @brief Overrides + operator.
   * @param[in] v The Vector3 object you would like to add to this Vector3
   * object
   * @return The Vector3 Object comprised of the sum of the two objects
   */
  Vector3 operator+(const Vector3& v) const;
  /**
   * @brief Overrides - operator.
   * @param[in] v The Vector3 object you would like to subtract to this Vector3
   * object
   * @return The Vector3 Object comprised of the subtraction of the two objects
   */
  Vector3 operator-(const Vector3& v) const;
  /**
   * @brief Overrides * operator.
   * @param[in] v The Vector3 object you would like to multiply to this Vector3
   * object
   * @return The Vector3 Object comprised of the multiplication of the two
   * objects
   */
  Vector3 operator*(double s) const;
  /**
   * @brief Overrides / operator.
   * @param[in] v The Vector3 object you would like to divide to this Vector3
   * object
   * @return The Vector3 Object comprised of the division of the two objects
   */
  Vector3 operator/(double s) const;
  double operator*(const Vector3& v) const;  // dot product
  // return std::vector version of this Vector3
  // template function should be defined in same file
  // with template keyword
  template<class T> std::vector<T> vec() const {
    return {
      static_cast<T>(x),
      static_cast<T>(y),
      static_cast<T>(z)
    };
  }
  Vector3 cross(const Vector3& v) const;
  double magnitude() const;
  Vector3& normalize();
  Vector3 unit() const;  // normal vector in same direction
  double dist(const Vector3& v) const;
  friend std::ostream& operator<<(std::ostream& strm, const Vector3& v);
};

#endif
