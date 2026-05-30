#include <stdio.h>
#include <string.h>
void replace_word_with_x(char *word) {
    int length = strlen(word);
    for (int i = 0; i < length; i++) {
        word[i] = 'x';
    }
}

int main(){
    

char str1[] = "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor \
incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud \
exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute \
irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla \
pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia \
deserunt mollit anim id est laborum.aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
char *token = strtok(str1, " ,.");
int max = 0;
char *max_token = NULL;
char longest_word_copy[100] = "";
while (token != NULL){
    printf("%s\n", token);
    if (strlen(token) > max){
        max = strlen(token);
        max_token = token;
    }
    strcpy(longest_word_copy, token);
    token = strtok(NULL, " ,.");
}
// Заменяем самое длинное слово
    if (max_token != NULL) {
        replace_word_with_x(max_token);
        printf("Самое длинное слово заменено на: ");
        for (int i = 0; i < max; i++) {
            printf("x");
        }
        printf("\n");
    }
    
printf("Самое длинное слово: %s, его длина = %d\n", longest_word_copy, max);
}