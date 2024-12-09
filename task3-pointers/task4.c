/*
Напишите программу,
    которая ищет введенной строке(с клавиатуры) введенную
    подстроку(с клавиатуры) и возвращает указатель на начало подстроки,
    если подстрока не найдена в указатель
    записывается NULL.В качестве срок использовать статические массивы.ю
*/

#include <stdio.h>
#include <string.h>

#define MAX_SIZE 100
int main() {
    char str[MAX_SIZE];
    char substr[MAX_SIZE];

    printf("insert string: ");
    if (!fgets(str, MAX_SIZE, stdin)) {
        printf("wrong string.\n");
        return 1;
    }

    str[strcspn(str, "\n")] = '\0';

    printf("insert substring: ");
    if (!fgets(substr, MAX_SIZE, stdin)) {
        printf("wrong substring.\n");
        return 1;
    }
    substr[strcspn(substr, "\n")] = '\0';

    char *result = strstr(str, substr);

    if (result != NULL) {
        printf("substring starts in: \"%s\"\n", result);
    } else {
        printf("there is not requsted substing in example\n");
    }

    return 0;
}