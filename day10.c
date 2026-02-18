#include <stdio.h>
#include <string.h>

int main() {
    char s[1000];
    int left, right, flag = 1;

    scanf("%s", s);              // read string (no spaces)
    left = 0;
    right = strlen(s) - 1;

    while (left < right) {
        if (s[left] != s[right]) {
            flag = 0;
            break;
        }
        left++;
        right--;
    }

    if (flag)
        printf("YES");
    else
        printf("NO");

    return 0;
}
