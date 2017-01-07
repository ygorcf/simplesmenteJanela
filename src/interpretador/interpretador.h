#ifndef SIMP_JAN_INTERPRETADOR_H
#define SIMP_JAN_INTERPRETADOR_H

#include <string.h>

typedef enum {
  SJ_ID_INDEFINIDO,
  SJ_ID_NULO,
  SJ_ID_JANELA,
  SJ_ID_INT,
  SJ_ID_ALTURA,
  SJ_ID_LARGURA
} idsSj;

idsSj *obterTodosIds(char *_str);
char *pularCaracs(char *_str, char *caracs);
char *localPrimeiro(char *_str, char *caracsProcurar);
idsSj obterId(char *_str);
void printId(idsSj id);
int idEPropriedade(idsSj id);
int idEValor(idsSj id);

#include "interpretador.c"

#endif // #ifndef SIMP_JAN_INTERPRETADOR_H