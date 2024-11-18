// спиральное заполнение матрицы
#include <stdio.h>

int main() {
    int size;
    printf("matrix size?:\n");
    scanf("%d", &size);

    int matrix[size][size];
    int num = 1;
    int top = 0, bottom = size - 1;
    int left = 0, right = size - 1;

    while (num <= size * size) {
        for (int i = left; i <= right && num <= size * size; ++i) {
            matrix[top][i] = num++;
        }
        top++;

        for (int i = top; i <= bottom && num <= size * size; ++i) {
            matrix[i][right] = num++;
        }
        right--;

        for (int i = right; i >= left && num <= size * size; --i) {
            matrix[bottom][i] = num++;
        }
        bottom--;

        for (int i = bottom; i >= top && num <= size * size; --i) {
            matrix[i][left] = num++;
        }
        left++;
    }

    printf("result:\n");
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            printf("%2d ", matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}