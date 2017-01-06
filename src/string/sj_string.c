#ifndef SIMP_JAN_STRING_C
#define SIMP_JAN_STRING_C

#include "sj_string.h"

int sj_strIgual(char *str1, char *str2) {
  return !strcmp(str1, str2);
}

char *sj_strStrip(char *_str) {
  return sj_strStripCaracs(_str, "\t\r\n \"'");
}

char *sj_strStripCaracs(char *_str, char *caracs) {
  int ini = 0, fim = strlen(_str) - 1;
  char *c = _str;
  while (*c != '\0') {
    if (strchr(caracs, *c++) != NULL)
      ini++;
    else
      break;
  }
  c = _str + fim;
  while (c != _str) {
    if (strchr(caracs, *c--) != NULL)
      fim--;
    else
      break;
  }
  char *ret = alocas(char, fim + 1);
  if (ret == NULL)
    return NULL;
  if (strncpy(ret, _str + ini, fim) == NULL) {
    free(ret);
    return NULL;
  }
  ret[fim] = '\0';
  return ret;
}

char *sj_strStripCarac(char *_str, char carac) {
  char *t = alocas(char, 2);
  if (t == NULL)
    return NULL;
  t[0] = carac;
  t[1] = '\0';
  char *ret = sj_strStripCaracs(_str, t);
  free(t);
  return ret;
}

char *sj_strCopia(char *_str) {
  int tam = strlen(_str);
  char *ret = malloc(tam * sizeof(char));
  if (ret == NULL)
    return NULL;
  if (strcpy(ret, _str) == NULL) {
    free(ret);
    return NULL;
  }
  return ret;
}

#endif // #ifndef SIMP_JAN_STRING_C