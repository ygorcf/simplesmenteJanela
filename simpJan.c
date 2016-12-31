#ifndef SIMP_JAN_H
#define SIMP_JAN_H

#include <windows.h>

#ifndef SIMP_JAN_ALOCACAO_H
#define SIMP_JAN_ALOCACAO_H

#include <stdlib.h>

#define alocas(t, q) ((t*)malloc((q) * sizeof(t)))
#define aloca(t) alocas(t, 1)

#endif // #ifndef SIMP_JAN_ALOCACAO_H
#ifndef SIMP_JAN_WSTR_C
#define SIMP_JAN_WSTR_C

#include <wchar.h>

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

#ifndef SIMP_JAN_TIPOS_BASICOS_H
#define SIMP_JAN_TIPOS_BASICOS_H

typedef HINSTANCE sj_Id;

typedef struct ConfiguracoesJanelaStruct {
  wchar_t *classeJanela;
  sj_Id instancia;
  wchar_t *tituloJanela;
  int iniX;
  int iniY;
  int largura;
  int altura;
  DWORD estilo;
} ConfiguracoesJanela;

typedef HWND sj_Janela;

#endif // #ifndef SIMP_JAN_TIPOS_BASICOS_H

#ifndef SIMP_JAN_RETORNO_BASE_H
#define SIMP_JAN_RETORNO_BASE_H

#include <windows.h>

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);
int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR pCmdLine, int nCmdShow);

int manipulaEventosJanela(sj_Janela, UINT, WPARAM, LPARAM);
int mainSimplesmenteJanela(sj_Id, char *, int);

#ifndef SIMP_JAN_RETORNO_BASE_C
#define SIMP_JAN_RETORNO_BASE_C

#ifndef SIMP_JAN_ALOCACAO_H
#define SIMP_JAN_ALOCACAO_H

#include <stdlib.h>

#define alocas(t, q) ((t*)malloc((q) * sizeof(t)))
#define aloca(t) alocas(t, 1)

#endif // #ifndef SIMP_JAN_ALOCACAO_H

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

#endif // #ifndef SIMP_JAN_RETORNO_BASE_H
#ifndef SIMP_JAN_CONF_JAN_H
#define SIMP_JAN_CONF_JAN_H

#ifndef SIMP_JAN_TIPOS_BASICOS_H
#define SIMP_JAN_TIPOS_BASICOS_H

typedef HINSTANCE sj_Id;

typedef struct ConfiguracoesJanelaStruct {
  wchar_t *classeJanela;
  sj_Id instancia;
  wchar_t *tituloJanela;
  int iniX;
  int iniY;
  int largura;
  int altura;
  DWORD estilo;
} ConfiguracoesJanela;

typedef HWND sj_Janela;

#endif // #ifndef SIMP_JAN_TIPOS_BASICOS_H

#include <windows.h>

ConfiguracoesJanela *criaConfiguracoesJanela(HINSTANCE instancia, char *classe, char *titulo, int largura, int altura);
void defineEstiloJanela(ConfiguracoesJanela *config, DWORD estilo);
void defineTamanhoJanela(ConfiguracoesJanela *config, int largura, int altura);
void defineLocalInicioJanela(ConfiguracoesJanela *config, int x, int y);
void defineTituloJanela(ConfiguracoesJanela *config, char *titulo);

#ifndef SIMP_JAN_CONF_JAN_C
#define SIMP_JAN_CONF_JAN_C


ConfiguracoesJanela *criaConfiguracoesJanela(HINSTANCE instancia, char *classe, char *titulo, int largura, int altura) {
  ConfiguracoesJanela *ret;
  ret = aloca(ConfiguracoesJanela);
  if (ret != NULL) {
    ret->classeJanela = strToWstr(classe);
    ret->instancia = instancia;
    defineTituloJanela(ret, titulo);
    defineLocalInicioJanela(ret, 0, 0);
    defineTamanhoJanela(ret, largura, altura);
    defineEstiloJanela(ret, WS_OVERLAPPEDWINDOW | WS_VISIBLE);
  }
  return ret;
}

void defineEstiloJanela(ConfiguracoesJanela *config, DWORD estilo) {
  config->estilo = estilo;
}

void defineTamanhoJanela(ConfiguracoesJanela *config, int largura, int altura) {
  config->largura = largura;
  config->altura = altura;
}

void defineLocalInicioJanela(ConfiguracoesJanela *config, int x, int y) {
  config->iniX = x;
  config->iniY = y;
}

void defineTituloJanela(ConfiguracoesJanela *config, char *titulo) {
  config->tituloJanela = strToWstr(titulo);
}

#endif // #ifndef SIMP_JAN_CONF_JAN_C

#endif // #ifndef SIMP_JAN_CONF_JAN_H
#ifndef SIMP_JAN_JANELAS_H
#define SIMP_JAN_JANELAS_H


sj_Janela criaJanela(ConfiguracoesJanela *config);
int executaJanela(sj_Janela jan);

#ifndef SIMP_JAN_JANELAS_C
#define SIMP_JAN_JANELAS_C


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

#endif // #ifndef SIMP_JAN_JANELAS_H

#endif // #ifndef SIMP_JAN_H
