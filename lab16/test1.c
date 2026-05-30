#include <stdio.h>
#include <stdlib.h>

// Скомпилируй и запусти меня

void init(int *arr, int n) {
    arr = malloc(n * sizeof(int)); // перенёс сюда выделение памяти, так как после выхода из функции адрес не сохраняется

    for (int i = 0; i < n; ++i) { 
        arr[i] = i;    
    }
    n = 5;
}

int main() {
    int *arr = NULL;
    int n = 10;

    init(arr, n);
    // n = ?
    for (int i = 0; i < n; ++i) {
        printf("%d\n", arr[i]);
    }
    free(arr);
    return 0;
}