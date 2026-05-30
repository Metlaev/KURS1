#include <stdio.h>
#include <stdlib.h>

typedef struct {
 char name[50]; // имя комнаты
 int level; // уровень/сложность комнаты
 int number; // номер комнаты
 int resolution; // размер комнаты
} room;

typedef struct node {
    room data;
    struct node *next;
} node;

node *newNode(room r_data){
    node *new_node = (node *)malloc(sizeof(node));

    new_node->data = r_data;
    new_node->next = NULL;
    
    return new_node;
}
void printList(node *head){

    node *cur = head;
    while (cur != NULL){
        printf("%s -> ", cur->data.name);
        cur = cur->next;
    }
    printf("NULL\n");
}

int main(){
    int n = 1;
    node *head = NULL;
    printf("Введите n: ");
    scanf("%d", &n);

    room s1 = {"dungeon", 1, 2, 34};
    room s2 = {"boss", 1, 2, 24};

    node *n1 = newNode(s1);
    node *n2 = newNode(s2);

    n1->next = n2; // связал 1 узел со вторым

    head = n1;

    printf("Комната 1: %s, %d, %d, %d\n", 
        n1->data.name, n1->data.level, n1->data.number, n1->data.resolution);
    printf("Комната 2: %s, %d, %d, %d\n", 
        n1->next->data.name, n1->next->data.level, n1->next->data.number, n1->next->data.resolution);
    printList(head);
    free(n1); free(n2);
    return 0;
}