#include <stdio.h>

// 1) Binary Search


int binary_search(int arr[], int n, int target) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == target) return mid;
        else if (arr[mid] < target) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}





// 2) Bubble Sort


void bubble_sort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}




// 3) Missing Number


int find_missing_number(int arr[], int n) {
    int total = (n + 1) * (n + 2) / 2;
    for (int i = 0; i < n; i++) total -= arr[i];
    return total;
}

int main() {
    // Binary Search Example
    int arr1[] = {11, 12, 22, 25, 34, 64, 90};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    int idx = binary_search(arr1, n1, 25);
    if (idx != -1) printf("Binary Search: Found at index %d\n", idx);
    else printf("Binary Search: Not found\n");

    // Bubble Sort Example
    int arr2[] = {64, 34, 25, 12, 22, 11, 90};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    bubble_sort(arr2, n2);
    printf("Bubble Sort: ");
    for (int i = 0; i < n2; i++) printf("%d ", arr2[i]);
    printf("\n");

    // Missing Number Example
    int arr3[] = {1, 2, 3, 5, 6};
    int n3 = sizeof(arr3) / sizeof(arr3[0]);
    printf("Missing Number: %d\n", find_missing_number(arr3, n3));

    return 0;
}