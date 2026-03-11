#include <stdio.h>
#define MAX 100

int stack[MAX];
int top = -1;

void push(int val) {
    if (top == MAX - 1) return; 
    stack[++top] = val;
}

void pop() {
    if (top == -1) return; 
    top--;
}

void display() {
    for (int i = top; i >= 0; i--) {
        printf("%d", stack[i]);
        if (i > 0) printf(" ");
    }
    printf("\n");
}

int main() {
    int n, m;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int val;
        scanf("%d", &val);
        push(val);
    }

    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        pop();
    }

    display();
    return 0;
}
