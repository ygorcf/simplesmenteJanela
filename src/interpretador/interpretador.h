#ifndef SIMP_JAN_INTERPRETADOR_H
#define SIMP_JAN_INTERPRETADOR_H

#include <string.h>

typedef enum {
  SJ_ID_JANELA
} idsSj;

idsSj *obterTodosIds(char *_str);
char *pularCaracs(char *_str, char *caracs);
char *localPrimeiro(char *_str, char *caracsProcurar);

#include "interpretador.c"

#endif // #ifndef SIMP_JAN_INTERPRETADOR_H