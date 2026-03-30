#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef struct Node {
    int key;
    int value;
    struct Node* next;
} Node;

typedef struct {
    int size;
    Node** buckets;
}HashTable;

HashTable* createHashTable(int size) {
    HashTable* table = (HashTable*)malloc(sizeof(HashTable));
    table->size = size;
    table->buckets = (Node**)calloc(size, sizeof(Node*));
    return table;
}

void freeHashTable(HashTable* t){
    for (int i = 0; i < t->size; i++) {
        Node* curr = t->buckets[i];
        while(curr){
            Node* temp = curr;
            curr = curr->next;
            free(temp);
        }
    }
    free(t->buckets);
    free(t);
}




int hash(int key, int size){
    int h = key % size;
    return (h < 0) ? (h + size) : h;
}

void insert(HashTable* t, int key, int value){
    int h = hash(key, t->size);
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = key;
    newNode->value = value;
    newNode->next = t->buckets[h];
    t->buckets[h] = newNode;
}

Node* find(HashTable* t, int key){
    int h = hash(key, t->size);
    Node* curr = t->buckets[h];
    while (curr) {
        if(curr->key == key)
            return curr;
        curr = curr->next;
    }
    return NULL;

}

int* twoSum(int* nums, int numsSize, int Target, int* returnSize){
    HashTable* t = createHashTable(numsSize * 2);

    for(int i = 0; i < numsSize; i++){
        int complement = Target - nums[i];
        Node* targetNode = find(t, complement);

        if(targetNode != NULL) {
            int* result = (int*)malloc(2 * sizeof(int));
            result[0] = targetNode->value;
            result[1] = i;
            *returnSize = 2;
            return result;
        }

        insert(t, nums[i], i);
    }

    *returnSize = 0;

    freeHashTable(t);
    return NULL;
}