#include "transducers.h"

#include <stdio.h>
#include <unistd.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

void dummy_source(const void *arg, FILE *out) {
  arg=arg; out=out;
}

void dummy_sink(void *arg, FILE *in) {
  arg=arg; in=in;
}

int main() {
  stream* s[1];

  assert(transducers_link_source(&s[0], dummy_source, NULL) == 0);
  assert(transducers_link_sink(dummy_sink, NULL, s[0]) == 0);
  assert(transducers_link_sink(dummy_sink, NULL, s[0]) != 0);
}
