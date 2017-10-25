typedef struct list list;

// Create a new list.  Returns NULL on error.
list* list_create();

// Free the list.  Does not free the elements it contains.
void list_free(list*);

// The length of a list.
int list_length(list*);

// Insert a new first element into the list.  Returns 0 on success.
int list_insert_first(list*, void*);

// Insert a new last element into the list.  Returns 0 on success.
int list_insert_last(list*, void*);

// Remove and return first element of the list.
void* list_remove_first(list*);

// Return (but do not remove!) some element from the list.
void* list_peek_nth(list*, int);

// Remove and return some element from the list.
void* list_remove_nth(list*, int);

// First parameter is auxiliary value; second is list element.
typedef void (*map_fn)(void*, void*);

// Apply a function to every element of the list.
void list_map(list*, map_fn, void*);
