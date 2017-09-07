//
// Author:  Michael Kirkedal Thomsen
//
// Made for CompSys17 C, lecture 2
//

#include <stdio.h>
#include "myio.h"

int main() {
  char input[4];

  printf ("Give me a string:\n");
  fgets(input, sizeof(input), stdin);
  printf ("You wrote: %s\n", input);

  flush_stdin();

  printf ("Give me a string:\n");
  fgets(input, sizeof(input), stdin);
  printf ("You wrote: %s\n", input);

  // What if we read more
}
