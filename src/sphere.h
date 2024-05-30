//
// Created by Madhav Shekhar Sharma on 5/30/24.
//

#ifndef RTC_SRC_SPHERE_H_
#define RTC_SRC_SPHERE_H_

#include "hittable.h"
#include "vec3.h"

class sphere : public hittable {
 private:
  point3 center;
  double radius;

 public:
  sphere(const point3 &C, double r) : center(C), radius(r) {}

  bool hit(const ray &r, hit_interval hit_int, hit_result &res) const override {
	vec3 C_ro = center - r.origin();
	double a = r.direction().norm_2();
	double b_ = dot(r.direction(), C_ro);
	double c = C_ro.norm_2() - radius * radius;
	double d = b_ * b_ - a * c;

	if (d < 0)
	  return false;

	double sqrt_d = sqrt(d);
	// check both roots
	double root = (b_ - sqrt_d) / a;
	if (!hit_int.surrounds(root)) {
	  root = (b_ + sqrt_d) / a;
	  if (!hit_int.surrounds(root)) {
		return false;
	  }
	}

	// collides
	res.point = r.at(root);
	vec3 out_normal = (res.point - center) / radius;
	res.t = root;
	res.set_normal(r, out_normal);

	return true;
  }
};

#endif//RTC_SRC_SPHERE_H_
