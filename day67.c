#include <stdio.h>
#include <stdlib.h>

struct Node {
    int vertex;
    struct Node* next;
};

struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

void addEdge(struct Node* adj[], int u, int v) {
    struct Node* newNode = createNode(v);
    newNode->next = adj[u];
    adj[u] = newNode;
}

void DFS(struct Node* adj[], int visited[], int v, int* stack, int* top) {
    visited[v] = 1;
    struct Node* temp = adj[v];
    while (temp) {
        if (!visited[temp->vertex]) {
            DFS(adj, visited, temp->vertex, stack, top);
        }
        temp = temp->next;
    }
    stack[(*top)++] = v; 
}

void topologicalSort(struct Node* adj[], int n) {
    int visited[n];
    for (int i = 0; i < n; i++) visited[i] = 0;

    int stack[n];
    int top = 0;

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            DFS(adj, visited, i, stack, &top);
        }
    }

    for (int i = top - 1; i >= 0; i--) {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    struct Node* adj[n];
    for (int i = 0; i < n; i++) adj[i] = NULL;

    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(adj, u, v);
    }

    topologicalSort(adj, n);

    return 0;
}
