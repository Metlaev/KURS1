#include <stdio.h>
#include <string.h>

// Проблема: number.num != 1025?

typedef struct {
    char str[5]; // изменил количество элементов 
    int num;
} NumberRepr;

void format(NumberRepr* number) {
    sprintf(number->str, "%3d", number->num);
}

int main() {
    NumberRepr number;
    number.num = 1025;
    format(&number);
    printf("str: %s\n", number.str);
    printf("num: %d\n", number.num);
    return 0;
}