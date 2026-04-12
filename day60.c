#include <stdio.h>
#include <stdlib.h>

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
    if (n == 0) return NULL;

    struct Node* nodes[n];
    for (int i = 0; i < n; i++) {
        if (arr[i] == -1) nodes[i] = NULL;
        else nodes[i] = createNode(arr[i]);
    }

    for (int i = 0; i < n; i++) {
        if (nodes[i] != NULL) {
            int leftIndex = 2 * i + 1;
            int rightIndex = 2 * i + 2;
            if (leftIndex < n) nodes[i]->left = nodes[leftIndex];
            if (rightIndex < n) nodes[i]->right = nodes[rightIndex];
        }
    }
    return nodes[0];
}

int isMinHeap(struct Node* root) {
    if (root == NULL) return 1;

    if (root->left && root->data > root->left->data) return 0;
    if (root->right && root->data > root->right->data) return 0;

    return isMinHeap(root->left) && isMinHeap(root->right);
}

int main() {
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    struct Node* root = buildTree(arr, n);

    if (isMinHeap(root))
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}
