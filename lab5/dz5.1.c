#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
int N;
scanf("%d", &N);
int signal[N];
srand(time(NULL));
printf("Все числа: ");
for (int i = 0; i < N; i++){ // прохожусь от 0 до N и заполняю массив случайными числами в диапазоне
    signal[i] = rand() % 65536 - 32768;
    printf("%d ", signal[i]);
}
printf("\n");

int max_re = signal[0];
for (int i = 0; i < N / 2; i++) { // прохожусь от 0 до половины N (т.к всего чисел N и в каждое комплексное число входит 2 числа из N чисел)
    int re = signal[i * 2];
    if (re > max_re){
        max_re = re;
    }
    int im = signal[i * 2 + 1];
    printf("Комплексное число № %d: %d + j*%d\n", i + 1, re, im); // вывожу запись комплексных чисел и макс из real
}
printf("Максимальное реальное число: %d\n", max_re); // вывожу макс из действительных
int signal_energy = 0;
for (int k = 0; k < N/2;k++){ // считаю сумму сумм квадратов реальных и вещественных чисел комплексного числа
     
    signal_energy += signal[k * 2] * signal[k * 2] + signal[k * 2 + 1] * signal[k * 2 + 1];
}
printf("Сумма = %d\n", signal_energy);
}