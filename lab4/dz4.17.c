#include <stdio.h>
int main(){
unsigned int a;
printf("Введите число а > 0: \n");
scanf("%d", &a);
unsigned int result = 0;
unsigned int i = 1;
while (a > 0) {
    unsigned int triad = a & 7;
    result += triad * i;
    a = a >> 3;
    i = i * 10;
    }
printf("%d\n", result);
return 0;
}