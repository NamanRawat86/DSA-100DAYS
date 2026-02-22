#include <stdio.h>
#include <stdlib.h>

struct Node {
    int prefixSum;
    int count;
    struct Node* next;
};

int hash(int key, int size) {
    if (key < 0) key = -key;
    return key % size;
}

void insert(struct Node** hashTable, int size, int prefixSum) {
    int idx = hash(prefixSum, size);
    struct Node* temp = hashTable[idx];
    while (temp) {
        if (temp->prefixSum == prefixSum) {
            temp->count++;
            return;
        }
        temp = temp->next;
    }
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->prefixSum = prefixSum;
    newNode->count = 1;
    newNode->next = hashTable[idx];
    hashTable[idx] = newNode;
}

int getCount(struct Node** hashTable, int size, int prefixSum) {
    int idx = hash(prefixSum, size);
    struct Node* temp = hashTable[idx];
    while (temp) {
        if (temp->prefixSum == prefixSum) return temp->count;
        temp = temp->next;
    }
    return 0;
}

int main() {
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    int hashSize = 10007;
    struct Node* hashTable[hashSize];
    for (int i = 0; i < hashSize; i++) hashTable[i] = NULL;

    int prefixSum = 0, countZeroSubarrays = 0;

    for (int i = 0; i < n; i++) {
        prefixSum += arr[i];
        if (prefixSum == 0) countZeroSubarrays++;
        countZeroSubarrays += getCount(hashTable, hashSize, prefixSum);
        insert(hashTable, hashSize, prefixSum);
    }

    printf("%d\n", countZeroSubarrays);
    return 0;
}
