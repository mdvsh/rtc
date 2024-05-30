//
// Created by Madhav Shekhar Sharma on 5/30/24.
//

#ifndef RTC_SRC_UTILS_H_
#define RTC_SRC_UTILS_H_

#include "color.h"
#include "ray.h"

const point3 basic_unit_sphere_center = point3(0, 0, -1);

color black_ray(const ray &r) {
  return {0, 0, 0};
}

color bl_wh_grad_ray(const ray &r) {
  vec3 normed_dir = normalize(r.direction());
  double y_comp_scaled = (normed_dir.y() + 1.0) * .5;
  return (1.0 - y_comp_scaled) * color(1.0, 1.0, 1.0) + y_comp_scaled * color(0.5, 0.7, 1.0);
}

bool is_in_collision_sphere(const point3 &C, double radius, const ray &ray) {
  vec3 C_ro = C - ray.origin();
  // discriminant root check method for collision: if at bdry or inside sphere, positive roots
  double a = dot(ray.direction(), ray.direction());
  double b = -2.0 * dot(ray.direction(), C_ro);
  double c = dot(C_ro, C_ro) - radius * radius;
  double discriminant = b * b - 4 * a * c;
  return (discriminant >= 0);
}

color bl_wh_grad_red_sphere_ray(const ray &r) {
  if (is_in_collision_sphere(basic_unit_sphere_center, 0.5, r)) {
	return {1.0, 0.0, 0.0};
  }
  return bl_wh_grad_ray(r);
}

#endif//RTC_SRC_UTILS_H_
