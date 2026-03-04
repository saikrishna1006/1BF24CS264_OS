#include <stdio.h>

int main() {
    int bt[20], ct[20], at[20], tat[20], wt[20], p[20], order[20], n;
    float twt = 0.0, ttat = 0.0, awt, att;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    // Input and initialize process IDs
    for (int i = 0; i < n; i++) {
        printf("Enter arrival time for process %d: ", i + 1);
        scanf("%d", &at[i]);

        printf("Enter burst time for process %d: ", i + 1);
        scanf("%d", &bt[i]);

        p[i] = i + 1;      // Process IDs
        order[i] = i;      // Index array for sorting
    }

    // Sort only the index array by arrival time
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (at[order[i]] > at[order[j]]) {
                int temp = order[i];
                order[i] = order[j];
                order[j] = temp;
            }
        }
    }

    // Calculate times using sorted order
    ct[order[0]] = at[order[0]] + bt[order[0]];
    wt[order[0]] = 0;
    tat[order[0]] = bt[order[0]];

    for (int k = 1; k < n; k++) {
        int i = order[k];
        int prev = order[k - 1];

        if (ct[prev] < at[i]) {
            ct[i] = at[i] + bt[i];
            wt[i] = 0;
        } else {
            wt[i] = ct[prev] - at[i];
            ct[i] = ct[prev] + bt[i];
        }
        tat[i] = wt[i] + bt[i];
    }

    // Calculate averages
    for (int i = 0; i < n; i++) {
        twt += wt[i];
        ttat += tat[i];
    }

    awt = twt / n;
    att = ttat / n;

    // Output in original order (P1, P2, P3…)
    printf("\nPROCESS\tAT\tBT\tCT\tWT\tTAT");
    for (int i = 0; i < n; i++) {
        printf("\nP%d\t%d\t%d\t%d\t%d\t%d",
               p[i], at[i], bt[i], ct[i], wt[i], tat[i]);
    }

    printf("\n\nAverage Waiting Time = %.2f", awt);
    printf("\nAverage Turnaround Time = %.2f\n", att);

    return 0;
}