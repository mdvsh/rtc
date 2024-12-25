//
// Created by Madhav Shekhar Sharma on 6/9/24.
//
#ifndef RTC_SRC_CAMERA_H_
#define RTC_SRC_CAMERA_H_

#include "color.h"
#include "hittable.h"
#include "utils.h"

#include <iostream>

class camera {
 public:
  double aspect_ratio = 1.0;
  int image_width = 100;
  int samples_per_pixel = 10;

  void render(const hittable& world) {
    initialize();

    std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";

    for (int j = 0; j < image_height; j++) {
      std::clog << "\rScanlines remaining: " << (image_height - j) << ' ' << std::flush;
      for (int i = 0; i < image_width; i++) {
        color pixel_color(0, 0, 0);
        for (int sample = 0; sample < samples_per_pixel; sample++) {
          ray r = get_ray(i, j);
          pixel_color += base_world_coloring(r, static_cast<const hittable_list&>(world));
        }
        print_color(std::cout, pixel_color, samples_per_pixel);
      }
    }

    std::clog << "\rDone.                 \n";
  }

 private:
  int image_height;
  point3 camera_origin;
  point3 top_left_pixel;
  vec3 pixel_del_x;
  vec3 pixel_del_y;

  void initialize() {
    image_height = int(image_width / aspect_ratio);
    image_height = (image_height < 1) ? 1 : image_height;

    camera_origin = point3(0.0, 0.0, 0.0);

    // Calculate the viewport dimensions
    double focal_length = 1.0;
    double viewport_height = 2.0;
    double viewport_width = viewport_height * (double(image_width) / image_height);

    // Calculate the vectors across the viewport edges
    vec3 viewport_x = vec3(viewport_width, 0, 0);
    vec3 viewport_y = vec3(0, -viewport_height, 0);

    // Calculate the pixel delta vectors
    pixel_del_x = viewport_x / image_width;
    pixel_del_y = viewport_y / image_height;

    // Calculate the location of the upper left pixel
    vec3 viewport_top_left =
      camera_origin - vec3(0, 0, focal_length) - viewport_x / 2 - viewport_y / 2;
    top_left_pixel = viewport_top_left + 0.5 * (pixel_del_x + pixel_del_y);
  }

  ray get_ray(int i, int j) const {
    // Get a randomly sampled camera ray for the pixel at location i,j
    vec3 pixel_center = top_left_pixel + (i * pixel_del_x) + (j * pixel_del_y);
    vec3 pixel_sample = pixel_center + pixel_random_offset();

    vec3 ray_direction = pixel_sample - camera_origin;
    return ray(camera_origin, ray_direction);
  }

  vec3 pixel_random_offset() const {
    // Returns random point in pixel's square area
    double px = -0.5 + random_double();
    double py = -0.5 + random_double();
    return (px * pixel_del_x) + (py * pixel_del_y);
  }
};

#endif  // RTC_SRC_CAMERA_H_
