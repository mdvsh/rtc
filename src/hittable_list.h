//
// Created by Madhav Shekhar Sharma on 5/30/24.
//

#ifndef RTC_SRC_HITTABLE_LIST_H_
#define RTC_SRC_HITTABLE_LIST_H_

#include "hittable.h"

#include <memory>
#include <vector>

class hittable_list : public hittable {
 public:
  std::vector<std::shared_ptr<hittable>> objects;

  hittable_list() = default;

  explicit hittable_list(const std::shared_ptr<hittable>& obj) { append(obj); }

  void append(const std::shared_ptr<hittable>(&obj)) { objects.push_back(obj); }

  void clear() { objects.clear(); }

  bool hit(const ray& r, hit_interval hit_int, hit_result& res) const override {
    hit_result temp_res;
    bool does_hit_something = false;
    double nearest_hit_at = hit_int.max;

    for (const auto& obj : objects) {
      if (obj->hit(r, hit_interval(hit_int.min, nearest_hit_at), temp_res)) {
        does_hit_something = true;
        nearest_hit_at = temp_res.t;
        res = temp_res;
      }
    }

    return does_hit_something;
  }
};

#endif  // RTC_SRC_HITTABLE_LIST_H_
