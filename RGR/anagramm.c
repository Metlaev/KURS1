#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <wchar.h>
#include "anagramm.h"

// функция для обмена значениями двух символов
void swap(wchar_t *x, wchar_t *y) {
    wchar_t temp = *x;
    *x = *y;
    *y = temp;
}

// рекурсивная функция для генерации и вывода перестановок
void permute(wchar_t *str, int l, int r, long long *count) {
    if (l == r) {
        printf("%ls\n", str);
        (*count)++;
    } else {
        for (int i = l; i <= r; i++) {
            swap(&str[l], &str[i]);
            permute(str, l + 1, r, count);
            swap((str + l), (str + i)); // возвращаем обратно слово
        }
    }
}
