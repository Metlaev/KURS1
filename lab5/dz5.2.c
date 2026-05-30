#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int isPrime(int x){
    if (x < 2) return 0;
    if (x == 2 || x == 3) return 1;
    if (x % 2 == 0) return 0;

    for(int i = 3; i * i <= x; i++){
        if (x % i == 0){
            return 0;
        }
    }
    return 1;
}
double arifm(int arr[], int size){
    double sum = 0;
    for (int i = 0; i < size; i++){
        sum += arr[i];
    }
    return sum / size;
}

int main(){
int n;
srand(time(NULL));
printf("Введите количество символов для массива X: ");
scanf("%d", &n);
int X[n];
int cnt_X = 0;
for (int i = 0; i < n; i++){
    X[i] = rand() % 1000;
    if (isPrime(X[i])){
        cnt_X += 1;
    }
    printf("%d ", X[i]);
}
printf("\n");

int Y[n];
int cnt_Y = 0;
for (int i = 0; i < n / 2; i++){
    Y[i] = X[i * 2 + 1];
    if (isPrime(Y[i])){
        cnt_Y += 1;
    }
    printf("%d ", Y[i]);    
}

printf("\n");
printf("Количество простых числе в массивах X и Y соответственно:%d %d \n", cnt_X, cnt_Y);
printf("Среднее арифм в массивах X и Y соответственно:%lf %lf \n", arifm(X, n), arifm(Y, (n/2)));
}