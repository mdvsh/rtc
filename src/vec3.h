//
// Created by Madhav Shekhar Sharma on 5/29/24.
//

#ifndef RTC_SRC_VEC3_H_
#define RTC_SRC_VEC3_H_

#include "iostream"
#include <cmath>

class vec3 {
 public:
  double d[3];

  vec3() : d{0, 0, 0} {}
  vec3(double d1, double d2, double d3) : d{d1, d2, d3} {}

  [[nodiscard]] double x() const { return d[0]; }
  [[nodiscard]] double y() const { return d[1]; }
  [[nodiscard]] double z() const { return d[2]; }

  // operator overloads
  vec3 operator-() const { return {-d[0], -d[1], -d[2]}; }
  double operator[](int idx) const { return d[idx]; }
  double &operator[](int idx) { return d[idx]; }

  vec3 &operator+=(const vec3 &v) {
	d[0] += v.d[0];
	d[1] += v.d[1];
	d[2] += v.d[2];
	return *this;
  }

  vec3 &operator*=(double scale) {
	d[0] *= scale;
	d[1] *= scale;
	d[2] *= scale;
	return *this;
  }

  vec3 &operator/=(double scale) {
	assert(scale != 0);
	return *this *= (1 / scale);
  }

  [[nodiscard]] double norm() const {
	// TODO: replace with Carmack's inverse (approx) sqrt and BENCHMARK.
	return sqrt(norm_2());
  }

  [[nodiscard]] double norm_2() const {
	return (d[0] * d[0] + d[1] * d[1] + d[2] * d[2]);
  }
};

// add alias for future usage clarity.
using point3 = vec3;

inline std::ostream &operator<<(std::ostream &out, const vec3 &v) {
  return out << v.d[0] << ' ' << v.d[1] << ' ' << v.d[2];
}

inline vec3 operator+(const vec3 &u, const vec3 &v) {
  return {u.d[0] + v.d[0], u.d[1] + v.d[1], u.d[2] + v.d[2]};
}

inline vec3 operator-(const vec3 &u, const vec3 &v) {
  return {u.d[0] - v.d[0], u.d[1] - v.d[1], u.d[2] - v.d[2]};
}

inline vec3 operator*(const vec3 &u, const vec3 &v) {
  return {u.d[0] * v.d[0], u.d[1] * v.d[1], u.d[2] * v.d[2]};
}

inline vec3 operator*(double scale, const vec3 &v) {
  return {scale * v.d[0], scale * v.d[1], scale * v.d[2]};
}

inline vec3 operator*(const vec3 &v, double scale) {
  return scale * v;
}

inline vec3 operator/(const vec3 &v, double scale) {
  assert(scale != 0);
  return (1 / scale) * v;
}

inline vec3 operator/(double scale, const vec3 &v) {
  return v / scale;
}

inline vec3 normalize(const vec3 &v) {
  return v / v.norm();
}

inline double dot(const vec3 &v_1, const vec3 &v_2) {
  return (v_1.d[0] * v_2.d[0] + v_1.d[1] * v_2.d[1] + v_1.d[2] * v_2.d[2]);
}

inline vec3 cross(const vec3 &v_1, const vec3 &v_2) {
  return {v_1.d[1] * v_2.d[2] - v_1.d[2] * v_2.d[1],
		  v_1.d[2] * v_2.d[0] - v_1.d[0] * v_2.d[2],
		  v_1.d[0] * v_2.d[1] - v_1.d[1] * v_2.d[0]};
}

#endif//RTC_SRC_VEC3_H_