//
// Author:  Michael Kirkedal Thomsen
//
// Find last character of a file - Using GDB
//
// Made for CompSys, e2017
//

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int main(int argc, char *argv[]) {
  if (argc != 2) { // 1 argument
    printf("Usage %s filename\n", argv[0]);
    return EXIT_SUCCESS;
  }

  FILE* fp;
  fp = fopen(argv[1], "r");

  if (errno == 0) {
    printf("File: %s was found, status: %d\n", argv[1], errno);

    char last;
    while (!feof(fp)) {
      last = fgetc(fp);
    }
    printf("The _not_ last char was: %c\n", last);

    fclose(fp);
  }
  else {
    printf("Reading %s resulted in error %d\n", argv[1], errno);
  }

  return EXIT_SUCCESS;
}