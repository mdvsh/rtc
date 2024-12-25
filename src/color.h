//
// Created by Madhav Shekhar Sharma on 5/29/24.
//

#ifndef RTC_SRC_COLOR_H_
#define RTC_SRC_COLOR_H_

#include "vec3.h"

#include <hit_interval.h>
#include <iostream>

using color = vec3;

void print_color(std::ostream& out, const color& pixel_color);
void print_color(std::ostream& out, const color& pixel_color, int samples_per_pixel);

#endif
// RTC_SRC_COLOR_H_
