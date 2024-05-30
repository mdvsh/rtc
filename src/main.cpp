#include <iostream>
#include <sstream>

#include "color.h"
#include "ray.h"
#include "utils.h"
#include "vec3.h"

int main() {
  // init Image
  const int image_width = 400;
  const double aspect_ratio = 16.0 / 9.0;

  // calc dims based on AR
  int image_height = int(image_width / aspect_ratio);
  image_height = (image_height < 1) ? 1 : image_height;

  // init Camera and Viewport
  const point3 camera_origin = point3(0.0, 0.0, 0.0);
  const double focal_length = 1.0;
  const double viewport_height = 2.0;
  const double viewport_width = viewport_height * (double(image_width) / image_height);// latter is 'real' AR

  vec3 viewport_x = vec3(viewport_width, 0, 0);
  vec3 viewport_y = vec3(0, -viewport_height, 0);
  vec3 pixel_del_x = viewport_x / image_width;
  vec3 pixel_del_y = viewport_y / image_height;

  vec3 viewport_top_left = camera_origin - vec3(0, 0, focal_length) - viewport_x / 2 - viewport_y / 2;
  vec3 top_left_pixel = viewport_top_left + 0.5 * (pixel_del_x + pixel_del_y);

  std::stringstream ss;
  ss << "P3\n"
	 << image_width << ' ' << image_height << "\n255\n";

  for (int j = 0; j < image_height; j++) {
	std::clog << "\rScanlines remaining: " << (image_height - j) << " " << std::flush;
	for (int i = 0; i < image_width; i++) {
	  //	  double r = double(i) / (image_width - 1);
	  //	  double g = double(j) / (image_height - 1);
	  //	  double b = 0.0;
	  vec3 pixel_center = top_left_pixel + (i * pixel_del_x) + (j * pixel_del_y);
	  vec3 ray_dir = pixel_center - camera_origin;
	  ray r(camera_origin, ray_dir);

	  //	  color pixel_color{r, g, b};
	  color pixel_color = bl_wh_grad_red_sphere_ray(r);
	  print_color(ss, pixel_color);
	}
  }

  std::clog << "\rDone.                 \n";
  std::cout << ss.str();
}