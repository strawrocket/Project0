#include "hash_table.h"
#include <stdio.h>
#include <stdlib.h>

// Initialize the components of a hashtable.
// The size parameter is the expected number of elements to be inserted.
// This method returns an error code, 0 for success and -1 otherwise (e.g., if
// the parameter passed to the method is not null, if malloc fails, etc).
int allocate(hashtable **ht, int size) {
  // The next line tells the compiler that we know we haven't used the variable
  // yet so don't issue a warning. You should remove this line once you use
  // the parameter.
  if (!ht) {
    return -1;
  }

  hashtable *new_table = calloc(1, sizeof(hashtable));

  if (new_table == NULL) {
    return -1;
  }
  // printf("%lu", sizeof(*new_table));
  new_table->sz = size;

  new_table->table = calloc(size, sizeof(node *));

  if (!new_table->table) {
    return -1;
  }

  *ht = new_table;

  return 0;
}

// This method inserts a key-value pair into the hash table.
// It returns an error code, 0 for success and -1 otherwise (e.g., if malloc is
// called and fails).
int put(hashtable *ht, keyType key, valType value) {

  if (!ht || !ht->table)
    return -1;

  node *new_node;
  new_node = calloc(1, sizeof(node));
  if (!new_node)
    return -1;

  int idx = key % ht->sz;

  new_node->key = key;
  new_node->value = value;
  new_node->next = NULL;

  if (!ht->table[idx]) {
    ht->table[idx] = new_node;
  } else {
    node *ptr = ht->table[idx];
    while (ptr && ptr->next) {
      ptr = ptr->next;
    }
    ptr->next = new_node;
  }

  ht->n_ele++;

  return 0;
}

// This method retrieves entries with a matching key and stores the
// corresponding values in the values array. The size of the values array is
// given by the parameter num_values. If there are more matching entries than
// num_values, they are not stored in the values array to avoid a buffer
// overflow. The function returns the number of matching entries using the
// num_results pointer. If the value of num_results is greater than num_values,
// the caller can invoke this function again (with a larger buffer) to get
// values that it missed during the first call. This method returns an error
// code, 0 for success and -1 otherwise (e.g., if the hashtable is not
// allocated).
int get(hashtable *ht, keyType key, valType *values, int num_values,
        int *num_results) {

  if (!ht || !ht->table)
    return -1;

  int idx = key % ht->sz;

  node *ptr = ht->table[idx];
  int cnt = 0;
  while (ptr) {
    if (cnt >= num_values)
      break;

    if (ptr->key == key)
      values[cnt++] = ptr->value;

    ptr = ptr->next;
  }
  if (num_results) {
    *num_results = cnt;
  }

  return 0;
}

// This method erases all key-value pairs with a given key from the hash table.
// It returns an error code, 0 for success and -1 otherwise (e.g., if the
// hashtable is not allocated).
int erase(hashtable *ht, keyType key) {
  (void)ht;
  (void)key;
  return 0;
}

// This method frees all memory occupied by the hash table.
// It returns an error code, 0 for success and -1 otherwise.
int deallocate(hashtable *ht) {
  // This line tells the compiler that we know we haven't used the variable
  // yet so don't issue a warning. You should remove this line once you use
  // the parameter.
  (void)ht;
  return 0;
}
