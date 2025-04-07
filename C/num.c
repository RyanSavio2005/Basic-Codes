#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate random weights and profits
void generateRandomItems(int weight[], int profit[], int n) {
    for (int i = 0; i < n; i++) {
        weight[i] = (rand() % 20) + 1;  // Random weight (1 to 20)
        profit[i] = (rand() % 100) + 10; // Random profit (10 to 100)
    }
}

// Function to sort items based on profit-to-weight ratio (Ascending Order)
void sortItemsAscending(int weight[], int profit[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            double ratio1 = (double)profit[j] / weight[j];
            double ratio2 = (double)profit[j + 1] / weight[j + 1];
            if (ratio1 > ratio2) { // Swap for ascending order
                // Swap weights
                int tempW = weight[j];
                weight[j] = weight[j + 1];
                weight[j + 1] = tempW;

                // Swap profits
                int tempP = profit[j];
                profit[j] = profit[j + 1];
                profit[j + 1] = tempP;
            }
        }
    }
}

// Function to solve the Fractional Knapsack Problem
double fractionalKnapsack(int weight[], int profit[], int n, int capacity) {
    sortItemsAscending(weight, profit, n); // Sorting items in ascending order

    // Display sorted items
    printf("\nItems sorted by profit-to-weight ratio (Ascending Order):\n");
    printf("Item\tWeight\tProfit\tRatio\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%.2f\n", i + 1, weight[i], profit[i], (double)profit[i] / weight[i]);
    }

    double totalProfit = 0.0;
    int currentWeight = 0;

    for (int i = 0; i < n; i++) {
        if (currentWeight + weight[i] <= capacity) {
            totalProfit += profit[i];
            currentWeight += weight[i];
        } else {
            int remaining = capacity - currentWeight;
            totalProfit += profit[i] * ((double)remaining / weight[i]);
            break;
        }
    }
    return totalProfit;
}

int main() {
    srand(time(0)); // Seed for random number generation

    int n, capacity;

    printf("Enter number of items: ");
    scanf("%d", &n);

    printf("Enter knapsack capacity: ");
    scanf("%d", &capacity);

    int weight[n], profit[n];

    // Generate random items
    generateRandomItems(weight, profit, n);

    // Display generated items (Before Sorting)
    printf("\nGenerated Items (Before Sorting):\n");
    printf("Item\tWeight\tProfit\tRatio\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%.2f\n", i + 1, weight[i], profit[i], (double)profit[i] / weight[i]);
    }

    double maxProfit = fractionalKnapsack(weight, profit, n, capacity);
    printf("\nMaximum profit obtained: %.2f\n", maxProfit);

    return 0;
}


