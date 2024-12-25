//
// Created by Madhav Shekhar Sharma on 5/30/24.
//

#ifndef RTC_SRC_UTILS_H_
#define RTC_SRC_UTILS_H_

#include "color.h"
#include "hittable_list.h"
#include "ray.h"

#include <random>

inline color black(const ray& r) {
  return {0, 0, 0};
}

inline double is_in_collision_sphere(const point3& C, double radius, const ray& ray) {
  vec3 C_ro = C - ray.origin();
  double a = ray.direction().norm_2();
  double b_ = dot(ray.direction(), C_ro);
  double c = C_ro.norm_2() - radius * radius;
  double d = b_ * b_ - a * c;

  if (d < 0)
    return -1.0;

  return (b_ - sqrt(d)) / a;
}

inline double random_double() {
  static std::uniform_real_distribution<double> distri(0.0, 1.0);
  static std::mt19937 generator;
  return distri(generator);
}

color bl_wh_grad(const ray& r);
color bl_wh_grad_red_sphere(const ray& r);
color bl_wh_grad_sphere_SN_clrmapped(const ray& r);
color base_world_coloring(const ray& r, const hittable_list& world);

#endif  // RTC_SRC_UTILS_H_
