#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  if (argc != 2) {
    fprintf(stderr, "Usage: %s argument\n", argv[0]);
    return EXIT_FAILURE;
  }
  // Problem. Here we are writing to a part of memory that is read-only.
  // GDB script in hello.gdb. Run
  // > gdb -x hello.gdb hello
  // Solution:
  // Create the string locally

  // char *hello = "hello";
  char hello[] = "hello";

  *hello = 'H';

  fprintf(stdout, "%s, %s!\n", hello, argv[1]);

  return EXIT_SUCCESS;
}
