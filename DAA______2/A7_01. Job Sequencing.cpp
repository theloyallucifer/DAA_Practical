#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char id;
    int profit;
    int deadline;
} Job;

int compareJobs(const void *a, const void *b) {
    return ((Job *)b)->profit - ((Job *)a)->profit;
}

int findMaxDeadline(Job jobs[], int n) {
    int max = 0;
    for (int i = 0; i < n; i++) {
        if (jobs[i].deadline > max) {
            max = jobs[i].deadline;
        }
    }
    return max;
}

void jobSequencing(Job jobs[], int n) {
    qsort(jobs, n, sizeof(Job), compareJobs);
    int maxDeadline = findMaxDeadline(jobs, n);
    if (maxDeadline == 0) {
        printf("No valid job scheduling possible.\n");
        return;
    }

    char *result = (char *)malloc(maxDeadline * sizeof(char));
    int *slot = (int *)malloc(maxDeadline * sizeof(int));
    int totalProfit = 0;

    for (int i = 0; i < maxDeadline; i++) {
        slot[i] = -1;
        result[i] = '\0';
    }

    for (int i = 0; i < n; i++) {
        for (int j = jobs[i].deadline - 1; j >= 0; j--) {
            if (slot[j] == -1) { 
                slot[j] = i;
                result[j] = jobs[i].id;
                totalProfit += jobs[i].profit;
                break;
            }
        }
    }

    printf("Scheduled Jobs: ");
    for (int i = 0; i < maxDeadline; i++) {
        if (slot[i] != -1)
            printf("%c ", result[i]);
    }
    printf("\nTotal Profit: %d\n", totalProfit);

    free(result);
    free(slot);
}

int main() {
    int n;
    printf("Enter the number of jobs: ");
    scanf("%d", &n);

    Job *jobs = (Job *)malloc(n * sizeof(Job));
    if (jobs == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }
    printf("Enter job details (ID Profit Deadline):\n");
    for (int i = 0; i < n; i++) {
        printf("Job %d: ", i + 1);
        scanf(" %c %d %d", &jobs[i].id, &jobs[i].profit, &jobs[i].deadline);
    }

    jobSequencing(jobs, n);
    free(jobs);
    return 0;
}

