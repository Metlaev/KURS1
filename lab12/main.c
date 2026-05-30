#include "header.h"

int main(){
    srand(time(NULL));
    
    // Массив для демонстрации
    Weapon weapons[N];
    for (int i=0; i<N; i++){
        weapons[i] = RandomWeapon();
    }
    
    // Размеры для тестирования
    int test_sizes[] = {10000,100000};
    int num_tests = sizeof(test_sizes) / sizeof(test_sizes[0]);
    
    for (int t = 0; t < num_tests; t++) {
        int size = test_sizes[t];
        printf("Тест на %d элементах\n", size);
        
        // test array - это указатель на адрес начала массива
        Weapon* test_array = malloc(size * sizeof(Weapon));
        
        // Заполнение массива
        for (int i = 0; i < size; i++) {
            test_array[i] = RandomWeapon();
        }
        

        SortTime(test_array, size);
        
 
        free(test_array);
    }
    
    selectSort(weapons, N);
    
    printf("\nПосле сортировки:\n");
    PrintTable(weapons, N);

    return 0;
}