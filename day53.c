#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1) return NULL;

    struct Node* root = createNode(arr[0]);
    struct Node* queue[n];
    int front = 0, rear = 0;
    queue[rear++] = root;

    int i = 1;
    while (i < n) {
        struct Node* current = queue[front++];

        if (arr[i] != -1) {
            current->left = createNode(arr[i]);
            queue[rear++] = current->left;
        }
        i++;

        if (i < n && arr[i] != -1) {
            current->right = createNode(arr[i]);
            queue[rear++] = current->right;
        }
        i++;
    }
    return root;
}

struct Pair {
    struct Node* node;
    int hd;
};

void verticalOrder(struct Node* root) {
    if (root == NULL) return;

    struct Pair queue[1000];
    int front = 0, rear = 0;
    queue[rear++] = (struct Pair){root, 0};

    int minHD = INT_MAX, maxHD = INT_MIN;
    int map[1000][1000]; 
    int count[1000] = {0};

    while (front < rear) {
        struct Pair current = queue[front++];
        struct Node* node = current.node;
        int hd = current.hd;

        if (hd < minHD) minHD = hd;
        if (hd > maxHD) maxHD = hd;

        map[hd + 500][count[hd + 500]++] = node->data;

        if (node->left) queue[rear++] = (struct Pair){node->left, hd - 1};
        if (node->right) queue[rear++] = (struct Pair){node->right, hd + 1};
    }

    for (int hd = minHD; hd <= maxHD; hd++) {
        for (int i = 0; i < count[hd + 500]; i++) {
            printf("%d ", map[hd + 500][i]);
        }
        printf("\n");
    }
}

int main() {
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    struct Node* root = buildTree(arr, n);

    verticalOrder(root);

    return 0;
}
