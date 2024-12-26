//
// Created by Madhav Shekhar Sharma on 12/26/24.
//

#ifndef RTC_SRC_MATH_UTILS_H_
#define RTC_SRC_MATH_UTILS_H_

#include <random>
#include <limits>

constexpr double pi = 3.1415926535897932385;

inline double random_double() {
  static std::uniform_real_distribution<double> distri(0.0, 1.0);
  static std::mt19937 generator;
  return distri(generator);
}

inline double random_double(double min, double max) {
  return min + (max - min) * random_double();
}

inline double degrees_to_radians(double degrees) {
  return degrees * pi / 180.0;
}

#endif  // RTC_SRC_MATH_UTILS_H_