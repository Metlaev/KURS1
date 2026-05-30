#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    int id;
    char level[10];
} Employee;

void save_to_databin(Employee *employees, int count, const char *filename){ // передаю структуру, количество сотрудников и имя файла
    FILE *db_file = fopen(filename, "wb"); // открываю файл
    if (db_file == NULL){
        perror("error opening file");
        return;
    }

    // Записываю количество сотрудников
    fwrite(&count, sizeof(int), 1, db_file);
    size_t written = fwrite(employees, sizeof(Employee), count, db_file);
    fclose(db_file);
    
    if (written == count){
        printf("Сохранено %d записей в файл %s\n", count, filename);
    } else {
        printf("Ошибка! Не всё записано\n");
    }
}

void search_employee(const char *filename){
    FILE *db_read = fopen(filename, "rb");
    if (db_read == NULL){
        perror("Ошибка открытия файла database.dat на чтение");
        exit(1);
    }

    // читаем количество записей
    int count;
    fread(&count, sizeof(int), 1, db_read);

    if (count == 0){
        printf("файл базы данных пуст\n");
        fclose(db_read);
        return;
    }

    int search_id;
    printf("\nВведите ID сотрудника:\n");
    scanf("%d", &search_id);
    
    Employee emp;
    int found = 0;

    for (int i = 0; i < count; i++){
        fread(&emp, sizeof(Employee), 1, d
        b_read);
        if (emp.id == search_id){
            found = 1;
           printf("\n :) СОТРУДНИК НАЙДЕН!\n");
           printf("Имя:   %-30s\n", emp.name);
           printf("Id:   %-30d\n", emp.id);
           printf("Уровень:   %-30s\n", emp.level);
           break;
        }
    }
    
    if (found == 0){
        printf("\n :( СОТРУДНИК НЕ НАЙДЕН!\n");
    }
    fclose(db_read);
}

int main(int argc, char *argv[]){

if (argc < 2){
    printf("Передан всего 1 аргумент: %s\n", argv[0]);
    return 1;
}

FILE *file;
file = fopen(argv[1], "r"); // открываю файл из 2 аргумента
if (file == NULL){
    perror("error opening file");
    exit(1);
}
FILE *db_dat = fopen("database.dat", "wb"); // открываю бинарный файл b для записи w
if (db_dat == NULL){
    perror("error opening file");
    exit(1);
}

char buffer[256];
char name[50];
int id;
char level[10];
Employee emp;

Employee *employees = NULL;
int employee_count = 0;
int capacity = 10;

employees = malloc(capacity * sizeof(Employee));
if (employees == NULL){
    printf("Ошибка выделения память\n");
    fclose(file);
    return 1;
}

//записываю 0 в начало файла, чтобы зарезервировать место для записей
// fwrite(&employee_count, sizeof(int), 1, db_dat);

//Печатаю таблицу
printf("%-20s %-10s %-10s\n", "Имя", "ID", "Уровень");
printf("%-20s %-10s %-10s\n", "--------------------", "----------", "----------");

while (fgets(buffer, sizeof(buffer), file)){ //получаем строку
    int count = sscanf(buffer, "%[^;];%d;%s", name, &id, level);
    printf("%-20s %-10d %-10s\n", name, id, level);
    
    if (count == 3){
        // Заполняем структуру
        strcpy(employees[employee_count].name, name);
        employees[employee_count].id = id;
        strcpy(employees[employee_count].level, level);
        
        employee_count++; // увеличиваем счётчик сотрудников
        if (employee_count >= capacity){
            capacity *= 2;
            employees = realloc(employees, capacity * sizeof(Employee));
        }
    }

}

fclose(file);
// fseek(db_dat, 0, SEEK_SET); //перемещаем указатель в начало файла
// fwrite(&employee_count, sizeof(int), 1, db_dat); //заместо нуля пишем номер сотрудника
// fclose(file);
// fclose(db_dat);
printf("\nВсего прочитано сотрудников: %d\n", employee_count);
save_to_databin(employees, employee_count, "database.dat");
free(employees);
// открываем бинарный файл для чтения
FILE *db_read = fopen("database.dat", "rb");
if (db_read == NULL){
    perror("Ошибка открытия файла database.dat на чтение");
    exit(1);
}

int count; // переменная для хранения количества записей
fread(&count, sizeof(int), 1, db_read); // читаем первое число
printf("\nКоличество записей в файле: %d\n", count);

for (int i = 0; i < count; i++){
    fread(&emp, sizeof(Employee), 1, db_read); // читаем каждую структуру
    printf("%d. %s, %d, %s\n", i+1, emp.name, emp.id, emp.level);
}
fclose(db_read);

printf("\n=== ПОИСК СОТРУДНИКА ===\n");
    search_employee("database.dat");
return 0;
}