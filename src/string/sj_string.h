#ifndef SIMP_JAN_STRING_H
#define SIMP_JAN_STRING_H

#include <string.h>

int sj_strIgual(char *str1, char *str2);
char *sj_strStrip(char *_str);
char *sj_strStripCaracs(char *_str, char *caracs);
char *sj_strStripCarac(char *_str, char carac);
char *sj_strCopia(char *_str);

#include "sj_string.c"

#endif // #ifndef SIMP_JAN_STRING_H