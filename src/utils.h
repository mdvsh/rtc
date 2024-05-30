//
// Created by Madhav Shekhar Sharma on 5/30/24.
//

#ifndef RTC_SRC_UTILS_H_
#define RTC_SRC_UTILS_H_

#include "color.h"
#include "ray.h"

color black_ray(const ray &r) {
  return {0, 0, 0};
}

color bl_wh_grad_ray(const ray &r) {
   vec3 normed_dir = normalize(r.direction());
   double y_comp_scaled = (normed_dir.y() + 1.0) * .5;
   return (1.0 - y_comp_scaled) * color(1.0, 1.0, 1.0) + y_comp_scaled * color(0.5, 0.7, 1.0);
}

#endif//RTC_SRC_UTILS_H_
