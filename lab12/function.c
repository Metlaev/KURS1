#include "header.h"

// Массив структур, который содержит все возможные варианты оружия
Weapon weaponCatalog[MAX_WEAPONS] = {
    {"Iron Sword", "Weapon", 15, "Common"},
    {"Mace", "Weapon", 10, "Common"},
    {"Grenade", "Weapon", 20, "Legendary"},
    {"Truth Stick", "Weapon", 1, "Strange"},
    {"Saw", "Weapon", 2, "Unusual"},
};

//Функция возвращает случайную структуру из массива
Weapon RandomWeapon(){
    int index = rand() % MAX_WEAPONS;
    return weaponCatalog[index];
}

// Функция выводит заданное количество оружий в инвентаре 
void PrintTable(Weapon weapons[], int size){
    printf("\n-------------------------------------------------------\n");
    printf("|  №  | Название         | Тип    | Вес | Редкость    |\n");
    printf("-------------------------------------------------------\n");
    
    for (int i = 0; i < size; i++){
        // Обрезаем название, если оно слишком длинное
        char shortName[17];
        strncpy(shortName, weapons[i].name, 16);
        shortName[16] = '\0';
        
        printf("| %-3d | %-16s | %-6s | %-3d | %-11s |\n", i + 1, shortName, weapons[i].type, weapons[i].weight, weapons[i].rarity);
    }
    
    printf("-------------------------------------------------------\n");
}

void selectSort(Weapon weapons[], int n) { // функция прямой сортировки
    for (int i = 0; i < n - 1; i++) {
        int min_i = i;
        for (int j = i + 1; j < n; j++) {
            if (weapons[j].weight < weapons[min_i].weight){
                min_i = j;
            }
        }
        if (min_i != i) { // проверка: поменялся ли элемент вообще. Если были фиктивные перестановки, то они удаляются из Mf, поэтому Mf < Mt
            Weapon temp = weapons[i]; // переменная для перестановки двух элементов массива между собой
            weapons[i] = weapons[min_i];
            weapons[min_i] = temp;
        }
    }
}

void SortTime(Weapon weapons[], int n) {
    struct timeval start, end;
    //Из чего состоит эта структура
    //struct timeval {
    //time_t      tv_sec;   // секунды с 1 января 1970 года
    //suseconds_t tv_usec;  // микросекунды (0-999999)};

    gettimeofday(&start, NULL);
    selectSort(weapons, n);
    gettimeofday(&end, NULL);

    long seconds = end.tv_sec - start.tv_sec;
    long microseconds = end.tv_usec - start.tv_usec;

    if (microseconds < 0){
        seconds -=1;
        microseconds += 1000000;
    }

    double elapsed = seconds + microseconds * 1e-6;
    printf("Сортировка %d элементов: %.6f сек\n", n, elapsed);
    printf("  (сек: %ld, мкс: %ld)\n", seconds, microseconds);

}