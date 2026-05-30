#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

#define N 4

void *routine(void *_){
    for (int i=0; i < N; i++){
        printf("thread: i=%d\n", i);
        sleep(2);
    }
    return NULL;
}
int main(void) {
    pthread_t tid;
    pthread_create(&tid, NULL, routine, NULL); // атрибуты по умолчанию
    pthread_join(tid, NULL); // переместил сюда, чтобы родительский поток выводил \
                                текст после завершения дочернего
    for (int i=0; i < N; i++){
        printf("main procces: i=%d\n", i);
        sleep(1);
    }
    //pthread_join(tid, NULL) был здесь до 2 задания
}