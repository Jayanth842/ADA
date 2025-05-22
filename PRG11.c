#include <stdio.h>
#include <stdlib.h>
#include <time.h>
 
// Merge function to merge two subarrays
void merge(int arr[], int l, int m, int r) {
   int n1 = m - l + 1;
   int n2 = r - m;
 
   // Create temporary arrays
   int L[n1], R[n2];
 
   // Copy data to temporary arrays L[] and R[]
   for (int i = 0; i < n1; i++)
       L[i] = arr[l + i];
   for (int j = 0; j < n2; j++)
       R[j] = arr[m + 1 + j];
 
   // Merge the temporary arrays back into arr[l..r]
   int i = 0; // Initial index of first subarray
   int j = 0; // Initial index of second subarray
   int k = l; // Initial index of merged subarray
   while (i < n1 && j < n2) {
       if (L[i] <= R[j]) {
           arr[k] = L[i];
           i++;
       } else {
           arr[k] = R[j];
           j++;
       }
       k++;
   }
 
   // Copy the remaining elements of L[], if any
   while (i < n1) {
       arr[k] = L[i];
       i++;
       k++;
   }
 
   // Copy the remaining elements of R[], if any
   while (j < n2) {
       arr[k] = R[j];
       j++;
       k++;
   }
}
 
// Merge Sort function
void mergeSort(int arr[], int l, int r) {
   if (l < r) {
       // Find the middle point
       int m = l + (r - l) / 2;
 
       // Sort first and second halves
       mergeSort(arr, l, m);
       mergeSort(arr, m + 1, r);
 
       // Merge the sorted halves
       merge(arr, l, m, r);
   }
}
 
// Function to generate random integers in the range [min, max]
void generateRandomArray(int arr[], int n, int min, int max) {
   for (int i = 0; i < n; i++) {
       arr[i] = rand() % (max - min + 1) + min;
   }
}
 
int main() {
   FILE *fp;
   fp = fopen("sorting_times.csv", "w");
   if (fp == NULL) {
       printf("Error opening file.\n");
       return 1;
   }
 
   fprintf(fp, "n,Time taken (ms)\n");
 
   srand(time(NULL)); // Seed the random number generator
 
   int max_n = 10000; // Maximum value of n
   int min = 1; // Minimum value of generated integers
   int max = 10000; // Maximum value of generated integers
 
   clock_t start, end;
   double cpu_time_used;
 
   for (int n = 5000; n <= max_n; n += 500) {
       int arr[n];
 
       // Generate random array
       generateRandomArray(arr, n, min, max);
 
       // Start the timer
       start = clock();
 
       // Perform merge sort
       mergeSort(arr, 0, n - 1);
 
       // Stop the timer
       end = clock();
       cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC * 1000; // Time taken in milliseconds
 
       // Print time taken
       printf("Time taken to sort %d elements: %.2f ms\n", n, cpu_time_used);
 
       // Write to file
       fprintf(fp, "%d,%.2f\n", n, cpu_time_used);
   }
 
   fclose(fp);
 
   printf("Data saved to sorting_times.csv\n");
 
   return 0;
}