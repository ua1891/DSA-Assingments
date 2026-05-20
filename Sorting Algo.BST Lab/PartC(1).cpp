#include<iostream>
using namespace std;

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}
void OptimizeSorting(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        bool shifted = false;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
            shifted = true;
        }

        arr[j + 1] = key;

        if (!shifted) {
            continue;
        }
    }
}
int binarySearch(int arr[], int item, int low, int high) {
    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] <= item)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return low;
}
void binaryInsertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];

        int pos = binarySearch(arr, key, 0, i - 1);
        
        int j = i - 1;
        while (j >= pos) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[pos] = key;
    }
}
int main() {
    int arr[] = {12, 11, 13, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    insertionSort(arr, n);
    cout << "Sorted array using Insertion Sort: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    int arr2[] = {12, 11, 13, 5, 6};
    OptimizeSorting(arr2, n);
    cout << "Sorted array using Optimized Insertion Sort: ";
    for (int i = 0; i < n; i++)
        cout << arr2[i] << " ";
    cout << endl;

    int arr3[] = {12, 11, 13, 5, 6};
    binaryInsertionSort(arr3, n);
    cout << "Sorted array using Binary Insertion Sort: ";
    for (int i = 0; i < n; i++)
        cout << arr3[i] << " ";
    cout << endl;

    return 0;
}