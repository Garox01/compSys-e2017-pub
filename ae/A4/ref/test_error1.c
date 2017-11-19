#include "transducers.h"

#include <stdio.h>
#include <unistd.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

void dummy_source(const void *arg, FILE *out) {
  arg=arg; out=out;
}

void dummy_transducer_1(const void *arg, FILE *out, FILE *in) {
  arg=arg; out=out; in=in;
}

void dummy_transducer_2(const void *arg, FILE *out, FILE *in) {
  arg=arg; out=out; in=in;
}

void dummy_sink(void *arg, FILE *in) {
  arg=arg; in=in;
}

int main() {
  stream* s[3];

  assert(transducers_link_source(&s[0], dummy_source, NULL) == 0);
  assert(transducers_link_1(&s[1], dummy_transducer_1, NULL, s[0]) == 0);
  assert(transducers_link_1(&s[2], dummy_transducer_1, NULL, s[0]) != 0);
}
