#include <stdio.h>
#include <stdlib.h>

void inputMatrix(int n, int matrix[n][n], int b[n]){
    for (int i=0; i < n; i++){
        for (int j=0; j < n; j++){
            printf("Введите элемент матрицы: ");
            scanf("%d", &matrix[i][j]);

        }
    }
    for (int i=0; i < n; i++){
        printf("Введите элемент строки B: ");
        scanf("%d", &b[i]);
    }
}

void printMatrix(int n, int matrix[n][n], int b[n]){
    printf("Матрица[%d][%d]: \n", n, n);
    for (int i=0; i<n; i++){
        for (int f=0; f<n; f++){
            printf("%d ", matrix[i][f]);
        }
    printf("\n");
    }
    printf("строка В: \n");
    for (int i=0; i < n; i++){
        printf("%d ", b[i]);
    }
    printf("\n");
    
}

int main() {
    int n;
    printf("Введите N от 1 до 3: ");
    scanf("%d", &n);
    int matrix[n][n];
    int b[n];
    inputMatrix(n, matrix, b);
    printMatrix(n, matrix, b);
    if (n == 2){
        float opr = matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
        printf("Определитель матрицы = %.2f\n", opr);
        if (opr == 0.00){
            printf("решений нет\n");
        }
        float Xopr = b[0] * matrix[1][1] - matrix[0][1] * b[1];
        printf("Определитель матрицы с заменой X = %.2f\n", Xopr) ;
        float Yopr = b[1] * matrix[0][0] - matrix[1][0] * b[0];
        printf("Определитель матрицы с заменой Y = %.2f\n", Yopr) ;

        float x = Xopr / opr;
        float y= Yopr / opr;
        printf("x = %.2f \ny = %.2f\n",x, y);
    }

    if(n == 3){
        float opr2 = matrix[0][0] * (matrix[1][1] * matrix[2][2] - matrix[1][2] * matrix[2][1]) -
        matrix[0][1] * (matrix[1][0] * matrix[2][2] - matrix[1][2] * matrix[2][0]) +
        matrix[0][2] * (matrix[1][0] * matrix[2][1] - matrix[1][1] * matrix[2][0]);

        float oprX = b[0] * (matrix[1][1] * matrix[2][2] - matrix[1][2] * matrix[2][1]) -
        matrix[0][1] * (b[1] * matrix[2][2] - matrix[1][2] * b[2]) +
        matrix[0][2] * (b[1] * matrix[2][1] - matrix[1][1] * b[2]);
        
        float oprY = matrix[0][0] * (b[1] * matrix[2][2] - matrix[1][2] * b[2]) -
        b[0] * (matrix[1][0] * matrix[2][2] - matrix[1][2] * matrix[2][0]) +
        matrix[0][2] * (matrix[1][0] * b[2] - b[1] * matrix[2][0]);

        float oprZ = matrix[0][0] * (matrix[1][1] * b[2] - b[1] * matrix[2][1]) -
        matrix[0][1] * (matrix[1][0] * b[2] - b[1] * matrix[2][0]) +
        b[0] * (matrix[1][0] * matrix[2][1] - matrix[1][1] * matrix[2][0]);
        float x = oprX / opr2;
        float y = oprY / opr2;
        float z = oprZ / opr2;
        printf("%.2f, %.2f, %.2f\n", x, y, z);
    }
}
