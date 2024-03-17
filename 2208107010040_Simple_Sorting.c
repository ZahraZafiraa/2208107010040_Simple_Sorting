#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function prototypes
void generateRandomNumbers(int n, int *arr);
void bubbleSort(int n, int *arr);
void selectionSort(int n, int *arr);
void insertionSort(int n, int *arr);
void saveArrayToFile(char *filename, int n, int *arr, char *algorithmType, int dataSize, int isUnsorted);

int main() {
  srand(time(NULL)); // Initialize random seed

  // Variables
  int n = 1000000; // Total numbers to generate
  int increment = 100000; // Increment value for each test
  int *arr = (int *)malloc(n * sizeof(int)); // Array to hold generated numbers

  // Generate random numbers and save unsorted numbers
  generateRandomNumbers(n, arr);
  saveArrayToFile("numbersRecord.txt", n, arr, "Unsorted numbers", n, 1);

  // Print table header
  printf("+------------------+------------------+---------------------+\n");
  printf("| Jenis Algoritma  | Jumlah Bilangan  | Waktu Eksekusi (ms) |\n");
  printf("+------------------+------------------+---------------------+\n");

  // Bubble Sort
  printf("| Bubble Sort      ");
  for (int i = increment; i <= n; i += increment) {
    int *tempArr = (int *)malloc(i * sizeof(int));
    for (int j = 0; j < i; j++) {
      tempArr[j] = arr[j];
    }
    clock_t start = clock();
    bubbleSort(i, tempArr);
    clock_t end = clock();
    double time_spent = ((double)(end - start)) * 1000 / CLOCKS_PER_SEC;
    saveArrayToFile("numbersRecord.txt", n, tempArr, "Bubble sort", i, 0);
    printf("| %-16d | %-19.2lf |\n", i, time_spent);
    // Print empty string for subsequent rows
    if (i != n) {
      printf("|                  ");
    }
    free(tempArr);
  }

  // Selection Sort
  printf("+------------------+------------------+---------------------+\n");
  printf("| Selection Sort   ");
  for (int i = increment; i <= n; i += increment) {
    int *tempArr = (int *)malloc(i * sizeof(int));
    for (int j = 0; j < i; j++) {
      tempArr[j] = arr[j];
    }
    clock_t start = clock();
    selectionSort(i, tempArr);
    clock_t end = clock();
    double time_spent = ((double)(end - start)) * 1000 / CLOCKS_PER_SEC;
    saveArrayToFile("numbersRecord.txt", n, tempArr, "Selection sort", i, 0);
    printf("| %-16d | %-19.2lf |\n", i, time_spent);
    // Print empty string for subsequent rows
    if (i != n) {
      printf("|                  ");
    }
    free(tempArr);
  }

  // Insertion Sort
  printf("+------------------+------------------+---------------------+\n");
  printf("| Insertion Sort   ");
  for (int i = increment; i <= n; i += increment) {
    int *tempArr = (int *)malloc(i * sizeof(int));
    for (int j = 0; j < i; j++) {
      tempArr[j] = arr[j];
    }
    clock_t start = clock();
    insertionSort(i, tempArr);
    clock_t end = clock();
    double time_spent = ((double)(end - start)) * 1000 / CLOCKS_PER_SEC;
    saveArrayToFile("numbersRecord.txt", n, tempArr, "Insertion sort", i, 0);
    printf("| %-16d | %-19.2lf |\n", i, time_spent);
    // Print empty string for subsequent rows
    if (i != n) {
      printf("|                  ");
    }
    free(tempArr);
  }
  printf("+------------------+------------------+---------------------+\n");
  free(arr);
  return 0;
}

void generateRandomNumbers(int n, int *arr) {
  for (int i = 0; i < n; i++) {
    arr[i] = rand();
  }
}

void bubbleSort(int n, int *arr) {
  int temp;
  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < n - i - 1; j++) {
      if (arr[j] > arr[j + 1]) {
        temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
    }
  }
}

void selectionSort(int n, int *arr) {
  int minIndex,
  temp;
  for (int i = 0; i < n - 1; i++) {
    minIndex = i;
    for (int j = i + 1; j < n; j++) {
      if (arr[j] < arr[minIndex]) {
        minIndex = j;
      }
    }
    temp = arr[i];
    arr[i] = arr[minIndex];
    arr[minIndex] = temp;
  }
}

void insertionSort(int n, int *arr) {
  int key,
  j;
  for (int i = 1; i < n; i++) {
    key = arr[i];
    j = i - 1;
    while (j >= 0 && arr[j] > key) {
      arr[j + 1] = arr[j];
      j = j - 1;
    }
    arr[j + 1] = key;
  }
}

void saveArrayToFile(char *filename, int n, int *arr, char *algorithmType, int dataSize, int isUnsorted) {
  FILE *file = fopen(filename, "a");
  if (file == NULL) {
    printf("Error opening file.\n");
    return;
  }

  if (isUnsorted) {
    fprintf(file, "Unsorted numbers:\n");
    for (int i = 0; i < n; i++) {
      fprintf(file, "%d\n", arr[i]);
    }
    fprintf(file, "\n");
  } else {
    fprintf(file, "%s (%d):\n", algorithmType, dataSize);
    for (int i = 0; i < dataSize; i++) {
      fprintf(file, "%d\n", arr[i]);
    }
    fprintf(file, "\n");
  }

  fclose(file);
}