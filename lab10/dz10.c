#include <stdio.h>
#include <stdlib.h>

struct Point {
    int x;
    int y;
};

int print_point(struct Point *p1, struct Point *p2){ // передаю указатели на структуру, так как в теле функции я работаю с адресом
    printf("Введите координаты первой точки: \n");
    scanf("%d %d", &p1->x, &p1->y);
    printf("Введите координаты второй точки: \n");
    scanf("%d %d", &p2->x, &p2->y);
    printf("Координаты точки p1: x=%d, y=%d \n", p1->x, p1->y);
    printf("Координаты точки p2: x=%d, y=%d \n", p2->x, p2->y);
}
int is_parall(struct Point *p1, struct Point *p2){ // передаю указатели на структуру, так как в теле функции я работаю с адресом
    if (p1->x == p2->x && p1->y == p2->y) {
        printf("Координаты совпадают \n");
        return 0;
    }
    if (p1->x == p2->x){
        printf("Прямая параллельна оси ординат\n");
    }
    else if (p1->x != p2->x){
        printf("Прямая не параллельна оси ординат\n");
    }
    if (p1->y == p2->y){
        printf("Прямая параллельна оси абсцисс\n");
    }
    else if (p1->y != p2->y){
        printf("Прямая не параллельна оси абсцисс\n");
    }
}
int main(){

struct Point *z1 = malloc(sizeof(struct Point)); // инициализирую укататели, выделяя им место в памяти
struct Point *z2 = malloc(sizeof(struct Point));
print_point(z1, z2); // передаю в функцию просто имена переменных, так как они являются
is_parall(z1, z2);

}