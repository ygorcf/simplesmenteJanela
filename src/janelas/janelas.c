#ifndef SIMP_JAN_JANELAS_C
#define SIMP_JAN_JANELAS_C

#include "janelas.h"

sj_Janela criaJanela(ConfiguracoesJanela *config) {
  WNDCLASSW wc;

  wc.style = CS_HREDRAW | CS_VREDRAW;
  wc.cbClsExtra = 0;
  wc.cbWndExtra = 0;
  wc.lpszClassName = config->classeJanela;
  wc.hInstance = config->instancia;
  wc.hbrBackground = GetSysColorBrush(COLOR_3DFACE);
  wc.lpszMenuName = NULL;
  wc.lpfnWndProc = WndProc;
  wc.hCursor = LoadCursor(NULL, IDC_ARROW);
  wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);

  RegisterClassW(&wc);
  return CreateWindowW(wc.lpszClassName, config->tituloJanela, config->estilo,
                config->iniX, config->iniY, config->largura, config->altura, NULL, NULL, config->instancia, NULL);  
}

int executaJanela(sj_Janela jan) {
  MSG  msg;
  ShowWindow((HWND) jan, SW_SHOWDEFAULT);
  UpdateWindow((HWND) jan);

  while (GetMessage(&msg, NULL, 0, 0)) {
    TranslateMessage(&msg);
    DispatchMessage(&msg);
  }

  return (int) msg.wParam;
}

#endif // #ifndef SIMP_JAN_JANELAS_C