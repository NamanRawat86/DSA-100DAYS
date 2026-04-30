#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Edge {
    int v, w;
    struct Edge* next;
};

struct Edge* adj[1000]; // adjacency list

void addEdge(int u, int v, int w) {
    struct Edge* newNode = (struct Edge*)malloc(sizeof(struct Edge));
    newNode->v = v;
    newNode->w = w;
    newNode->next = adj[u];
    adj[u] = newNode;

    newNode = (struct Edge*)malloc(sizeof(struct Edge));
    newNode->v = u;
    newNode->w = w;
    newNode->next = adj[v];
    adj[v] = newNode;
}

struct HeapNode {
    int v, dist;
};

struct MinHeap {
    struct HeapNode* arr[1000];
    int size;
};

struct MinHeap* createHeap() {
    struct MinHeap* heap = (struct MinHeap*)malloc(sizeof(struct MinHeap));
    heap->size = 0;
    return heap;
}

void swap(struct HeapNode** a, struct HeapNode** b) {
    struct HeapNode* temp = *a;
    *a = *b;
    *b = temp;
}

void heapifyUp(struct MinHeap* heap, int idx) {
    while (idx > 0) {
        int parent = (idx - 1) / 2;
        if (heap->arr[idx]->dist < heap->arr[parent]->dist) {
            swap(&heap->arr[idx], &heap->arr[parent]);
            idx = parent;
        } else break;
    }
}

void heapifyDown(struct MinHeap* heap, int idx) {
    int left, right, smallest;
    while (1) {
        left = 2*idx + 1;
        right = 2*idx + 2;
        smallest = idx;
        if (left < heap->size && heap->arr[left]->dist < heap->arr[smallest]->dist)
            smallest = left;
        if (right < heap->size && heap->arr[right]->dist < heap->arr[smallest]->dist)
            smallest = right;
        if (smallest != idx) {
            swap(&heap->arr[idx], &heap->arr[smallest]);
            idx = smallest;
        } else break;
    }
}

void push(struct MinHeap* heap, int v, int dist) {
    struct HeapNode* node = (struct HeapNode*)malloc(sizeof(struct HeapNode));
    node->v = v;
    node->dist = dist;
    heap->arr[heap->size] = node;
    heapifyUp(heap, heap->size);
    heap->size++;
}

struct HeapNode* pop(struct MinHeap* heap) {
    if (heap->size == 0) return NULL;
    struct HeapNode* root = heap->arr[0];
    heap->arr[0] = heap->arr[heap->size-1];
    heap->size--;
    heapifyDown(heap, 0);
    return root;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    for (int i = 1; i <= n; i++) adj[i] = NULL;

    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        addEdge(u, v, w);
    }

    int src;
    scanf("%d", &src);

    int dist[n+1];
    for (int i = 1; i <= n; i++) dist[i] = INT_MAX;
    dist[src] = 0;

    struct MinHeap* heap = createHeap();
    push(heap, src, 0);

    while (heap->size > 0) {
        struct HeapNode* node = pop(heap);
        int u = node->v;
        int d = node->dist;
        free(node);

        if (d > dist[u]) continue;

        struct Edge* temp = adj[u];
        while (temp) {
            int v = temp->v;
            int w = temp->w;
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                push(heap, v, dist[v]);
            }
            temp = temp->next;
        }
    }

    for (int i = 1; i <= n; i++) {
        if (dist[i] == INT_MAX) printf("INF ");
        else printf("%d ", dist[i]);
    }
    printf("\n");

    return 0;
}
