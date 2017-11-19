#include "transducers.h"

#include <stdio.h>
#include <unistd.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

struct ints {
  int n; /* Number of integers. */
  int *d; /* The data. */
};

void ints_stream(const void *arg, FILE *out) {
  const struct ints *ints = arg;
  fwrite(ints->d, sizeof(int), ints->n, out);
}

void product_streams(const void *arg, FILE *out, FILE *in1, FILE *in2) {
  arg=arg; // Unused
  int x, y;
  while ((fread(&x, sizeof(int), 1, in1) == 1) &&
         (fread(&y, sizeof(int), 1, in2) == 1)) {
    int z = x * y;
    if (fwrite(&z, sizeof(int), 1, out) != 1) {
      break;
    }
  }
}

void save_stream(void *arg, FILE *in) {
  /* We will be writing bytes to this location. */
  unsigned char *d = arg;

  while (fread(d, sizeof(unsigned char), 1, in) == 1) {
    d++; /* Move location ahead by one byte. */
  }
}

int main() {
  stream* s[3];

  int x[] = { 0, 1, 2, 3, 4 };
  int num_x = sizeof(x)/sizeof(x[0]);
  struct ints ints_x = { num_x, x };

  int y[] = { 5, 6, 7, 8, 9 };
  int num_y = sizeof(y)/sizeof(y[0]);
  struct ints ints_y = { num_y, y };

  int z[] = { 0, 6, 14, 24, 36 };

  /* Always use calloc() for allocating arrays. */
  int *output = calloc(num_x, sizeof(int));

  assert(transducers_link_source(&s[0], ints_stream, &ints_x) == 0);
  assert(transducers_link_source(&s[1], ints_stream, &ints_y) == 0);
  assert(transducers_link_2(&s[2], product_streams, NULL, s[0], s[1]) == 0);
  assert(transducers_link_sink(save_stream, output, s[2]) == 0);

  assert(memcmp(z,output,num_x*sizeof(int)) == 0);

  /* Note the sizeof()-trick to determine the number of elements in
     the array.  This *only* works for statically allocated arrays,
     *not* ones created by malloc(). */
  for (int i = 0; i < (int)(sizeof(s)/sizeof(s[0])); i++) {
    transducers_free_stream(s[i]);
  }

  return 0;
}
