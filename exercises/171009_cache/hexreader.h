#include <stdlib.h>
#include <stdio.h>

#define STREAMMAX 256

/** 
 * 
 **/
typedef struct hexstream {
  int length;             // Number of elements
  unsigned long stream[STREAMMAX]; // Pointer to the array containing the ordered type mapping
} hexstream;

/**
 * 
 **/
hexstream readstream(char* filename);


