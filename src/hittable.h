//
// Created by Madhav Shekhar Sharma on 5/30/24.
//

#ifndef RTC_SRC_HITTABLE_H_
#define RTC_SRC_HITTABLE_H_

#include "hit_interval.h"
#include "ray.h"

struct hit_result {
  point3 point;
  vec3 normal;
  double t{};
  bool is_front_facing{};

  void set_normal(const ray &r, const vec3 &out_normal) {
	is_front_facing = dot(r.direction(), out_normal) < 0;
	normal = is_front_facing ? out_normal : -out_normal;
  }
};

class hittable {
 public:
  virtual ~hittable() = default;
  virtual bool hit(const ray &r, hit_interval hit_int, hit_result &res) const = 0;
};

#endif//RTC_SRC_HITTABLE_H_
