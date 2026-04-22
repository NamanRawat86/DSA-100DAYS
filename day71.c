#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define EMPTY -1

int hash(int key, int m) {
    return key % m;
}

void insert(int table[], int m, int key) {
    int idx = hash(key, m);
    int i = 0;
    while (i < m) {
        int newIdx = (idx + i * i) % m;
        if (table[newIdx] == EMPTY) {
            table[newIdx] = key;
            return;
        }
        i++;
    }
}

int search(int table[], int m, int key) {
    int idx = hash(key, m);
    int i = 0;
    while (i < m) {
        int newIdx = (idx + i * i) % m;
        if (table[newIdx] == EMPTY) return 0;
        if (table[newIdx] == key) return 1;
        i++;
    }
    return 0;
}

int main() {
    int m, q;
    scanf("%d", &m);
    scanf("%d", &q);

    int table[m];
    for (int i = 0; i < m; i++) table[i] = EMPTY;

    for (int i = 0; i < q; i++) {
        char op[10];
        int key;
        scanf("%s %d", op, &key);
        if (strcmp(op, "INSERT") == 0) {
            insert(table, m, key);
        } else if (strcmp(op, "SEARCH") == 0) {
            if (search(table, m, key)) printf("FOUND\n");
            else printf("NOT FOUND\n");
        }
    }

    return 0;
}
