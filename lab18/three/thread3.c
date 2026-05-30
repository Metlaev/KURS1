#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

void *sleepSort(void *arg){
    long val = (long)arg; // обратно делаю его лонг
    usleep(val * 10000);

    printf("%ld ", val);
    fflush(stdout);
    return NULL;
}

int main (){
    int array[] = {12, 4, 3, 9, 1, 5, 8, 2};
    int n = sizeof(array) / sizeof(array[0]);
    pthread_t tid[n];

    printf("Исходный массив: ");
    for (int i=0;i<n;i++){
        printf("%d ", array[i]);
    }

    printf("Отсортированный массив: ");
    
    for (int i=0; i<n; i++){
        pthread_create(&tid[i], NULL, sleepSort, (void*)(long)array[i]); // преобразовали число в лонг, а потом замаскировали под указатель
    }
    for (int i=0; i<n; i++){
        pthread_join(tid[i], NULL);
    }
}