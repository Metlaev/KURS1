#ifndef ANAGRAM_H
#define ANAGRAM_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <wchar.h>

void swap (wchar_t *x, wchar_t *y);
void permute(wchar_t *str, int l, int r, long long *count);

#endif // ANNAGRAMM_H