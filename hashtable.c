#include <stdlib.h>
#include <stdio.h>

typedef int value_type;
struct BucketNode {
    value_type v;
    struct BucketNode * next;
};  
typedef struct BucketNode BucketNode;
typedef struct BucketNode * HashTable;
#define TABLE_SIZE 1024   

HashTable table[TABLE_SIZE];
int hash(value_type v);
int find(value_type v);
int rm(value_type v);
void main();

int hash(value_type v) {
    return ((int)v * 113) % v;
}

void insert(value_type v) {
    int index = hash(v);
    BucketNode * node;
    if (table[index] == 0) {
       node = malloc(sizeof(BucketNode));
       node->v = v;
       node->next = NULL;
       table[index] = node;
       return;
    }
    else {
        node = malloc(sizeof(BucketNode));
        node->v = v;
        node->next = table[index];
        table[index] = node;
        return;
    }
}

int find(value_type v) {
    int index = hash(v);
    int count = 0; // whether v is in the hashtable
    BucketNode * node = table[index]; 
    while ( node != NULL ) {
        if ( node->v == v )
            count++;
        node = node->next;
    }
    return count;
}

int rm(value_type v) {
   BucketNode * node = table[hash(v)];
   BucketNode * pre = NULL;
   while ( node != NULL ) {
       if ( node->v == v ) {
          if ( pre == NULL ) {
              table[hash(v)] = node->next;
              free(node);
              return 0;
          }
          pre->next = node->next;
          free(node);
          return 0;
       }
       pre = node;
       node = node->next;
   }
   return -1;
}
        
void sayError(int flag) {
    static int test_count = 0;
    test_count++;
    if (flag)
        fprintf(stderr, "ERROR CASE: %d \n", test_count); 
}
void main() {
    int test_count = 0;
    value_type v = 2;
    insert(v);
    sayError(find(v) != 1);

    insert(v);
    test_count++;
    sayError(find(v) != 2);

    test_count++;
    sayError(rm(v) != 0);
    
    test_count++;
    sayError(rm(v) != 0);

    test_count++;
    sayError(rm(v) != -1);

    printf("End of Test. \n");
}

