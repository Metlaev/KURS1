// #include <stdio.h>

// // int replace(int n, int k, int matrica[n][k], int r){

// // int matrica[n][k] = {
// //         {7, 3, 9, 1},
// //         {5, 8, 2, 4},
// //         {9, 1, 6, 3},
// //         {2, 7, 4, 8},
// //         {4, 5, 3, 2}
// //     };

// // for (int i = 0; i < n; i++){
// //     for (int j =0; j < k-1; j++){
// //         if (matrica[i][j] > matrica[i+1][j]){
// //             r[i][j] == matrica[i][j];
// //         }
// //     }
// // }

// // for (int i = 0; i < n; i++){
// //     for (int j =0; j < k-1; j++){
// //         printf("%d", r[i][j]);
// //         }
// //     printf("\n");
// //     }

// // }
// int main(){

// // int n;
// // printf("Введите N: ");
// // scanf("%d", &n);
// // int matrix[n][n];
// // for (int i = 0; i < 5; i++){
// //     for (int j =0; j < 4; j++){
// //         scanf("%d", &matrix[i][j]);
// //     }
// // }

// int matrix = {
//         {7, 3, 9, 1},
//         {5, 8, 2, 4},
//         {9, 1, 6, 3},
//         {2, 7, 4, 8},
//         {4, 5, 3, 2}
//     };
// int r;
// int n = 5;
// int k = 4;

// for (int i = 0; i < 5; i++){
//     for (int j =0; j < 4; j++){
//         printf("%d ", matrix[i][j]);
//     }
//     printf("\n");
// }
// for (int i = 0; i < 5; i++){
//     for (int j =0; j < 4-1; j++){
//         if (matrix[i][j] > matrix[i+1][j]){
//             printf("%d > %d \n", matrix[i][0], matrix[i+1][0]);
//         };
//     }
// }

// int matrica[n][k] = {
//         {7, 3, 9, 1},
//         {5, 8, 2, 4},
//         {9, 1, 6, 3},
//         {2, 7, 4, 8},
//         {4, 5, 3, 2}
//     };

// for (int i = 0; i < n; i++){
//     for (int j =0; j < k-1; j++){
//         if (matrica[i][j] > matrica[i+1][j]){
//             r[i][j] == matrica[i][j];
//         }
//     }
// }

// for (int i = 0; i < n; i++){
//     for (int j =0; j < k-1; j++){
//         printf("%d", r[i][j]);
//         }
//     printf("\n");
//     }

// return 0;
// }
#include <stdio.h>

#define ROWS 4
#define COLS 3

int arr[COLS] = {0};
void sort_column_bubble(int matrix[ROWS][COLS], int col) {
    for (int i = 0; i < ROWS - 1; i++) {
        for (int j = 0; j < ROWS - i - 1; j++) {
            if (matrix[j][col] > matrix[j + 1][col]) {
                int temp = matrix[j][col];
                matrix[j][col] = matrix[j + 1][col];
                matrix[j + 1][col] = temp;
                arr[col]++;
            }
        }
    }
    for (int j = 0; j < COLS; j++) {
        printf("%d\n", arr[j]);

    }
}
void print_matrix(int matrix[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {

    int matrix[ROWS][COLS] = {
        {9, 2, 7},
        {1, 5, 6},
        {4, 8, 3},
        {5, 1, 2}
    };
    
    printf("Исходная матрица:\n");
    print_matrix(matrix);
    

    for (int col = 0; col < COLS; col++) {
        sort_column_bubble(matrix, col);
    }
    int min = arr[0];

    int index = 0;
    for (int i = 0; i<COLS; i++){
            if (arr[i] < min){
            min = arr[i];
            index = i;
        }
    }
    int cnt_pos = 0;
    for (int i = 0; i < ROWS; i++){
        if (matrix[i][index] > 0){
            cnt_pos += 1;
        }
        matrix[i][index] = 0;
    }
    printf("Положительные: %d\n", cnt_pos);

    printf("\nМатрица после сортировки столбцов:\n");
    print_matrix(matrix);
    
    return 0;
}