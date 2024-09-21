#include <stdio.h>
#include <stdlib.h>

#include "hash_table.h"

// This is where you can implement your own tests for the hash table
// implementation.
int main(void) {

  hashtable *ht = NULL;
  int size = 10;
  allocate(&ht, size);
  printf("%d", allocate(&ht, size));
  int key = 99;
  int value = 569;

  put(ht, key, value);

  int num_values = 1;

  valType *values = malloc(1 * sizeof(valType));

  int num_results = 0;

  get(ht, key, values, num_values, &num_results);
  if ((num_results) > num_values) {
    values = realloc(values, (num_results) * sizeof(valType));
    get(ht, 0, values, num_values, &num_results);
  }

  for (int i = 0; i < (num_results); i++) {
    printf("value at %d, key = %d and value = %d \n", i, key, values[i]);
  }
  free(values);

  erase(ht, 0);

  deallocate(ht);
  return 0;
}
