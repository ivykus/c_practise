#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
  Problem SCN — суммирование в строке
  Ваша задача написать программу которая суммирует строчку, воспринимая символы
  в ней как коды этих символов

  Вы можете рассчитывать, что строка содержит только однобайтные символы UTF8
  (эта задача стала бы заметно сложнее без этого предположения)

  Вы также можете предполагать, что длина строки не превышает 1024 символа и не
  меньше 1 символа

  Посылка должна состоять из программы, которая считывает строку со стандартного
  ввода и отдаёт на стандартный вывод сумму символов в этой строке


  Пример 1

  Вход: Hello, world!

  Выход: 1161


  Пример 2 (многострочный текст это тоже текст)

  Вход: First line\nSecond line

  Выход: 2046

*/

void problem_scn();

/*
  Problem SR — переворот подстрок
  Ваша задача написать программу которая переворачивает в некоей строке все
  вхождения определённой подстроки

  Например для подстроки "world" и строки "Hello, world!" результатом должно
  быть "Hello, dlrow!"

  Вы можете предполагать что текст состоит из слов, разделённых пробелами и
  пунктуацией, а слово состоит из алфавитных символов

  Вы также можете использовать любые функции стандартной библиотеки, включая
  strstr для поиска подстроки

  Во входных данных идёт сначала длина искомой подстроки, далее отделённая любым
  одним пробельным символом сама подстрока, далее длина текста и далее, опять
  отделённый одним любым пробельным символом сам текст, в котором нужно сделать
  поиск и замену

  На выходе должен быть распечатан текст с перевёрнутыми подстроками, либо
  исходный текст, если ни одной подстроки не найдено

  Посылка должна состоять из программы, которая считывает данные со стандартного
  ввода и печатает ответ на стандартный вывод


  Пример 1

  Вход: 5 world 13 Hello, world!

  Выход: Hello, dlrow!

  Пример 2

  Вход: 3 abc 51 qffUt g abcykvabcb x Lv BRabc g KUrabcN wQabcylz R

  Выход: qffUt g cbaykvcbab x Lv BRcba g KUrcbaN wQcbaylz R
*/
void problem_sr();

/*
  Problem SA — конкатенировать с реаллокацией
  Ваша задача написать функцию с наперёд заданным прототипом, осуществляющую
  конкатенацию строк с реаллокацией

  char *strcat_r(char *dest, const char *src, int *bufsz);
  Функция должна дописывать src в конец dest, при необходимости реаллоцируя dest

  Параметр bufsz содержит фактический размер массива для dest, который может
  быть куда больше, чем её null-terminated длина. Это in-out параметр, так как
  туда записывается новый размер. Функция должна, если буфер недостаточен,
  реаллоцировать его точно до размера сконкатенированной строки, делать запас
  для амортизации не надо

  Возвращаемое значение: указатель на начало сконкатенированной строки. Из-за
  реаллокаций он может и не совпадать с dest

  Посылка должна состоять из этой одной функции (допустимо также любое
  количество вспомогательных), и не должна содержать функции main

  Пример 1

  Вход: "Hello", 6, ", world!"

  Выход: "Hello, world!"
*/
void problem_sa();
char *strcat_r(char *dest, const char *src, int *buf_sz);

void read_data(char **substr_, char **str_);

void reverse_substr(char *str, char *substr);

int main() {}

void problem_scn() {
  char c;
  int res = 0;
  while (scanf("%c", &c) == 1) {
    res += c;
  }
  printf("%d\n", res);
}

void problem_sa() {
  char *substr = NULL;
  char *str = NULL;
  read_data(&substr, &str);
}

char *strcat_r(char *dest, const char *src, int *buf_sz) {
  size_t dest_len = strlen(dest);
  size_t src_len = strlen(src);
  size_t new_len = dest_len + src_len + 1;
  if (*buf_sz < new_len) {
    *buf_sz = new_len;
    dest = realloc(dest, *buf_sz);
  }
  strncat(dest, src, src_len + 1);
  return dest;
}

void problem_sr() {
  char *substr = NULL;
  char *str = NULL;
  read_data(&substr, &str);

  reverse_substr(str, substr);

  printf("%s\n", str);
  free(substr);
  free(str);
}

void reverse_substr(char *str, char *substr) {
  char *pos;
  int len = strlen(substr);
  while ((pos = strstr(str, substr))) {
    int i = 0;
    while (i < len / 2) {
      char c = pos[i];
      pos[i] = pos[len - 1 - i];
      pos[len - 1 - i] = c;
      i++;
    }
    str = pos + len;
  }
}

void read_data(char **substr_, char **str_) {
  char c;
  int substr_sz = 0;
  int str_sz = 0;
  char *substr = NULL;
  char *str = NULL;

  scanf("%d", &substr_sz);
  substr = malloc(substr_sz + 1);

  scanf("%c", &c);
  for (int i = 0; i < substr_sz; i++) {
    scanf("%c", &substr[i]);
  }
  substr[substr_sz] = '\0';

  scanf("%c", &c);
  scanf("%d", &str_sz);
  str = malloc(str_sz + 1);
  scanf("%c", &c);
  for (int i = 0; i < str_sz; i++) {
    scanf("%c", &str[i]);
  }
  str[str_sz] = '\0';

  *substr_ = substr;
  *str_ = str;
}