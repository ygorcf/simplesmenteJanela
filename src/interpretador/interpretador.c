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
  idsSj *ret = NULL, *retTemp;
  int qtdId = 1;
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
    retTemp = ret;
    retTemp = (idsSj *)realloc(ret, (qtdId + 1) * sizeof(idsSj));
    if (retTemp == NULL) {
      free(ret);
      return NULL;
    }
    ret = retTemp;
    ret[qtdId - 1] = obterId(add);
    ret[qtdId++] = SJ_ID_NULO;
  }
  return ret;
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

idsSj obterId(char *_str) {
  if (sj_strEInt(_str))
    return SJ_ID_INT;
  if (sj_strIgual(_str, "janela"))
    return SJ_ID_JANELA;
  if (sj_strIgual(_str, "altura"))
    return SJ_ID_ALTURA;
  if (sj_strIgual(_str, "largura"))
    return SJ_ID_LARGURA;
}

void printId(idsSj id) {
  switch (id) {
    case SJ_ID_JANELA:
      printf("Janela");
      break;
    case SJ_ID_INT:
      printf("Inteiro");
      break;
    case SJ_ID_ALTURA:
      printf("Altura");
      break;
    case SJ_ID_LARGURA:
      printf("Largura");
      break;
    default:
      printf("indefinido");
  }
  printf("\n");
}

int idEPropriedade(idsSj id) {
  switch (id) {
    case SJ_ID_ALTURA:
      return 1;
    case SJ_ID_LARGURA:
      return 1;
    default:
      return 0;
  }
}

int idEValor(idsSj id) {
  switch (id) {
    case SJ_ID_INT:
      return 1;
    default:
      return 0;
  }
}

sj_Janela *obterJanelas(sj_Id idProcesso, char *configuracoes) {
  char *classe = NULL, *titulo = NULL;
  int larg, alt, esperadoValor = 0, *valorAlterar = NULL, qtdjan = 1;
  sj_Janela *ret = NULL, *retTemp;
  idsSj *a = obterTodosIds(configuracoes);
  /*ConfiguracoesJanela *conf = criaConfiguracoesJanela(idProcesso, "Window", c, 350, 250);
  sj_Janela jan = criaJanela(conf);
  executaJanela(jan);*/
  while (*a != SJ_ID_NULO) {
    if (esperadoValor && idEValor(*a)) {
      *valorAlterar = 100;
      esperadoValor = 0;
    } else if (idEPropriedade(*a)) {
      esperadoValor = 1;
      switch (*a) {
        case SJ_ID_ALTURA:
          valorAlterar = &alt;
          break;
        case SJ_ID_LARGURA:
          valorAlterar = &larg;
          break;
        default :
          return NULL;
      }
    } else {
      larg = 350;
      alt = 250;
      esperadoValor = 0;
      if (titulo != NULL) free(titulo);
      titulo = (char *)malloc(7 * sizeof(char));
      if (titulo == NULL) return NULL;
      strcpy(titulo, "Janela\0");
      switch (*a) {
        case SJ_ID_JANELA:
          classe = "Window";
          break;
        default :
          return NULL;
      }
    }
    retTemp = ret;
    retTemp = (sj_Janela *)realloc(ret, (qtdjan + 1) * sizeof(sj_Janela));
    if (retTemp == NULL) {
      free(ret);
      return NULL;
    }
    ret = retTemp;
    ConfiguracoesJanela *conf = criaConfiguracoesJanela(idProcesso, classe, titulo, larg, alt);
    ret[qtdjan - 1] = criaJanela(conf);
    ret[qtdjan++] = NULL;
    a++;
  }
  return ret;
}

#endif // #ifndef SIMP_JAN_INTERPRETADOR_C