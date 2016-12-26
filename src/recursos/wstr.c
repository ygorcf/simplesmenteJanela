#ifndef SIMP_JAN_WSTR_C
#define SIMP_JAN_WSTR_C

#include <wchar.h>
#include "alocacao.h"

wchar_t *strToWstr(char *_str) {
  int len = strlen(_str);
  wchar_t *ret;
  ret = alocas(wchar_t, len);
  if (ret != NULL) {
    swprintf(ret, len, L"%hs", _str);
  }
  return ret;
}

#endif // #ifndef SIMP_JAN_WSTR_C