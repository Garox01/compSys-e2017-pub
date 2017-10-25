#include "list.h"
#include <stdlib.h>
#include <assert.h>

struct node {
  void *elem;
  struct node *next;
};

struct list {
  struct node *head;
};

list* list_create() {
  list* l = malloc(sizeof(list));
  if (l) {
    l->head = NULL;
  }
  return l;
}

void list_free(list* l) {
  struct node *cur = l->head;
  while (cur) {
    struct node* next = cur->next;
    free(cur);
    cur = next;
  }
}

int list_length(list* l) {
  struct node *cur = l->head;
  int n = 0;
  while (cur) {
    cur = cur->next;
    n++;
  }
  return n;
}

int list_insert_first(list* l, void* x) {
  struct node *new_head = malloc(sizeof(struct node));
  if (new_head) {
    new_head->elem = x;
    new_head->next = l->head;
    l->head = new_head;
    return 0;
  } else {
    return 1;
  }
}

int list_insert_last(list* l, void* x) {
  if (l->head == NULL) {
    return list_insert_first(l, x);
  } else {
    struct node *prev = l->head;
    struct node *cur = prev->next;

    while (cur) {
      prev = cur;
      cur = cur->next;
    }

    struct node *new_node = malloc(sizeof(struct node));
    if (new_node) {
      new_node->elem = x;
      new_node->next = NULL;
      prev->next = new_node;
      return 0;
    } else {
      return 1;
    }
  }
}

void* list_remove_first(list* l) {
  assert(l->head != NULL);

  struct node *old_head = l->head;
  void *x = old_head->elem;
  l->head = old_head->next;
  free(old_head);
  return x;
}

void* list_peek_nth(list* l, int i) {
  struct node *cur = l->head;
  int j = i;

  while (j > 0) {
    assert(cur != NULL);
    cur = cur->next;
    j--;
  }
  return cur->elem;
}

void* list_remove_nth(list* l, int i) {
  if (i == 0) {
    return list_remove_first(l);
  } else {
    assert(l->head != NULL);
    assert(l->head->next != NULL);
    struct node *prev = l->head;
    struct node *cur = l->head->next;
    int j = i-1;

    while (j > 0) {
      assert(cur->next != NULL);
      prev = cur;
      cur = cur->next;
      j--;
    }

    prev->next = cur->next;
    void *x = cur->elem;
    free(cur);
    return x;
  }
}

// Apply a function to every element of the list.
void list_map(list* l, map_fn f, void* arg) {
  struct node *cur = l->head;

  while (cur) {
    f(arg, cur->elem);
    cur = cur->next;
  }
}
