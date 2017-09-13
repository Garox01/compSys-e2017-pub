#include <stdio.h>
#include <stdlib.h>

int* update (int *arr, int size, int* max);

#define SIZE 10

int main() {
  int x[SIZE];

  // As I know that I write on too high addresses,
  // I make sure to put this pointer at the lower address-
  // That is done declaring it later... the stack grows down-wards.

  // I will use maxaddr to record the largest used address.
  int *maxaddr;
  maxaddr = x;

  // Initialize array
  for (int c = 0 ; c < SIZE ; c++) {
    x[c] = c * 2;
  }

  // Do some random updates to an array
  maxaddr = update((int*) &x, SIZE, maxaddr);

  // Print the elements
  for (int c = 0 ; c < SIZE ; c++) {
    printf("%d\n", x[c]);
  }

  return EXIT_SUCCESS;
  // Note had I called
  //  exit(EXIT_SUCCESS);
  // instead of return, I would not have gotten the segmentation fault.
  // The reason is that it would called another function, that would tell the OS
  // to end the program. Thus, I would never have gotten to the return address that
  // I had smashed.
  // However, this is _not_ good coding. A function, also main, should return normally.
  // exit(1) should be used only when a function have unforeseen behaviour.
}

// Update an array starting from arr with size elements
int* update (int *arr, int size, int *maxaddr) {
  for (int i = 0 ; i < size ; i++) {
    arr[i] += i;
    if (&arr[i] > maxaddr) {
      maxaddr = &arr[i];
    }
    // There is not real semantics for this update, so we can just guess that something that works.
    // If you were a tester, you would send it back to the developer (here stupid teacher) and let him fix it.
    maxaddr = update(arr+i, size-1, maxaddr);
  }
  return maxaddr;
}
