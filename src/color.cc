#include "color.h"

void print_color(std::ostream& out, const color& pixel_color) {
  print_color(out, pixel_color, 1);
}

inline double linear_to_gamma(double linear_comp) {
  return linear_comp > 0 ? sqrt(linear_comp) : 0;
}

void print_color(std::ostream& out, const color& pixel_color, int samples_per_pixel) {
  double r = pixel_color.x();
  double g = pixel_color.y();
  double b = pixel_color.z();

  // Divide the color by the number of samples
  double scale = 1.0 / samples_per_pixel;
  r *= scale;
  g *= scale;
  b *= scale;
  r = linear_to_gamma(r);
  g = linear_to_gamma(g);
  b = linear_to_gamma(b);
  static const hit_interval intensity(0.000, 0.999);
  int r_b = static_cast<int>(256 * intensity.clamp(r));
  int g_b = static_cast<int>(256 * intensity.clamp(g));
  int b_b = static_cast<int>(256 * intensity.clamp(b));

  out << r_b << ' ' << g_b << ' ' << b_b << '\n';
}
