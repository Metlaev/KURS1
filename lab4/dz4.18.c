#include <stdio.h>
int main(){

int reverse_numbers(int num){
    while (num > 0){
        
    }
}
unsigned int a;
printf("Введите положительное a: \n");
scanf("%d", &a);
unsigned int result = 0;
unsigned int i = 1;
while(a > 0){
    unsigned int tetrad = a & 15;
    result += tetrad * i;
    a = a >> 4;
    i = i * 10;
    printf("%x", tetrad);
    }
printf("\nВаше число в шестнадцатеричной записи: %d", result);
return 0;
}
