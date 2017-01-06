#ifndef SIMP_JAN_INTERPRETADOR_C
#define SIMP_JAN_INTERPRETADOR_C

#include "interpretador.h"

// copiar toda string

// pegar todas palavras
//  loop
//   strip na string
//   pegar tamanho da palavra
//   copiar palavra
//   adicionar no array
//   move ponteiro str
// transformar palavras em identificadores
// retornar array de identificadores
idsSj *obterTodosIds(char *_str) {
  char *copiaStr = sj_strCopia(_str);
  if (copiaStr == NULL) return NULL;
  char *caracsPular = "  :=;'\"\r\t\n";
  char *temp = NULL, *add = NULL;
  int tam = 0;
  while (*copiaStr != '\0') {
    copiaStr = pularCaracs(copiaStr, caracsPular);
    if (copiaStr == NULL)
      return NULL;
    temp = localPrimeiro(copiaStr, caracsPular);
    tam = temp - copiaStr;
    add = (char *)malloc((tam + 1) * sizeof(char));
    if (add == NULL) {
      free(copiaStr);
      return NULL;
    }
    if (strncpy(add, copiaStr, tam) == NULL) {
      free(copiaStr);
      free(add);
      return NULL;
    }
    copiaStr = temp;
    printf("|%s|\n", add);
  }
  return NULL;
}

char *pularCaracs(char *_str, char *caracs) {
if (_str == NULL) return NULL;
  char *t = _str - 1;
  while (*++t != '\0') {
    if (strchr(caracs, *t) == NULL)
      break;
  }
  return t;
}

char *localPrimeiro(char *_str, char *caracsProcurar) {
if (_str == NULL) return NULL;
  char *t = _str - 1;
  while (*++t != '\0') {
    if (strchr(caracsProcurar, *t) != NULL)
      break;
  }
  return t;
}

#endif // #ifndef SIMP_JAN_INTERPRETADOR_C