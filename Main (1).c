#include <stdio.h>
#include <stdlib.h>
 
// Structure to represent items
struct Item {
   int weight;
   int value;
   double density; // Density is value/weight ratio
};
 
// Function to solve discrete knapsack problem using greedy approximation method
int discreteKnapsack(struct Item items[], int n, int capacity) {
   // Calculate density for each item
   for (int i = 0; i < n; i++) {
       items[i].density = (double)items[i].value / items[i].weight;
   }
 
   // Sort items based on their density in non-increasing order using insertion sort
   for (int i = 1; i < n; i++) {
       struct Item temp = items[i];
       int j = i - 1;
       while (j >= 0 && items[j].density < temp.density) {
           items[j + 1] = items[j];
           j--;
       }
       items[j + 1] = temp;
   }
 
   // Fill the knapsack with items greedily
   int totalValue = 0;
   for (int i = 0; i < n && capacity > 0; i++) {
       if (items[i].weight <= capacity) {
           totalValue += items[i].value;
           capacity -= items[i].weight;
       }
   }
 
   return totalValue;
}
 
// Function to solve continuous knapsack problem using greedy approximation method
double continuousKnapsack(struct Item items[], int n, int capacity) {
   // Calculate density for each item
   for (int i = 0; i < n; i++) {
       items[i].density = (double)items[i].value / items[i].weight;
   }
 
   // Sort items based on their density in non-increasing order using insertion sort
   for (int i = 1; i < n; i++) {
       struct Item temp = items[i];
       int j = i - 1;
       while (j >= 0 && items[j].density < temp.density) {
           items[j + 1] = items[j];
           j--;
       }
       items[j + 1] = temp;
   }
 
   // Fill the knapsack with items greedily
   double totalValue = 0.0;
   for (int i = 0; i < n && capacity > 0; i++) {
       if (items[i].weight <= capacity) {
           totalValue += items[i].value;
           capacity -= items[i].weight;
       } else {
           totalValue += (capacity * items[i].density);
           capacity = 0;
       }
   }
 
   return totalValue;
}
 
int main() {
   // Sample data for discrete knapsack problem
   struct Item discreteItems[] = {{10, 60}, {20, 100}, {30, 120}};
   int n1 = sizeof(discreteItems) / sizeof(discreteItems[0]);
   int discreteCapacity = 50;
 
   // Sample data for continuous knapsack problem
   struct Item continuousItems[] = {{10, 60}, {20, 100}, {30, 120}};
   int n2 = sizeof(continuousItems) / sizeof(continuousItems[0]);
   int continuousCapacity = 50;
 
   // Compute and print solutions for discrete and continuous knapsack problems
   printf("Discrete Knapsack Problem:\n");
   int discreteResult = discreteKnapsack(discreteItems, n1, discreteCapacity);
   printf("Maximum value obtained: %d\n\n", discreteResult);
 
   printf("Continuous Knapsack Problem:\n");
   double continuousResult = continuousKnapsack(continuousItems, n2, continuousCapacity);
   printf("Maximum value obtained: %.2f\n", continuousResult);
 
   return 0;
}