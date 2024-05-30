//
// Created by Madhav Shekhar Sharma on 5/30/24.
//

#ifndef RTC_SRC_HIT_INTERVAL_H_
#define RTC_SRC_HIT_INTERVAL_H_

#include <limits>

constexpr double infty = std::numeric_limits<double>::max();

class hit_interval {
 public:
  double max, min;

  hit_interval() : min(-infty), max(infty) {}
  hit_interval(double m_min, double m_max) : min(m_min), max(m_max) {}

  [[nodiscard]] double size() const { return (max - min); }
  [[nodiscard]] bool contains(double x) const { return min <= x && x <= max; }
  [[nodiscard]] bool surrounds(double x) const { return min < x && x < max; }

  static const hit_interval universe, empty;
};

const hit_interval hit_interval::universe = hit_interval(-infty, infty);
const hit_interval hit_interval::empty = hit_interval(infty, -infty);

#endif//RTC_SRC_HIT_INTERVAL_H_
