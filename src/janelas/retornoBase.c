#ifndef SIMP_JAN_RETORNO_BASE_C
#define SIMP_JAN_RETORNO_BASE_C

#include "retornoBase.h"
#include "../recursos/alocacao.h"

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
  if (manipulaEventosJanela(hwnd, msg, wParam, lParam))
    switch (msg) {
      case WM_DESTROY:
        PostQuitMessage(0);
        break;
    }

  return DefWindowProcW(hwnd, msg, wParam, lParam);
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR pCmdLine, int nCmdShow) {
  /*int tamBuff = 0;
  tamBuff = WideCharToMultiByte(CP_ACP, 0, pCmdLine, -1, NULL, 0, NULL, NULL);
  if (tamBuff == 0)
    return -2;
  char *argvCmd = NULL;
  argvCmd = alocas(char, tamBuff);
  if (argvCmd == NULL)
    return -3;
  if (tamBuff != WideCharToMultiByte(CP_ACP, 0, pCmdLine, -1, argvCmd, tamBuff, NULL, NULL)) {
    free(argvCmd);
    return -4;
  }*/
  return mainSimplesmenteJanela(hInstance, pCmdLine, nCmdShow);
}

#endif // #ifndef SIMP_JAN_RETORNO_BASE_C