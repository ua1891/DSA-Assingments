#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i;
    int *arr;

    // 1. Takes n from user
    printf("Enter the number of elements: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid input. Please enter a positive integer.\n");
        return 1;
    }

    // 2. Dynamically allocates array using malloc
    arr = (int*)malloc(n * sizeof(int));
    
    // Check if memory allocation was successful
    if (arr == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    // 3. Stores n integers
    printf("Enter %d integers:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // 4. Resizes array using realloc (double size)
    // We use a temporary pointer to avoid memory leaks if realloc fails
    int *temp = (int*)realloc(arr, 2 * n * sizeof(int));
    if (temp == NULL) {
        printf("Memory reallocation failed.\n");
        free(arr); // Free the original memory before exiting
        return 1;
    }
    arr = temp; // Update arr to point to the new memory block
    printf("Array successfully resized to hold %d integers.\n", 2 * n);

    // 5. Frees memory safely
    free(arr);
    arr = NULL; // Set pointer to NULL to prevent dangling pointer usage
    return 0;
}