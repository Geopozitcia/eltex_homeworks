#include "calc.h"
#include <stdio.h>

int main() {
    int choice, a, b, result;

    while (1) {
        printf("\nМеню:\n");
        printf("1) Сложение\n");
        printf("2) Вычитание\n");
        printf("3) Умножение\n");
        printf("4) Деление\n");
        printf("5) Выход\n");
        printf("Выберите операцию: ");
        scanf("%d", &choice);

        if (choice == 5) {
            break;
        }

        printf("Введите два числа: ");
        scanf("%d %d", &a, &b);

        switch (choice) {
        case 1:
            result = add(a, b);
            printf("Результат: %d\n", result);
            break;
        case 2:
            result = sub(a, b);
            printf("Результат: %d\n", result);
            break;
        case 3:
            result = mul(a, b);
            printf("Результат: %d\n", result);
            break;
        case 4:
            result = div(a, b);
            if (b != 0) {
                printf("Результат: %d\n", result);
            }
            break;
        default:
            printf("Некорректный выбор!\n");
        }
    }

    return 0;
}