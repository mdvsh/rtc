//
// Created by Madhav Shekhar Sharma on 5/29/24.
//

#ifndef RTC_SRC_COLOR_H_
#define RTC_SRC_COLOR_H_

#include "vec3.h"

using color = vec3;

void print_color(std::ostream &out, const color &pixel_color) {
  double r = pixel_color.x();
  double g = pixel_color.y();
  double b = pixel_color.z();

  // Translate the [0,1] comp values within the byte range [0,255]
  int r_b = int(255.999 * r);
  int g_b = int(255.999 * g);
  int b_b = int(255.999 * b);

  out << r_b << ' ' << g_b << ' ' << b_b << '\n';
}

#endif
//RTC_SRC_COLOR_H_
