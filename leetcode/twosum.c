#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 10000

typedef struct {
    int value;
    int index;
} HashTableItem;

int hash(int key) {
    return abs(key) % TABLE_SIZE;
}

void insert(HashTableItem* hashTable[], int value, int index) {
    int hashIndex = hash(value);
    while (hashTable[hashIndex] != NULL && hashTable[hashIndex]->value != value) {
        hashIndex = (hashIndex + 1) % TABLE_SIZE;
    }
    if (hashTable[hashIndex] == NULL) {
        hashTable[hashIndex] = (HashTableItem*)malloc(sizeof(HashTableItem));
    }
    hashTable[hashIndex]->value = value;
    hashTable[hashIndex]->index = index;
}

int search(HashTableItem* hashTable[], int value) {
    int hashIndex = hash(value);
    while (hashTable[hashIndex] != NULL) {
        if (hashTable[hashIndex]->value == value) {
            return hashTable[hashIndex]->index;
        }
        hashIndex = (hashIndex + 1) % TABLE_SIZE;
    }
    return -1;
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    HashTableItem* hashTable[TABLE_SIZE] = {NULL};
    int* result = (int*)malloc(2 * sizeof(int));
    
    for (int i = 0; i < numsSize; i++) {
        int complement = target - nums[i];
        int complementIndex = search(hashTable, complement);
        if (complementIndex != -1) {
            result[0] = complementIndex;
            result[1] = i;
            *returnSize = 2;
            return result;
        }
        insert(hashTable, nums[i], i);
    }
    
    *returnSize = 0;
    return NULL;
}

int main() {
    int nums[] = {2, 7, 11, 15};
    int target = 9;
    int returnSize;
    int* result = twoSum(nums, 4, target, &returnSize);
    
    if (returnSize == 2) {
        printf("Indices: [%d, %d]\n", result[0], result[1]);
    } else {
        printf("No solution found.\n");
    }
    
    free(result);
    return 0;
}
