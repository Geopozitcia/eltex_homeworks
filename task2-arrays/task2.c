#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int size = 0;
    printf("enter array's size:\n");
    scanf("%d", &size);

    int arr[size];

    for (int i = 0; i < size; ++i) {
        printf("enter value of %d element:\n", i);
        scanf("%d", &arr[i]);
    }

    int start = 0;
    int end = size - 1;

    while (start < end) {
        swap(&arr[start], &arr[end]);
        ++start;
        --end;
    }

    printf("reverse array:\n");
    for (int i = 0; i < size; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}