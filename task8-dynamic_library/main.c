#include "calc.h"
#include <dlfcn.h>
#include <stdio.h>

int main() {
    void *handle;
    int (*add)(int, int), (*sub)(int, int), (*mul)(int, int), (*div)(int, int);
    int choice, a, b, result;

    handle = dlopen("./libcalc.so", RTLD_LAZY);
    if (!handle) {
        fprintf(stderr, "Ошибка при загрузке библиотеки: %s\n", dlerror());
        return 1;
    }

    add = dlsym(handle, "add");
    sub = dlsym(handle, "sub");
    mul = dlsym(handle, "mul");
    div = dlsym(handle, "div");

    if (!add || !sub || !mul || !div) {
        fprintf(stderr, "Ошибка при загрузке функций: %s\n", dlerror());
        dlclose(handle);
        return 1;
    }

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

    dlclose(handle);
    return 0;
}