#include <stdio.h>
#include <stdlib.h>

struct Hash {
    int sum;
    int index;
};

int main() {
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    struct Hash hash[2*n+1]; 
    for (int i = 0; i < 2*n+1; i++) {
        hash[i].sum = 0;
        hash[i].index = -1;
    }

    int prefixSum = 0, maxLen = 0;
    for (int i = 0; i < n; i++) {
        prefixSum += arr[i];

        if (prefixSum == 0) {
            if (i + 1 > maxLen) maxLen = i + 1;
        }

        int found = 0;
        for (int j = 0; j < 2*n+1; j++) {
            if (hash[j].index != -1 && hash[j].sum == prefixSum) {
                int len = i - hash[j].index;
                if (len > maxLen) maxLen = len;
                found = 1;
                break;
            }
        }

        if (!found) {
            for (int j = 0; j < 2*n+1; j++) {
                if (hash[j].index == -1) {
                    hash[j].sum = prefixSum;
                    hash[j].index = i;
                    break;
                }
            }
        }
    }

    printf("%d\n", maxLen);
    return 0;
}
