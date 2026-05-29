#include<iostream>
using namespace std;
void PrintArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
void Bubblesort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}
void OptimizedBubbleSort(int arr[], int n) {
    bool swapped;
    for (int i = 0; i < n - 1; i++) {
        swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) {
            break;
        }
    }
}
int main(){
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Original array: ";
    PrintArray(arr, n);
    Bubblesort(arr, n);
    cout << "Sorted array: ";
    PrintArray(arr, n);
        int arr2[] = {64, 34, 25, 12, 22, 11, 90};
    cout << "Original array: ";
    PrintArray(arr2, n);
    OptimizedBubbleSort(arr2, n);
    cout << " After Optimization Sorted array: ";
    PrintArray(arr2, n);

    return 0;
}