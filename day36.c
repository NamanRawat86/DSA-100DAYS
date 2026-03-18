#include <stdio.h>
#include <stdlib.h>

struct CircularQueue {
    int *arr;
    int front, rear, size, capacity;
};

void initQueue(struct CircularQueue *q, int capacity) {
    q->capacity = capacity;
    q->arr = (int*)malloc(capacity * sizeof(int));
    q->front = q->rear = -1;
    q->size = 0;
}

int isFull(struct CircularQueue *q) {
    return q->size == q->capacity;
}

int isEmpty(struct CircularQueue *q) {
    return q->size == 0;
}

void enqueue(struct CircularQueue *q, int val) {
    if (isFull(q)) return;
    if (q->front == -1) q->front = 0;
    q->rear = (q->rear + 1) % q->capacity;
    q->arr[q->rear] = val;
    q->size++;
}

void dequeue(struct CircularQueue *q) {
    if (isEmpty(q)) return;
    q->front = (q->front + 1) % q->capacity;
    q->size--;
    if (q->size == 0) {
        q->front = q->rear = -1;
    }
}

void display(struct CircularQueue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return;
    }
    int count = q->size;
    int i = q->front;
    while (count--) {
        printf("%d", q->arr[i]);
        if (count > 0) printf(" ");
        i = (i + 1) % q->capacity;
    }
    printf("\n");
}

int main() {
    int n, m;
    scanf("%d", &n);

    struct CircularQueue q;
    initQueue(&q, n);

    for (int i = 0; i < n; i++) {
        int val;
        scanf("%d", &val);
        enqueue(&q, val);
    }

    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        dequeue(&q);
    }

    display(&q);

    free(q.arr);
    return 0;
}
