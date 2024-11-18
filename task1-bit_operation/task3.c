/*
Найти количество единиц в двоичном представлении целого
положительного числа (число вводится с клавиатуры).
*/

#include <stdio.h>
int main() {
    int number;
    int check;
    int sum = 0;
    printf("enter a positive intager\n");
    check = scanf("%d", &number);
    if (check == 1 && number > 0) { // case 1
        int size = sizeof(number) * 8;
        for (int i = size - 1; i >= 0; i--) {
            if (number & (1U << i))
                sum++;
            else
                ;
        }
        printf("there is %d units in binary view of %d\n", sum, number);
    } else if (check == 1 && number == 0) { // case 2
        printf("there is %d units in binary view of %d\n", sum, number);
        return 0;
    } else {
        printf("maybe you should take abc book before computer?\n enter a "
               "positive number\n");
    }
    return 0;
}