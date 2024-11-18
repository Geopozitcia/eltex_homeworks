#include <stdio.h>

int main() {
    int number;
    int third_byte_value;
    int check;

    printf("Insert a positive integer:\n");
    check = scanf("%d", &number);
    if (check != 1 || number < 0) {
        printf("Please insert a POSITIVE INTEGER!\n");
        return 1;
    }

    printf("Insert third byte value from 0 to 255:\n");
    check = scanf("%d", &third_byte_value);
    if (check != 1 || third_byte_value < 0 || third_byte_value > 255) {
        printf("You should insert a number from 0 to 255 (1111 1111 in "
               "binary).\n");
        return 1;
    }

    int mask = 0xFF << (2 * 8);
    number &= ~mask;
    number |= (third_byte_value & 0xFF) << (2 * 8);

    printf("Resulting number: %d\n", number);
    return 0;
}