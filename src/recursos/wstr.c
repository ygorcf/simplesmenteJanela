#ifndef SIMP_JAN_WSTR_C
#define SIMP_JAN_WSTR_C

#include <wchar.h>
#include "alocacao.h"

wchar_t *strToWstr(char *_str) {
  int len = strlen(_str) + 1;
  wchar_t *ret;
  ret = alocas(wchar_t, len);
  if (ret != NULL) {
    swprintf(ret, len + 1, L"%hs\0", _str);
  }
  return ret;
}

#endif // #ifndef SIMP_JAN_WSTR_C