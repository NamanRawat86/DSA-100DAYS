#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Edge {
    int vertex;
    int weight;
    struct Edge* next;
};

struct Edge* createEdge(int v, int w) {
    struct Edge* newEdge = (struct Edge*)malloc(sizeof(struct Edge));
    newEdge->vertex = v;
    newEdge->weight = w;
    newEdge->next = NULL;
    return newEdge;
}

void addEdge(struct Edge* adj[], int u, int v, int w, int directed) {
    struct Edge* newEdge = createEdge(v, w);
    newEdge->next = adj[u];
    adj[u] = newEdge;

    if (!directed) {
        newEdge = createEdge(u, w);
        newEdge->next = adj[v];
        adj[v] = newEdge;
    }
}

struct HeapNode {
    int vertex;
    int dist;
};

struct MinHeap {
    struct HeapNode* arr;
    int size;
    int capacity;
    int* pos;
};

struct MinHeap* createMinHeap(int capacity) {
    struct MinHeap* heap = (struct MinHeap*)malloc(sizeof(struct MinHeap));
    heap->arr = (struct HeapNode*)malloc(capacity * sizeof(struct HeapNode));
    heap->pos = (int*)malloc(capacity * sizeof(int));
    heap->size = 0;
    heap->capacity = capacity;
    return heap;
}

void swapHeapNode(struct HeapNode* a, struct HeapNode* b) {
    struct HeapNode temp = *a;
    *a = *b;
    *b = temp;
}

void minHeapify(struct MinHeap* heap, int idx) {
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < heap->size && heap->arr[left].dist < heap->arr[smallest].dist)
        smallest = left;
    if (right < heap->size && heap->arr[right].dist < heap->arr[smallest].dist)
        smallest = right;

    if (smallest != idx) {
        heap->pos[heap->arr[smallest].vertex] = idx;
        heap->pos[heap->arr[idx].vertex] = smallest;
        swapHeapNode(&heap->arr[smallest], &heap->arr[idx]);
        minHeapify(heap, smallest);
    }
}

struct HeapNode extractMin(struct MinHeap* heap) {
    struct HeapNode root = heap->arr[0];
    struct HeapNode last = heap->arr[heap->size - 1];
    heap->arr[0] = last;

    heap->pos[root.vertex] = heap->size - 1;
    heap->pos[last.vertex] = 0;

    heap->size--;
    minHeapify(heap, 0);

    return root;
}

void decreaseKey(struct MinHeap* heap, int v, int dist) {
    int i = heap->pos[v];
    heap->arr[i].dist = dist;

    while (i && heap->arr[i].dist < heap->arr[(i - 1) / 2].dist) {
        heap->pos[heap->arr[i].vertex] = (i - 1) / 2;
        heap->pos[heap->arr[(i - 1) / 2].vertex] = i;
        swapHeapNode(&heap->arr[i], &heap->arr[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

int isEmpty(struct MinHeap* heap) {
    return heap->size == 0;
}

void dijkstra(struct Edge* adj[], int n, int src) {
    int dist[n];
    for (int i = 0; i < n; i++) dist[i] = INT_MAX;
    dist[src] = 0;

    struct MinHeap* heap = createMinHeap(n);
    for (int v = 0; v < n; v++) {
        heap->arr[v].vertex = v;
        heap->arr[v].dist = dist[v];
        heap->pos[v] = v;
    }
    heap->size = n;

    while (!isEmpty(heap)) {
        struct HeapNode minNode = extractMin(heap);
        int u = minNode.vertex;

        struct Edge* temp = adj[u];
        while (temp) {
            int v = temp->vertex;
            if (dist[u] != INT_MAX && temp->weight + dist[u] < dist[v]) {
                dist[v] = dist[u] + temp->weight;
                decreaseKey(heap, v, dist[v]);
            }
            temp = temp->next;
        }
    }

    for (int i = 0; i < n; i++) {
        if (dist[i] == INT_MAX) printf("INF ");
        else printf("%d ", dist[i]);
    }
    printf("\n");
}

int main() {
    int n, m, directed;
    scanf("%d %d", &n, &m);
    scanf("%d", &directed);

    struct Edge* adj[n];
    for (int i = 0; i < n; i++) adj[i] = NULL;

    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        addEdge(adj, u, v, w, directed);
    }

    int src;
    scanf("%d", &src);

    dijkstra(adj, n, src);

    return 0;
}
