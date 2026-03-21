#include <stdio.h>
#include <string.h>

#define MAX 100

int heap[MAX];
int size = 0;

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapifyUp(int i) {
    while (i > 0 && heap[(i - 1) / 2] > heap[i]) {
        swap(&heap[i], &heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

void heapifyDown(int i) {
    int left, right, smallest;
    while (1) {
        left = 2 * i + 1;
        right = 2 * i + 2;
        smallest = i;

        if (left < size && heap[left] < heap[smallest]) smallest = left;
        if (right < size && heap[right] < heap[smallest]) smallest = right;

        if (smallest != i) {
            swap(&heap[i], &heap[smallest]);
            i = smallest;
        } else break;
    }
}

void insert(int x) {
    if (size == MAX) return;
    heap[size] = x;
    heapifyUp(size);
    size++;
}

int extractMin() {
    if (size == 0) return -1;
    int root = heap[0];
    heap[0] = heap[size - 1];
    size--;
    heapifyDown(0);
    return root;
}

int peek() {
    if (size == 0) return -1;
    return heap[0];
}

int main() {
    int N;
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        char op[20];
        scanf("%s", op);
        if (strcmp(op, "insert") == 0) {
            int x;
            scanf("%d", &x);
            insert(x);
        } else if (strcmp(op, "extractMin") == 0) {
            printf("%d\n", extractMin());
        } else if (strcmp(op, "peek") == 0) {
            printf("%d\n", peek());
        }
    }

    return 0;
}
