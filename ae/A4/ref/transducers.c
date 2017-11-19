#include "transducers.h"
#include <unistd.h>
#include <stdlib.h>
#include <assert.h>

static int file_pipe(FILE* files[2]) {
  int fds[2];

  int r = pipe(fds);

  if (r == 0) {
    files[0] = fdopen(fds[0], "r");
    files[1] = fdopen(fds[1], "w");

    if (files[0] && files[1]) {
      return 0;
    } else {
      return 1;
    }
  } else {
    return r;
  }
}

struct stream {
  FILE *f;
  int linked;
};

void transducers_free_stream(stream *s) {
  fclose(s->f);
  free(s);
}

int transducers_link_source(stream **out,
                            transducers_source s, const void *arg) {
  pid_t pid;

  FILE *files[2];
  assert(file_pipe(files) == 0);
  FILE *file_out = files[0];
  FILE *file_in = files[1];

  if ((pid = fork()) == 0) {
    /* Child */
    fclose(file_out);
    s(arg, file_in);
    exit(0);
  } else {
    /* Parent */
    fclose(file_in);

    *out = malloc(sizeof(stream));
    (*out)->f = file_out;
    (*out)->linked = 0;
    return 0;
  }
}

int transducers_link_sink(transducers_sink s, void *arg,
                          stream *in) {
  if (in->linked) {
    return 1;
  }

  in->linked = 1;
  s(arg, in->f);

  return 0;
}

int transducers_link_1(stream **out,
                       transducers_1 t, const void *arg,
                       stream* in) {
  if (in->linked) {
    return 1;
  }

  in->linked = 1;

  pid_t pid;

  FILE *files[2];
  assert(file_pipe(files) == 0);
  FILE *file_out = files[0];
  FILE *file_in = files[1];

  if ((pid = fork()) == 0) {
    /* Child */
    t(arg, file_in, in->f);
    exit(0);
  } else {
    /* Parent */
    fclose(file_in);
    *out = malloc(sizeof(stream));
    (*out)->f = file_out;
    (*out)->linked = 0;
    return 0;
  }
}

int transducers_link_2(stream **out,
                       transducers_2 t, const void *arg,
                       stream* in1, stream* in2) {
  if (in1->linked || in2->linked) {
    return 1;
  }

  in1->linked = 1;
  in2->linked = 1;

  pid_t pid;

  FILE *files[2];
  assert(file_pipe(files) == 0);
  FILE *file_out = files[0];
  FILE *file_in = files[1];

  if ((pid = fork()) == 0) {
    /* Child */
    fclose(file_out);
    t(arg, file_in, in1->f, in2->f);
    exit(0);
  } else {
    /* Parent */
    fclose(file_in);
    *out = malloc(sizeof(stream));
    (*out)->f = file_out;
    (*out)->linked = 0;
    return 0;
  }
}

int transducers_dup(stream **out1, stream **out2,
                    stream *in) {
  if (in->linked) {
    return 1;
  }

  in->linked = 1;

  pid_t pid;

  FILE *files[2];
  assert(file_pipe(files) == 0);
  FILE *file_1_out = files[0];
  FILE *file_1_in = files[1];

  assert(file_pipe(files) == 0);
  FILE *file_2_out = files[0];
  FILE *file_2_in = files[1];

  if ((pid = fork()) == 0) {
    /* Child */

    fclose(file_1_out);
    fclose(file_2_out);

    unsigned char x;
    while (fread(&x, 1, 1, in->f) == 1) {
      fwrite(&x, 1, 1, file_1_in);
      fwrite(&x, 1, 1, file_2_in);
    }

    exit(0);
  } else {
    /* Parent */
    fclose(file_1_in);
    fclose(file_2_in);
    *out1 = malloc(sizeof(stream));
    *out2 = malloc(sizeof(stream));
    (*out1)->f = file_1_out;
    (*out1)->linked = 0;
    (*out2)->f = file_2_out;
    (*out2)->linked = 0;
    return 0;
  }

}
