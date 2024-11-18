/*
Вывести двоичное представление целого положительного числа,
используя битовые операции (число вводится с клавиатуры).
*/

#include <stdio.h>
int main() {
    int number;
    int check;
    printf("enter a positive intager\n");
    check = scanf("%d", &number);
    if (check == 1 && number > 0) { // case 1
        int size = sizeof(number) * 8;
        int leading_zeroes = 1;
        printf("binary view of %d is: ", number);
        for (int i = size - 1; i >= 0; i--) {
            if (number & (1U << i)) {
                printf("1");
                leading_zeroes = 0;
            } else if (!leading_zeroes)
                printf("0");
        }
        printf("\n");
    } else if (check == 1 && number == 0) { // case 2
        printf("binary view of 0 is: 0");
        return 0;
    } else {
        printf(
            "are you blind or what?\ntry again and enter a positive number\n");
    }
    return 0;
}