#include <stdlib.h>
#include <stdio.h>
#include <time.h>
 
// Function to swap two integers
void swap(int* a, int* b) {
   int temp = *a;
   *a = *b;
   *b = temp;
}
 
// Function to partition the array and return the pivot index
int partition(int arr[], int low, int high) {
   int pivot = arr[high]; // Pivot element
   int i = (low - 1); // Index of smaller element
 
   for (int j = low; j <= high - 1; j++) {
       // If current element is smaller than the pivot
       if (arr[j] < pivot) {
           i++; // Increment index of smaller element
           swap(&arr[i], &arr[j]);
       }
   }
   swap(&arr[i + 1], &arr[high]);
   return (i + 1);
}
 
// Function to implement Quick Sort
void quickSort(int arr[], int low, int high) {
   if (low < high) {
       // Partitioning index
       int pi = partition(arr, low, high);
 
       // Sort elements before partition and after partition
       quickSort(arr, low, pi - 1);
       quickSort(arr, pi + 1, high);
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
 
       // Perform quick sort
       quickSort(arr, 0, n - 1);
 
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