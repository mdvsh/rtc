#include <iostream>
#include <sstream>

#include "color.h"
#include "vec3.h"

int main() {
  const int image_width = 256;
  const int image_height = 256;

  std::stringstream ss;
  ss << "P3\n"
	 << image_width << ' ' << image_height << "\n255\n";

  for (int j = 0; j < image_height; j++) {
	std::clog << "\rScanlines remaining: " << (image_height - j) << " " << std::flush;
	for (int i = 0; i < image_width; i++) {
	  double r = double(i) / (image_width - 1);
	  double g = double(j) / (image_height - 1);
	  double b = 0.0;

	  color pixel_color{r, g, b};
	  print_color(ss, pixel_color);
	}
  }

  std::clog << "\rDone.                 \n";
  std::cout << ss.str();
}