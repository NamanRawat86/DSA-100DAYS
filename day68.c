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

void topologicalSort(struct Node* adj[], int n, int indegree[]) {
    int queue[n], front = 0, rear = 0;

    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0) {
            queue[rear++] = i;
        }
    }

    int count = 0;
    while (front < rear) {
        int u = queue[front++];
        printf("%d ", u);
        count++;

        struct Node* temp = adj[u];
        while (temp) {
            indegree[temp->vertex]--;
            if (indegree[temp->vertex] == 0) {
                queue[rear++] = temp->vertex;
            }
            temp = temp->next;
        }
    }

    if (count != n) {
        printf("\nGraph has a cycle, topological ordering not possible.\n");
    } else {
        printf("\n");
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    struct Node* adj[n];
    for (int i = 0; i < n; i++) adj[i] = NULL;

    int indegree[n];
    for (int i = 0; i < n; i++) indegree[i] = 0;

    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(adj, u, v);
        indegree[v]++;
    }

    topologicalSort(adj, n, indegree);

    return 0;
}
