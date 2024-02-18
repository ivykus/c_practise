#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
    Problem SP — замена в строке
    Ваша задача написать функцию с наперёд заданным прототипом, осуществляющую
   замену всех подстрок в строке

    char *replace(char *str, char const *from, char const *to);
    Функция должна аллоцировать и возвращать строку со всеми вхождениями from,
   замененными на to

    Посылка должна состоять из этой одной функции (допустимо также любое
   количество вспомогательных), и не должна содержать функции main

    Пример 1

    Вход: "Hello, %username, how are you, %username", "%username", "Eric, the
   Blood Axe"

    Выход: "Hello, Eric, the Blood Axe, how are you, Eric, the Blood Axe"
*/

char *replace(char *str, char const *from, char const *to) {
  size_t from_len = strlen(from);
  size_t to_len = strlen(to);
  size_t new_sz = 0;
  char *result = NULL;
  char *result_ = NULL;

  char *pos = NULL;
  int counter = 0;
  char *str_ = str;
  while ((pos = strstr(str_, from))) {
    counter++;
    str_ = pos + from_len;
  }

  if (!counter) {
    return strdup(str);
  }

  // calculate size of resulting string
  new_sz = strlen(str) + (to_len - from_len) * counter;

  result = calloc(new_sz + 1, sizeof(char));
  if (!result) {
    return NULL;
  }

  str_ = str;
  result_ = result;
  while ((pos = strstr(str_, from))) {
    // copy before substitution
    strncpy(result_, str_, pos - str_);
    result_ += (pos - str_);

    // copy substitution
    strncpy(result_, to, to_len);
    result_ += to_len;

    str_ = pos + from_len;
  }

  if (str_ < str + strlen(str)) {
    // copy after substitution
    strcpy(result_, str_);
  }

  return result;
}

int main() {
  char *result;

  char *str1 = "Hello, %username, how are you, %username";
  char *from1 = "%username";
  char *to1 = "Eric, the Blood Axe";
  char *expected1 =
      "Hello, Eric, the Blood Axe, how are you, Eric, the Blood Axe";
  result = replace(str1, from1, to1);
  if (strcmp(result, expected1)) {
    printf("ERROR: \n\texpected: %s\n\tgot: %s\n", expected1, result);

  } else {
    printf("OK\n");
  }
  free(result);

  char *str2 = "%username";
  char *from2 = "%username";
  char *to2 = "Eric, the Blood Axe";
  char *expected2 = "Eric, the Blood Axe";
  result = replace(str2, from2, to2);
  if (strcmp(result, expected2)) {
    printf("ERROR: \n\texpected: %s\n\tgot: %s\n", expected2, result);

  } else {
    printf("OK\n");
  }
  free(result);

  char *str3 = "bananas";
  char *from3 = "%username";
  char *to3 = "Eric, the Blood Axe";
  char *expected3 = "bananas";
  result = replace(str3, from3, to3);
  if (strcmp(result, expected3)) {
    printf("ERROR: \n\texpected: %s\n\tgot: %s\n", expected3, result);

  } else {
    printf("OK\n");
  }
  free(result);

  char *str4 = "NOG tabcb MnJHabc ZQxqi i m abcHRARX zQOH CVaabc fsabcU";
  char *from4 = "abc";
  char *to4 = "x";
  char *expected4 = "NOG txb MnJHx ZQxqi i m xHRARX zQOH CVax fsxU";
  result = replace(str4, from4, to4);
  if (strcmp(result, expected4)) {
    printf("ERROR: \n\texpected: %s\n\tgot: %s\n", expected4, result);
  } else {
    printf("OK\n");
  }
  free(result);

  char *str5 = "abc1";
  char *from5 = "abc";
  char *to5 = "x";
  char *expected5 = "x1";
  result = replace(str5, from5, to5);
  if (strcmp(result, expected5)) {
    printf("ERROR: \n\texpected: %s\n\tgot: %s\n", expected5, result);
  } else {
    printf("OK\n");
  }
  free(result);

  return 0;
}