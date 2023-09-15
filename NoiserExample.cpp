#include <CE_main.h>
#include <iostream>

int main()
{
  ns::perlinNoise prln(12345);
  cy::vector2<float> myvector2;
  myvector2.x = 1.013;
  myvector2.y = myvector.x;
  std::cout << "the noise at your coordinates: (" << myvector.x << ", " << myvector.y << ") = " prln.noise(myvector.x, myvector.y) << std::endl;
  return 0;
}
