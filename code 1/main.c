#include <stdio.h>
#include <string.h>
#include <ctype.h>

void fLongWord(char s[], char longWord[]);
int cGWord(char word[]);
int cPWord(char word[]);
int cPGWords(char s[]);

int main() {
char s[100];
printf("Введіть речення: ");
fgets(s, sizeof(s), stdin);
char longWord[100] = "";
fLongWord(s, longWord);
int PGword = cPGWords(s);
  
printf("Найдовше слово: %s\n", longWord);
if (PGword == 0){
printf("немає слів з однаковою кількістю голосних і приголосних літер");
}
else{
printf("Кількість слів з однаковою кількістю голосних і приголосних літер: %d\n", PGword);}
 return 0;
}

// кількість голосних
int cGWord(char word[]) {
int Gword = 0;
for (int i = 0; word[i] != '\0'; i++) {
char ch = tolower(word[i]);
if (isalpha(ch) && (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u'))
Gword++;
 }
return Gword;
}
// кількість приголосних
int cPWord(char word[]) {
int Pword = 0;
for (int i = 0; word[i] != '\0'; i++) {
char ch = tolower(word[i]);
if (isalpha(ch) && !(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u'))
Pword++;
}
return Pword;
}
// кількість приголосних й голосних
int cPGWords(char sentence[]) {
int PGword = 0;
char copy[100];
strcpy(copy, sentence);
char *word = strtok(copy, " \n");
while (word != 0) {
int Gword = cGWord(word);
int Pword = cPWord(word);
if (Gword == Pword) {
PGword++;
}
word = strtok(0, " \n");
 }
return PGword;
}
// найдовше слово
void fLongWord(char s[], char longWord[]) {
char copy[100];
strcpy(copy, s);
char *word = strtok(copy, " \n");
while (word != 0) {
if (strlen(word) > strlen(longWord))
strcpy(longWord, word);
word = strtok(0, " \n");
  }
}