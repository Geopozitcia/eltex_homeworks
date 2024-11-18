// Заполнить верхний треугольник матрицы '0'
#include <stdio.h>
int main() {
    int size = 0;
    printf("matrix size?\n");
    scanf("%d", &size);

    int matrix[size][size];

    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (j >= size - i - 1) {
                matrix[i][j] = 1;
            } else {
                matrix[i][j] = 0;
            }
        }
    }

    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}