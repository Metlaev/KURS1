#include <stdio.h>  
void swap(int* arr, int i, int j) {  
    int temp = arr[i];  
    arr[i] = arr[j];  
    arr[j] = temp;  
}  
void bubbleSort(int arr, int n) {  
    for (int i = 0; i < n - 1; i++) {  
        for (int j = 0; j < n - i - 1; j++) {  
            if (arr[j] > arr[j + 1]) {  
                swap(&arr[j], &arr[j + 1]);  
            }  
        }  
    }  
}
int main() {
    int a[] = {4, 2};
    bubbleSort(a, 3);
} 
comment out
comment 2

