#include <stdio.h>
int main(){

int N;
int value = 1;
while (1){ //ПРОВЕРКА N ОТ 1 ДО 3
    printf("Введите желаемый размер квадратной матрицы от 1 до 3: \n");
    scanf("%d", &N);
    if (N == 1 || N == 2 || N == 3){
    break;
    } else{
    printf("Введено некорректное число \n");
    continue;
    }
}
printf("\n");
// ввожу матрицу
int matrix[N][N];
for (int i = 0; i < N; i++){
    for (int j = 0; j < N; j++){
        matrix[i][j] = value++; // использую value++ (постфиксный инкремент), чтобы сначала записать в элемент матрицы значение матрицы, а после прибавить 1 к value
    }
    
}
printf("Матрицы %d x %d: \n", N, N);
for (int i = 0; i < N; i++){
    for (int j = 0; j < N; j++){
        printf("%d ", matrix[i][j]);
    }
    printf("\n");
}
// считаю определители крамером
if (N == 3){
    int det3 = matrix[0][0] * matrix[1][1] * matrix[2][2] +
               matrix[0][2] * matrix[1][0] * matrix[2][1] +
               matrix[2][0] * matrix[0][1] * matrix[1][2] -
               matrix[0][2] * matrix[1][1] * matrix[2][0] -
               matrix[0][1] * matrix[1][0] * matrix[2][2] -
               matrix[0][0] * matrix[1][2] * matrix[2][1];
    printf("Определитель матрицы %d x %d = %d\n", N, N, det3);
    if (det3 == 0){
        printf("Решений нет\n");
    }
}
if (N == 2){
    int det2 = matrix[0][0] * matrix[1][1] -
               matrix[0][1] * matrix[1][0];
    printf("Определитель матрицы %d x %d = %d\n", N, N, det2);
    if (det2 == 0){
        printf("Решений нет\n");
    }

}
if (N == 1){ printf("Определитель матрицы %d x %d = %d\n", N, N, N); 
    if (N == 0){
        printf("Решений нет\n");
    }
}

}