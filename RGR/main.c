#include "anagramm.h"
int main(int argc, char *argv[]) {
    
    setlocale(LC_ALL, ""); // поддержка UTF-8 для корректного вывода кириллицы

    if (argc < 2) {
        printf("Ошибка: Укажите имя файла в качестве аргумента.\n");
        printf("Приведите к такому формату: %s <имя_файла>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Ошибка: Не удалось открыть файл '%s'.\n", argv[1]);
        return 1;
    }

    // буфер для чтения строки из файла
    char utf8_buffer[1024];
    if (fgets(utf8_buffer, sizeof(utf8_buffer), file) == NULL) { // 1 - куда записать строку, 2 - макс размер строки, 3 - откуда читать
        printf("Ошибка: Файл пуст или поврежден.\n");
        fclose(file);
        return 1;
    }
    fclose(file);

    // удаляем символ переноса строки, если он есть
    size_t len_bytes = strlen(utf8_buffer);
    if (len_bytes > 0 && utf8_buffer[len_bytes - 1] == '\n') {
        utf8_buffer[len_bytes - 1] = '\0';
    }

    // корректно считаем количество символов для разных языков
    size_t num_chars = mbstowcs(NULL, utf8_buffer, 0);
    if (num_chars == (size_t)-1) {
        printf("Ошибка кодировки при чтении слова.\n");
        return 1;
    }

    // выделяем память под широкие символы
    wchar_t *word = malloc((num_chars + 1) * sizeof(wchar_t));

    // конвертируем обычные байты в широкие символы (wchar_t)
    mbstowcs(word, utf8_buffer, num_chars + 1); // 1 - куда записывать, 2 - откуда читать, 3 - ограничение

    // 4. Запускаем генерацию анаграмм
    long long total_anagrams = 0;
    printf("Слово: %ls\n", word);
    printf("---Список анаграмм---\n");
    
    permute(word, 0, (int)num_chars - 1, &total_anagrams);

    printf("Всего выведено анаграмм: %lld\n", total_anagrams);

    free(word);
    return 0;
}