#ifndef SIMP_JAN_RETORNO_BASE_C
#define SIMP_JAN_RETORNO_BASE_C

#include "retornoBase.h"

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
  if (msg == WM_DESTROY)
      PostQuitMessage(0);

  return DefWindowProcW(hwnd, msg, wParam, lParam);
}

#endif // #ifndef SIMP_JAN_RETORNO_BASE_C