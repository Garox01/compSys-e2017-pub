#include <stdio.h>
#include <stdlib.h>

#define HEIGHT 1000
#define WIDTH 10

int main() {
  // Define a multiplication table
  int table[HEIGHT][WIDTH];

  for (int h = 0 ; h < HEIGHT ; h++) {
    for (int w = 0 ; w < WIDTH ; w++) {
      table[w*h][h] = w*h;
    }
  }

  printf("Element (5,5)\n  expected value: 25\n  actual value:   %d\n", table[5][5]);
  return EXIT_SUCCESS;
}
