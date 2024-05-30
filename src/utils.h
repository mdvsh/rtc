//
// Created by Madhav Shekhar Sharma on 5/30/24.
//

#ifndef RTC_SRC_UTILS_H_
#define RTC_SRC_UTILS_H_

#include "color.h"
#include "ray.h"

const point3 basic_unit_sphere_center = point3(0, 0, -1);

color black(const ray &r) {
  return {0, 0, 0};
}

color bl_wh_grad(const ray &r) {
  vec3 normed_dir = normalize(r.direction());
  double y_comp_scaled = (normed_dir.y() + 1.0) * .5;
  return (1.0 - y_comp_scaled) * color(1.0, 1.0, 1.0) + y_comp_scaled * color(0.5, 0.7, 1.0);
}

[[maybe_unused]] double is_in_collision_sphere(const point3 &C, double radius, const ray &ray) {
  // discriminant root check method for collision: if at bdry or inside sphere, positive roots
  //  vec3 C_ro = C - ray.origin();
  //  double a = dot(ray.direction(), ray.direction());
  //  double b = -2.0 * dot(ray.direction(), C_ro);
  //  double c = dot(C_ro, C_ro) - radius * radius;
  //  double d = b * b - 4 * a * c;

  // v2: simplified by taking b = -2b_
  vec3 C_ro = C - ray.origin();
  double a = ray.direction().norm_2();
  double b_ = dot(ray.direction(), C_ro);
  double c = C_ro.norm_2() - radius * radius;
  double d = b_ * b_ - a * c;

  // TODO: later, generalize for front-back view of camera
  if (d < 0) {
	return -1.0;
  } else {
	//	return (-b - sqrt(d)) / (2.0 * a);
	return (b_ - sqrt(d)) / a;
  }
}

color bl_wh_grad_red_sphere(const ray &r) {
  if (is_in_collision_sphere(basic_unit_sphere_center, 0.5, r) > 0.0) {
	return {1.0, 0.0, 0.0};
  }
  return bl_wh_grad(r);
}

color bl_wh_grad_sphere_SN_clrmapped(const ray &r) {
  if (double t = is_in_collision_sphere(basic_unit_sphere_center, 0.5, r); t > 0.0) {
	vec3 SN = normalize(r.at(t) - basic_unit_sphere_center);
	return 0.5 * color(SN.x() + 1, SN.y() + 1, SN.z() + 1);
  }
  return bl_wh_grad(r);
}

color base_world_coloring(const ray &r, const hittable_list &world) {
  hit_result res;
  if (world.hit(r, hit_interval(0, infty), res)) {
	return 0.5 * (res.normal + color(1, 1, 1));
  }
  return bl_wh_grad(r);
}

#endif//RTC_SRC_UTILS_H_
