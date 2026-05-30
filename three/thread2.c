#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

#define N 4

typedef struct {
    int id;
    char **lines;
}ThreadData;

// функция для 5 задания
void message(void *arg){
    int id = *(int*)arg; // разыменовываем указатель с явным приведением к int
    printf("Завершение потока %d\n", id);
}

void *print_seq(void *arg){
    ThreadData *data = (ThreadData*)arg;
    int id = *(int*)arg;
    pthread_cleanup_push(message, &id); // 5 задание: зарегали ф-ию message в стек обработчиков
    for (int i=0; i < 3; i++){
        printf("Поток %d: %s\n", data->id, data->lines[i]);
        sleep(1); // 4 задание: сон на 1 сек
    }
    pthread_cleanup_pop(0); // удаляет из стека ф-ию
    return NULL;
}
int main(void) {
    pthread_t tid[4];
    ThreadData data[4];
    char *seq[4][3] = {
        {"1", "2", "3"},
        {"a", "b", "c"},
        {"яблоко", "груша", "банан"},
        {"лев", "тигр", "гепард"}
    };
    for (int i=0; i < 4; i++){
        data[i].id = i + 1;
        data[i].lines = seq[i];
        pthread_create(&tid[i], NULL, print_seq, &data[i]);
    }
    sleep(2); // 4 задание: перед прерыванием сон на 2 секунды
    for (int i = 0; i < 4; i++) {
        pthread_cancel(tid[i]); // 4 задание: прерываем работу всех дочек
        // после отмены срабатывает функция из pthread_cleanup_push
        pthread_join(tid[i], NULL);
    }
}