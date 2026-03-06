#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct Node* createCircularList(int n) {
    struct Node* head = NULL;
    struct Node* temp = NULL;
    struct Node* newNode;
    int val;

    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        newNode = createNode(val);
        if (head == NULL) {
            head = newNode;
            temp = newNode;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }
    if (temp != NULL) temp->next = head;
    return head;
}

void traverseCircularList(struct Node* head) {
    if (head == NULL) return;
    struct Node* temp = head;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

int main() {
    int n;
    scanf("%d", &n);
    struct Node* head = createCircularList(n);
    traverseCircularList(head);
    return 0;
}
