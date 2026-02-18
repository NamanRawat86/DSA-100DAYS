/*Problem: Write a C program to insert an element x at a given 1-based position pos in an array of n integers. Shift existing elements to the right to make space.
*/

#include <stdio.h>

int main() {
    int n, pos, x;
    
    // Read size of array
    scanf("%d", &n);
    
    int arr[100]; // assuming max size 100 for simplicity
    
    // Read array elements
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    // Read position and element to insert
    scanf("%d", &pos);
    scanf("%d", &x);
    
    // Shift elements to the right from pos-1
    for (int i = n; i >= pos; i--) {
        arr[i] = arr[i - 1];
    }
    
    // Insert element at position (1-based index)
    arr[pos - 1] = x;
    
    // Print updated array
    for (int i = 0; i <= n; i++) {
        printf("%d", arr[i]);
        if (i != n) printf(" ");
    }
    
    return 0;
}