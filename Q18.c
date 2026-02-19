#include <stdio.h>

int main() {
    int n, k;
    
    // Input size
    scanf("%d", &n);
    
    int arr[n], temp[n];
    
    // Input array elements
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    // Input rotation count
    scanf("%d", &k);
    
    // Handle k greater than n
    k = k % n;
    
    // Perform right rotation
    for(int i = 0; i < n; i++) {
        temp[(i + k) % n] = arr[i];
    }
    
    // Print rotated array
    for(int i = 0; i < n; i++) {
        printf("%d ", temp[i]);
    }
    
    return 0;
}
