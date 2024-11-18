// Вывести квадратную матрицу по заданному N
#include <stdio.h>
int main(void) {
    int size;
    scanf("%d", &size);
    if (size <= 0) {
        printf("matrix must be more then zero!\n");
        return 1;
    } else {
        int arr[size][size];
        int value = 1;
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                arr[i][j] = value;
                value++;
            }
        }

        printf("matrix:\n");
        for (size_t i = 0; i < size; i++) {
            for (size_t j = 0; j < size; j++) {
                printf("%d ", arr[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}