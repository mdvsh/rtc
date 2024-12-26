#include "camera.h"
#include "hittable_list.h"
#include "sphere.h"

int main() {
  // World
  hittable_list world;
  world.append(std::make_shared<sphere>(point3(0, 0, -1), 0.5));       // Small sphere
  world.append(std::make_shared<sphere>(point3(0, -100.5, -1), 100));  // Ground sphere

  // Camera
  camera cam;
  cam.aspect_ratio = 16.0 / 9.0;
  cam.image_width = 400;
  cam.samples_per_pixel = 100;
  cam.max_depth = 75;

  // Render
  cam.render(world);
}
