//01/04/25
#include <stdio.h>
#include <stdlib.h>

// Structure to represent a job
struct job {
    int id;
    int deadline;
    int profit;
};

// Function to compare two jobs based on their profit
int compare(const void* a, const void* b) {
    return ((struct job*)b)->profit - ((struct job*)a)->profit;
}

// Function to schedule jobs to maximize profit with given deadlines
void scheduleJobs(struct job jobs[], int n) {
    int maxDeadline = 0;
    int i;
    
    // Find the maximum deadline
    for (i = 0; i < n; ++i) {
        if (jobs[i].deadline > maxDeadline) {
            maxDeadline = jobs[i].deadline;
        }
    }
    
    // Initialize result array
    int result[maxDeadline];
    for (i = 0; i < maxDeadline; ++i) {
        result[i] = -1;
    }
    
    int totalProfit = 0, totalJobs = 0;
    
    // Schedule jobs
    for (i = 0; i < n; ++i) {
        int deadline = jobs[i].deadline;
        while (deadline > 0 && result[deadline - 1] != -1) {
            deadline--;
        }
        if (deadline > 0) {
            result[deadline - 1] = jobs[i].id;
            totalProfit += jobs[i].profit;
            totalJobs++;
        }
    }
    
    // Print results
    printf("Scheduled Jobs: ");
    for (i = 0; i < maxDeadline; ++i) {
        if (result[i] != -1) {
            printf("%d ", result[i]);
        }
    }
    printf("\nTotal Profit: %d\n", totalProfit);
    printf("Number of jobs scheduled: %d\n", totalJobs);
}

int main() {
    int n;
    printf("Enter the number of jobs: ");
    scanf("%d", &n);

    struct job jobs[n];
    int i;
    printf("Enter the deadline and profit for each job:\n");
    for (i = 0; i < n; ++i) {
        printf("Job %d: ", i + 1);
        scanf("%d %d", &jobs[i].deadline, &jobs[i].profit);
        jobs[i].id = i + 1;
    }

    // Sort jobs based on their profit (in non-increasing order)
    qsort(jobs, n, sizeof(struct job), compare);

    // Schedule the jobs
    scheduleJobs(jobs, n);

    return 0;
}
