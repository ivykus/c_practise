#include <assert.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
  Problem SU — поиск в строке независимо от регистра
  Ваша задача написать функцию strstrci с наперёд заданным прототипом, которая
  ищет подстроку в строке, независимо от регистра символов (ci означает case
  insensitive)

  char * strstrci(char const * haystack, char const * needle);
  Ниже приведён пример применения

  char const *needle = "Ab", *src = "abracadaBra";
  char *pos1, *pos2, *pos3;
  pos1 = strstrci(src, needle);
  assert(pos1 != NULL);
  pos2 = strstrci(pos1 + 2, needle);
  assert(pos2 != NULL);
  pos3 = strstrci(pos2 + 2, needle);
  assert(pos3 == NULL);
  Первая найденная позиция "abracadabra", вторая "abracadaBra"

  Вы можете реализовать простой и наивный алгоритм с квадратичной
  асимптотической сложностью, он пройдёт тесты к этой задаче
*/

char *strstrci(char const *haystack, char const *needle) {
  if (!haystack || !needle) {
    return NULL;
  }
  for (size_t i = 0; i < strlen(haystack) - strlen(needle) + 1; i++) {
    if (tolower(haystack[i]) == tolower(needle[0])) {
      for (size_t j = 1; j < strlen(needle); j++) {
        if (tolower(haystack[i + j]) != tolower(needle[j])) {
          i = i + j - 1;
          break;
        }
        if (j == strlen(needle) - 1) {
          printf("%s\n", haystack + i);
          return (char *)haystack + i;
        }
      }
    }
  }
  return NULL;
}

char tolower2(char c) {
  if (c >= 'A' && c <= 'Z') {
    return c - 'A' + 'a';
  }
  return c;
}

int compare(const char *X, const char *Y) {
  while (*X && *Y) {
    if (tolower2(*X) != tolower2(*Y)) {
      return 0;
    }

    X++;
    Y++;
  }

  return (*Y == '\0');
}

char *strstrci2(const char *X, const char *Y) {
  while (*X != '\0') {
    if ((tolower2(*X) == tolower2(*Y)) && compare(X, Y)) {
      return strdup(X);
    }
    X++;
  }

  return NULL;
}

int main() {
  char const *needle = "Ab";
  char const *src = "abracadaBra";
  char *pos1, *pos2, *pos3;

  pos1 = strstrci(src, needle);
  assert(pos1 != NULL);
  if (strcmp(pos1, "abracadaBra") != 0) {
    printf("ERROR: \n\texpected: abracadaBra\n\tgot: %s\n", pos1);
  } else {
    printf("OK\n");
  }
  pos2 = strstrci(pos1 + 2, needle);
  assert(pos2 != NULL);
  if (strcmp(pos2, "aBra") != 0) {
    printf("ERROR: \n\texpected: aBra\n\tgot: %s\n", pos2);
  } else {
    printf("OK\n");
  }
  pos3 = strstrci(pos2 + 2, needle);
  assert(pos3 == NULL);

  char *str = "UvsegUBqeOVQpApROEhEVfEhFjWjVrvCkfsJHHSLmAEIanSGnYQYMSlCKBNSVgrG"
              "ptAHMWRVQSDSajqdjdTEaNBkKvUmnDNmalQD5egubq";

  char *result = strstrci(str, "egubq");
  assert(result != NULL);
  if (strcmp(result, "egUBqeOVQpApROEhEVfEhFjWjVrvCkfsJHHSLmAEIanSGnYQYMSlCKBNS"
                     "VgrGptAHMWRVQSDSajqdjdTEaNBkKvUmnDNmalQD5egubq") != 0) {
    printf("ERROR: \n\texpected: egubq\n\tgot: %s\n", result);
  } else {
    printf("OK\n");
  }
  return 0;
}