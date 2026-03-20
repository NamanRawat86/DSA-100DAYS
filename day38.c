#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct Deque {
    int arr[MAX];
    int front, rear, size;
};

void initDeque(struct Deque* dq) {
    dq->front = 0;
    dq->rear = -1;
    dq->size = 0;
}

int empty(struct Deque* dq) {
    return dq->size == 0;
}

int size(struct Deque* dq) {
    return dq->size;
}

void push_front(struct Deque* dq, int val) {
    if (dq->size == MAX) return;
    dq->front = (dq->front - 1 + MAX) % MAX;
    dq->arr[dq->front] = val;
    dq->size++;
    if (dq->size == 1) dq->rear = dq->front;
}

void push_back(struct Deque* dq, int val) {
    if (dq->size == MAX) return;
    dq->rear = (dq->rear + 1) % MAX;
    dq->arr[dq->rear] = val;
    dq->size++;
    if (dq->size == 1) dq->front = dq->rear;
}

int pop_front(struct Deque* dq) {
    if (empty(dq)) return -1;
    int val = dq->arr[dq->front];
    dq->front = (dq->front + 1) % MAX;
    dq->size--;
    return val;
}

int pop_back(struct Deque* dq) {
    if (empty(dq)) return -1;
    int val = dq->arr[dq->rear];
    dq->rear = (dq->rear - 1 + MAX) % MAX;
    dq->size--;
    return val;
}

int front(struct Deque* dq) {
    if (empty(dq)) return -1;
    return dq->arr[dq->front];
}

int back(struct Deque* dq) {
    if (empty(dq)) return -1;
    return dq->arr[dq->rear];
}

void display(struct Deque* dq) {
    if (empty(dq)) {
        printf("Deque is empty\n");
        return;
    }
    int i = dq->front;
    for (int count = 0; count < dq->size; count++) {
        printf("%d", dq->arr[i]);
        if (count < dq->size - 1) printf(" ");
        i = (i + 1) % MAX;
    }
    printf("\n");
}

int main() {
    struct Deque dq;
    initDeque(&dq);

    push_back(&dq, 10);
    push_back(&dq, 20);
    push_front(&dq, 5);
    display(&dq);

    printf("%d\n", front(&dq));
    printf("%d\n", back(&dq));

    printf("%d\n", pop_front(&dq));
    printf("%d\n", pop_back(&dq));
    display(&dq);

    return 0;
}
