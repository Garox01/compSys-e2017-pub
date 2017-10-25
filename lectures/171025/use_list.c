#include "list.h"
#include <stdio.h>

void print_int_list(list *l) {
  int n = list_length(l);
  for (int i = 0; i < n; i++) {
    int *x = list_peek_nth(l, i);
    printf("%d ", *x);
  }
  printf("\n");
}

void inc(void *arg, void *elem) {
  int *elem_int = elem;
  int *arg_int = arg;

  *elem_int += *arg_int;
}

int main() {
  list* l = list_create();
  int ints[10];

  for (int i = 0; i < 10; i++) {
    ints[i] = i;
  }

  list_insert_first(l, &ints[0]);
  list_insert_first(l, &ints[1]);
  list_insert_first(l, &ints[2]);

  print_int_list(l);

  list_map(l, inc, &ints[9]);

  print_int_list(l);
}
