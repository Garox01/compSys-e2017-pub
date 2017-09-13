#include <stdio.h>
#include <stdlib.h>

#define HEIGHT 1000
#define WIDTH 10

int main() {
  // Define a multiplication table
  int table[HEIGHT][WIDTH];

  for (int h = 0 ; h < HEIGHT ; h++) {
    for (int w = 0 ; w < WIDTH ; w++) {
      // Index is out of bounds
      // table[w*h][h] = w*h;
      // Update to
      // table[w][h] = w*h; // Still wrong
      // There is still a bug -- though no segmentation fault
      table[h][w] = w*h; // Correct
    }
  }

  printf("Element (5,5)\n  expected value: 25\n  actual value:   %d\n", table[5][5]);
  return EXIT_SUCCESS;
}
