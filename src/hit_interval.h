//
// Created by Madhav Shekhar Sharma on 5/30/24.
//

#ifndef RTC_SRC_HIT_INTERVAL_H_
#define RTC_SRC_HIT_INTERVAL_H_

#include <limits>

constexpr double infty = std::numeric_limits<double>::infinity();

class hit_interval {
 public:
  double max, min;

  hit_interval() : min(-infty), max(infty) {}

  hit_interval(double m_min, double m_max) : min(m_min), max(m_max) {}

  [[nodiscard]] double size() const { return (max - min); }

  [[nodiscard]] bool contains(double x) const { return min <= x && x <= max; }

  [[nodiscard]] bool surrounds(double x) const { return min < x && x < max; }

  [[nodiscard]] double clamp(double x) const {
    if (x < min)
      return min;
    if (x > max)
      return max;
    return x;
  }

  static const hit_interval universe;
  static const hit_interval empty;
};

#endif  // RTC_SRC_HIT_INTERVAL_H_
