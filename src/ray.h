//
// Created by Madhav Shekhar Sharma on 5/29/24.
//

#ifndef RTC_SRC_RAY_H_
#define RTC_SRC_RAY_H_

#include "vec3.h"

class ray {
 public:
  ray() = default;

  ray(const point3 &origin, const vec3 &direction) : m_origin(origin), m_dir(direction) {}

  [[nodiscard]] const point3 &origin() const { return m_origin; }
  [[nodiscard]] const vec3 &direction() const { return m_dir; }

  [[nodiscard]] point3 at(double t) const {
	return (m_origin + m_dir * t);
  }

 private:
  vec3 m_origin;
  vec3 m_dir;
};

#endif//RTC_SRC_RAY_H_
