#include <stdio.h>
#include <stdbool.h>
 
#define MAX_SIZE 100
 
// Function to find a subset of a given set whose sum is equal to a given positive integer
void findSubset(int set[], int n, int sum, int subset[], int subSize, int totalSum, int index) {
   if (totalSum == sum) {
       // Print the subset
       printf("Subset found: { ");
       for (int i = 0; i < subSize; i++)
           printf("%d ", subset[i]);
       printf("}\n");
       return;
   }
 
   if (index >= n || totalSum > sum)
       return;
 
   // Include the current element in the subset
   subset[subSize] = set[index];
   findSubset(set, n, sum, subset, subSize + 1, totalSum + set[index], index + 1);
 
   // Exclude the current element and move to the next one
   findSubset(set, n, sum, subset, subSize, totalSum, index + 1);
}
 
int main() {
   int set[] = {12, 4, 5, 6, 7, 2, 3, 8, 9}; // Given set
   int n = sizeof(set) / sizeof(set[0]); // Number of elements in the set
   int sum = 15; // Given sum
   int subset[MAX_SIZE]; // Array to store the subset
   int subSize = 0; // Size of the subset
 
   printf("Finding subset(s) with sum %d:\n", sum);
   findSubset(set, n, sum, subset, subSize, 0, 0);
 
   return 0;
}
