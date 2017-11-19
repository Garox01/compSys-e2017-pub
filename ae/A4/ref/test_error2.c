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

void dummy_transducer_2(const void *arg, FILE *out, FILE *in1, FILE *in2) {
  arg=arg; out=out; in1=in1; in2=in2;
}

void dummy_sink(void *arg, FILE *in) {
  arg=arg; in=in;
}

int main() {
  stream* s[5];

  assert(transducers_link_source(&s[0], dummy_source, NULL) == 0);
  assert(transducers_dup(&s[1], &s[2], s[0]) == 0);
  assert(transducers_link_2(&s[3], dummy_transducer_2, NULL, s[1], s[2]) == 0);
  assert(transducers_link_2(&s[4], dummy_transducer_2, NULL, s[2], s[3]) != 0);
}
