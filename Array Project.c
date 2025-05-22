// Simple Array Operations: Insert, Update, Delete, Search, Display, Sort
//Here, variables...n=size; pos=position;

#include <stdio.h>

// Function
void insert(int arr[], int *n, int val, int pos);
void update(int arr[], int n, int pos, int newVal);
void delete(int arr[], int *n, int pos);
int search(int arr[], int n, int val);
void show(int arr[], int n);
void sort(int arr[], int n);

int main() {
    int arr[100];
    int n = 0, choice, val, pos;

    printf("How many elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    do {
        printf("\nMenu:\n");
        printf("1. Insert\n");
        printf("2. Update\n");
        printf("3. Delete\n");
        printf("4. Search\n");
        printf("5. Display\n");
        printf("6. Sort\n");
        printf("7. Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value and position: ");
                scanf("%d%d", &val, &pos);
                insert(arr, &n, val, pos);
                break;
            case 2:
                printf("Enter position and new value: ");
                scanf("%d%d", &pos, &val);
                update(arr, n, pos, val);
                break;
            case 3:
                printf("Enter position to delete: ");
                scanf("%d", &pos);
                delete(arr, &n, pos);
                break;
            case 4:
                printf("Enter value to search: ");
                scanf("%d", &val);
                pos = search(arr, n, val);
                if (pos != -1)
                    printf("Found at position: %d\n", pos);
                else
                    printf("Not found.\n");
                break;
            case 5:
                show(arr, n);
                break;
            case 6:
                sort(arr, n);
                printf("Array sorted.\n");
                break;
            case 7:
                printf("Exiting.\n");
                break;
            default:
                printf("Invalid option.\n");
        }

    } while (choice != 7);

    return 0;
}

// Insert value at given position
void insert(int arr[], int *n, int val, int pos) {
    if (pos < 0 || pos > *n) {
        printf("Invalid position.\n");
        return;
    }

    for (int i = *n; i > pos; i--) {
        arr[i] = arr[i - 1];
    }
    arr[pos] = val;
    (*n)++;
}

// Update value at given position
void update(int arr[], int n, int pos, int newVal) {
    if (pos < 0 || pos >= n) {
        printf("Invalid position.\n");
        return;
    }

    arr[pos] = newVal;
}

// Delete value at given position
void delete(int arr[], int *n, int pos) {
    if (pos < 0 || pos >= *n) {
        printf("Invalid position.\n");
        return;
    }

    for (int i = pos; i < *n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    (*n)--;
}

// Searching for vale in the array
int search(int arr[], int n, int val) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == val)
            return i;
    }
    return -1;
}

// Displaying the array
void show(int arr[], int n) {
    printf("Current array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Sorting the array
void sort(int arr[], int n) {
    int temp;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] > arr[j]) {
                // swap
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}
