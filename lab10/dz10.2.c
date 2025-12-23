#include "dz10.3.h"
int print_point(struct Point *p1, struct Point *p2){
    printf("Введите координаты первой точки: ");
    scanf("%d %d", &p1->x, &p1->y);
    printf("Введите координаты второй точки: ");
    scanf("%d %d", &p2->x, &p2->y);
    printf("Координаты точки p1: x=%d, y=%d \n", p1->x, p1->y);
    printf("Координаты точки p2: x=%d, y=%d \n", p2->x, p2->y);
}
int is_parall(struct Point p1, struct Point p2){
    if (p1.x == p2.x){
        printf("Прямая параллельна оси абсцисс\n");
    }
    if (p1.y == p2.y){
        printf("Прямая параллельна оси ординат\n");
    }
}