/*
Поменять  в  целом  положительном  числе  (типа  int)  значение  третьего
байта  на введенное  пользователем  число  (изначальное  число  также
вводится  с  клавиатуры)  через  указатель  (не  применяя  битовые
операции).
*/

#include <stdio.h>

#include <stdio.h>
#include <stdlib.h>

void change_third_byte(int *num, unsigned char new_value) {
    unsigned char *byte_ptr = (unsigned char *)num;
    byte_ptr[2] = new_value;
}

int main() {
    int number;
    unsigned char new_byte;
    char input_buffer[100];

    printf("insert integer: ");
    if (!fgets(input_buffer, sizeof(input_buffer), stdin) ||
        sscanf(input_buffer, "%d", &number) != 1 || number < 0) {
        printf("wrong input.\n");
        return 1;
    }

    printf("new 3-rd byte: ");
    if (!fgets(input_buffer, sizeof(input_buffer), stdin) ||
        sscanf(input_buffer, "%hhu", &new_byte) != 1) {
        printf("from 0 to 255!.\n");
        return 1;
    }
    change_third_byte(&number, new_byte);

    printf("result: %d\n", number);

    return 0;
}