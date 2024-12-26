#include "utils.h"

#include "hit_interval.h"
#include "vec3.h"

static const point3 basic_unit_sphere_center(0, 0, -1);

color bl_wh_grad(const ray& r) {
  vec3 normed_dir = normalize(r.direction());
  double y_comp_scaled = (normed_dir.y() + 1.0) * .5;
  return (1.0 - y_comp_scaled) * color(1.0, 1.0, 1.0) + y_comp_scaled * color(0.5, 0.7, 1.0);
}

color bl_wh_grad_red_sphere(const ray& r) {
  if (is_in_collision_sphere(basic_unit_sphere_center, 0.5, r) > 0.0) {
    return {1.0, 0.0, 0.0};
  }
  return bl_wh_grad(r);
}

color bl_wh_grad_sphere_SN_clrmapped(const ray& r) {
  if (double t = is_in_collision_sphere(basic_unit_sphere_center, 0.5, r); t > 0.0) {
    vec3 SN = normalize(r.at(t) - basic_unit_sphere_center);
    return 0.5 * color(SN.x() + 1, SN.y() + 1, SN.z() + 1);
  }
  return bl_wh_grad(r);
}


