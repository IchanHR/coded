#include <stdio.h>
#include <stdlib.h>

#define MAX 100

//Swap Function
void swap(int *a, int *b) { //variables that point to the integers that soon be swapped
int temp = *a; //intializing a temporary variable and set it to the value of a
//switch time
*a = *b; //setting the value of a to b variable
*b = temp; //setting the value of b to the temporary variable
}

// Bubble Sort Function
void bubbleSort(int arr[], int n) { //initializing n as the size of the array and arr as the array to be sorted
for (int i = 0; i < n-1; i++) //looping through the nth element of the array
    for (int j = 0; j < n-i-1; j++) //looping through the array until the last unsorted element
        if (arr[j] > arr[j+1]) //if the current is greater than next
            swap(&arr[j], &arr[j+1]); //then call swap function to swap the elements
}

// Selection Sort Function
void selectionSort(int arr[], int n) { //initializing n as the size of the array and arr as the array to be sorted
for (int i = 0; i < n-1; i++) { //looping through the nth element of the array
    int minIdx = i; //initializing the minimum index to the current index
    for (int j = i+1; j < n; j++) //looping through the array to find the minimum element
        if (arr[j] < arr[minIdx]) //if the current index element is less than the minimum index element
            minIdx = j; //set the minimum index to the current index
    swap(&arr[minIdx], &arr[i]); //perform a swap minimum index element with the current index element
}
}

// Insertion Sort Function
void insertionSort(int arr[], int n) { //initializing n as the size of the array and arr as the array to be sorted
for (int i = 1; i < n; i++) { //looping through the array starting from the second element
    int key = arr[i]; //setting variable key to the current element
    int j = i - 1;
    while (j >= 0 && arr[j] > key) {
        arr[j+1] = arr[j];
        j--;
    }
    arr[j+1] = key;
}
}

// partition function for Quick Sort function to help in sorting
int partition(int arr[], int low, int high) { //initializing low and high as the range of the array to be sorted
int pivot = arr[high]; //setting the pivot to the last element of the array
int i = (low - 1); //initializing i to the index before the first element
for (int j = low; j < high; j++) { //looping through the array from low to high
    if (arr[j] < pivot) { //if the current element is less than the pivot
        i++; //increment i
        swap(&arr[i], &arr[j]); //swap the current element with the element at index i
    }
}
swap(&arr[i + 1], &arr[high]); //calling swap function to swap the pivot with the element at index i + 1
return (i + 1); //returning the index of the pivot after swapping
}

// Quick Sort Function
void quickSort(int arr[], int low, int high) { //initializing low and high as the range of the array to be sorted
if (low < high) { //if low is less than high = more than one element means need sorting
    int pi = partition(arr, low, high); //calling partition function to get the pivot index
    quickSort(arr, low, pi - 1); //recursively calling quickSort on the left side of the pivot
    quickSort(arr, pi + 1, high); //recursively calling quickSort on the right side of the pivot
}
}

// Merging Function 
void merge(int arr[], int l, int m, int r) { //initializing l as the left index, m as the middle index, and r as the right index
int n1 = m - l + 1; //getting number of elements in the left subarray
int n2 = r - m; //getting number of elements in the right subarray
int L[n1], R[n2]; //setting temporary array variables to hold the left and right subarrays

for (int i = 0; i < n1; i++) //looping through the left subarray
    L[i] = arr[l + i]; //copying elements from the original array to the left subarray for sorting later
for (int j = 0; j < n2; j++) //looping through the right subarray
    R[j] = arr[m + 1 + j]; //copying elements from the original array to the right subarray for sorting later

int i = 0, j = 0, k = l; //initializing i and j as the index for left and right subarrays, and k for the index of original array
while (i < n1 && j < n2) { //looping until the end of either subarray
    arr[k++] = (L[i] <= R[j]) ? L[i++] : R[j++]; //comparing elements from both subarrays and placing the smaller one in the original array
}
while (i < n1) arr[k++] = L[i++]; //checking if there are remaining elements in the left subarray, copy them to the original array
while (j < n2) arr[k++] = R[j++]; //checking if there are remaining elements in the right subarray, copy them to the original array
}

// Merge Sort Function
void mergeSort(int arr[], int l, int r) { //initializing l as the left index and r as the right index
if (l < r) { //if left index is less than right index = more than one element means need sorting
    int m = l + (r - l) / 2; //finding the middle index and setting it to m
    mergeSort(arr, l, m); //calling mergesort for the left half of the array
    mergeSort(arr, m + 1, r); //calling mergesort for the right half of the array
    merge(arr, l, m, r); //calling merge function to merge the two halves
}
}

// Output the sorted array function
void printArray(int arr[], int n) {
for (int i = 0; i < n; i++)
    printf("%d ", arr[i]);
printf("\n");
}

// Duplicate checker function to check if there are same number in the input
int isDuplicate(int arr[], int size, int num) { //initializing arr as the array to be checked, size as the number of elements in the array, and num as the number to be checked
for (int i = 0; i < size; i++) //looping through the array
    if (arr[i] == num) return 1; //if the number is found in the array, return 1 (true)
return 0; //if the number is not found, return 0 (false)
}

int main() { 
int data[MAX], sorted[MAX], n, choice; //initializing data as the array to hold input numbers, sorted as the array to hold sorted numbers, n as the number of elements, and choice as the sorting method chosen by user
char rpt; // variable to ask user if they want to sort again

//asking for the number of data to be inputted and later be sorted from the user
printf("Berapa banyak data: ");
scanf("%d", &n);

//looping to get input from the user as much as n(number of data)
for (int i = 0; i < n; ) {
    int num;
    printf("Input data ke-%d: ", i+1);
        scanf("%d", &num);
    if (num < 1 || num > 100) { //checking if the input is between 1 and 100
        printf("Angka harus antara 1 - 100\n");
        continue;
    }
    if (isDuplicate(data, i, num)) { //calling isDuplicate function to check if the number is a duplicate
        printf("Tidak boleh duplikat\n");
        continue;
    }
    data[i++] = num; //storing the number in the data array if it is valid and not a duplicate
}

do {
    for (int i = 0; i < n; i++) sorted[i] = data[i]; //copying the data array to the sorted array for sorting

    //asking the user to choose which sorting method they prefer to use and calling the corresponding sorting function to sort the inputted numbers
    printf("\nPilih Metode Sorting:\n"); 
    printf("1. Bubble Sort\n2. Selection Sort\n3. Insertion Sort\n4. Quick Sort\n5. Merge Sort\n");
        printf("Pilihan anda: ");
    scanf("%d", &choice); //getting the user's choice of sorting method

    //switch case to call the corresponding sorting function based on user choice
    switch (choice) {
        case 1: bubbleSort(sorted, n); break;
        case 2: selectionSort(sorted, n); break;
        case 3: insertionSort(sorted, n); break;
        case 4: quickSort(sorted, 0, n-1); break;
        case 5: mergeSort(sorted, 0, n-1); break;
        default: printf("Pilihan tidak valid\n"); continue; // if the choice is not valid, continue to the next iteration
    }

    //displaying the sorted array
    printf("Hasil sorting:\n");
    printArray(sorted, n);

    //asking the user if they want to sort again
    printf("Mau sorting lagi? [Y/N]: ");
    scanf(" %c", &rpt);

} while (rpt == 'Y' || rpt == 'y'); // continue sorting if user inputs 'Y' or 'y'

return 0;
}