#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Candidate {
    char name[100];
    int votes;
};

int main() {
    int n;
    scanf("%d", &n);

    struct Candidate arr[n];
    int count = 0;

    for (int i = 0; i < n; i++) {
        char temp[100];
        scanf("%s", temp);

        int found = 0;
        for (int j = 0; j < count; j++) {
            if (strcmp(arr[j].name, temp) == 0) {
                arr[j].votes++;
                found = 1;
                break;
            }
        }
        if (!found) {
            strcpy(arr[count].name, temp);
            arr[count].votes = 1;
            count++;
        }
    }

    char winner[100];
    int maxVotes = -1;

    for (int i = 0; i < count; i++) {
        if (arr[i].votes > maxVotes) {
            maxVotes = arr[i].votes;
            strcpy(winner, arr[i].name);
        } else if (arr[i].votes == maxVotes) {
            if (strcmp(arr[i].name, winner) < 0) {
                strcpy(winner, arr[i].name);
            }
        }
    }

    printf("%s %d\n", winner, maxVotes);
    return 0;
}
