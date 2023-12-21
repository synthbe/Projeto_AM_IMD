#include <iostream>
#include <cstdlib>

int main(void) {
  srand((unsigned) time(NULL));
  for (int i = 0; i < 10; ++i) {
    std::cout << (double)rand()/RAND_MAX << std::endl;
  }
  return 0;
}
