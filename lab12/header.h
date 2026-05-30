#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>
#include <string.h>


#define N 10
#define MAX_WEAPONS 5

typedef struct {
    char name[50];
    char type[50];
    int weight;
    char rarity[25];
} Weapon;

// Убрали: extern Weapon weaponCatalog[MAX_WEAPONS];

Weapon RandomWeapon();
void PrintTable(Weapon weapons[], int size);
void selectSort(Weapon weapons[], int n);
void SortTime(Weapon weapons[], int n);

#endif