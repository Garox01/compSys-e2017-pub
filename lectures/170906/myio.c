//
// Author:  Michael Kirkedal Thomsen
//
// My library of IO functions
//
// Made for CompSys17 C, lecture 2
//

#include <stdio.h>

#define SUCCESS 1

int flush_stdin() {
  while (fgetc(stdin) != 10) {

  }
  return SUCCESS;
}
