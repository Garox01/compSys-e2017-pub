
#include <stdio.h>

int main(int argc, char* argv[]) {
  char input[20];
  printf ("Give me a string\n");
  fgets(input, sizeof(input), stdin);
  printf ("You wrote: %s\n", input);
}
