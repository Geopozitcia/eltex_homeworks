#include "calc.h"
#include <stdio.h>

int div(int a, int b) {
    if (b == 0) {
        printf("Division by zero error!\n");
        return 1;
    }
    return a / b;
}