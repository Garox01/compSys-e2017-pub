//
// Author:  Michael Kirkedal Thomsen
//
// Fibonacci function
//
// Made for CompSys17 C, lecture 2,3
//

#include <stdio.h>
#define SCANSUCCESS 1

int fib(int fib_num);
int fib_ref(int* fib_num);

int main() {
  int num;
  int result, result_ref;
  num = 2; // second Fibonacci number

  // Returns a pointer (address) to the value of num
  int* fibnump = &num;
  // We can set it directly
  *fibnump = 6;
  // Note this updates the value of num

  printf ("Give me a number:\n");
  int scanStatus = scanf("%d", fibnump);
  // We could even force it to be an unsigned integer.

  // Check if scan it OK
  if (scanStatus == SCANSUCCESS) {
    result = fib(num);
    result_ref = fib_ref(&num);

    printf ("Result is fib    : %d\n", result);
    printf ("Result is fib_ref: %d\n", result_ref);
  }
  else {
    printf("The provided value was not an integer\n");
  }
}

int fib(int fib_num) {
  if (fib_num == 1 || fib_num == 2) {
    return 1;
  }
  else {
    return fib(fib_num - 1) + fib(fib_num -2);
  }
}

int fib_ref(int* fib_num) {
  if (*fib_num == 1 || *fib_num == 2) {
    return 1;
  }
  else {
    int res;
    *fib_num -= 1;
    res = fib_ref(fib_num);
    *fib_num -= 1;
    res += fib_ref(fib_num);
    *fib_num += 2;
    return res;
  }
}
