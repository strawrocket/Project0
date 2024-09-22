#ifndef CS165_HASH_TABLE // This is a header guard. It prevents the header from
                         // being included more than once.
#define CS165_HASH_TABLE

typedef struct node {
  // define the components of the hash table here (e.g. the array, bookkeeping
  // for number of elements, etc)
  int key1, key2;
  int value1, value2;
  struct node *next;
} node;

typedef struct hashtable {
  node **table;
  int sz;
  int n_ele;

} hashtable;

typedef int keyType;
typedef int valType;

int allocate(hashtable **ht, int size);
int put(hashtable *ht, keyType key, valType value);
int get(hashtable *ht, keyType key, valType *values, int num_values,
        int *num_results);
int erase(hashtable *ht, keyType key);
int deallocate(hashtable *ht);

#endif
