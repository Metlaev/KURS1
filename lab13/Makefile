.PHONY: clean # нужна, чтобы цель clean работала, даже если уже есть файл с таким именем

all: main # при выполнении команды make без флагов будет выполняться эта цель
libutil.a: function.o
	ar rc libutil.a function.o

main.o: app/main.c # компилируем исходный файл и получаем объектные файлы
	gcc -c app/main.c -o main.o -I ./include

function.o: src/function.c # компилируем исходный файл и получаем объектные файлы
	gcc -c src/function.c -o function.o -I ./include

main: main.o libutil.a # цель должна создать исполняемый файл, если найдёт объектные файлы
	gcc -o main main.o -L. -lutil	

clean: # не имеет зависимостей и удаляет все объектные файлы и исполняемый файл, полученные во время сборки
	rm -f *.o main
	
run: all # цель, которая запускает исполняемый файл
	./main