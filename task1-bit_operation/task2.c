/*
Вывести двоичное представление целого отрицательного числа,
используя битовые операции (число вводится с клавиатуры).
*/

#include <stdio.h>

int main() {
    int number;
    int check;

    printf("insert negative intager:\n");
    check = scanf("%d", &number);

    if (check == 1 && number < 0) {
        int size = sizeof(number) * 8;
        int step = 0;

        unsigned int unsigned_number = (unsigned int)number;

        printf("binary view of %d is: ", number);
        for (int i = size - 1; i >= 0; i--) {
            if (unsigned_number & (1U << i)) {
                printf("1");
                step++;
                if (step == 4) {
                    printf(" ");
                    step = 0;
                }
            } else {
                printf("0");
                step++;
                if (step == 4) {
                    printf(" ");
                    step = 0;
                }
            }
        }
        printf("\n");
    } else if (check == 1 && number == 0) {
        printf("binary view of %d is: 0\n", number);
        return 0;
    } else {
        printf("huh? can't you read? insert negative intager.\n");
    }

    return 0;
}
