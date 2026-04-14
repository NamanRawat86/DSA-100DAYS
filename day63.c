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

void addEdge(struct Node* adj[], int u, int v, int directed) {
    struct Node* newNode = createNode(v);
    newNode->next = adj[u];
    adj[u] = newNode;

    if (!directed) {
        newNode = createNode(u);
        newNode->next = adj[v];
        adj[v] = newNode;
    }
}

void DFS(struct Node* adj[], int visited[], int v) {
    visited[v] = 1;
    printf("%d ", v);

    struct Node* temp = adj[v];
    while (temp) {
        if (!visited[temp->vertex]) {
            DFS(adj, visited, temp->vertex);
        }
        temp = temp->next;
    }
}

int main() {
    int n, m, directed;
    scanf("%d %d", &n, &m);
    scanf("%d", &directed);

    struct Node* adj[n];
    for (int i = 0; i < n; i++) adj[i] = NULL;

    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(adj, u, v, directed);
    }

    int s;
    scanf("%d", &s);

    int visited[n];
    for (int i = 0; i < n; i++) visited[i] = 0;

    DFS(adj, visited, s);
    printf("\n");

    return 0;
}
