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

#ifndef SIMP_JAN_STRING_H
#define SIMP_JAN_STRING_H

#include <string.h>
#include <stdlib.h>

int sj_strIgual(char *str1, char *str2);
char *sj_strStrip(char *_str);
char *sj_strStripCaracs(char *_str, char *caracs);
char *sj_strStripCarac(char *_str, char carac);
char *sj_strCopia(char *_str);
int sj_strEInt(char *_str);

#ifndef SIMP_JAN_STRING_C
#define SIMP_JAN_STRING_C


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

int sj_strEInt(char *_str) {
  char *temp = _str;
  while (*temp != '\0') {
    if (isdigit(*temp) == 0 && *temp != '0')
      return 0;
    temp++;
  }
  return 1;
}

#endif // #ifndef SIMP_JAN_STRING_C

#endif // #ifndef SIMP_JAN_STRING_H

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

#ifndef SIMP_JAN_INTERPRETADOR_C
#define SIMP_JAN_INTERPRETADOR_C


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
  }
  return ret;
}

#endif // #ifndef SIMP_JAN_INTERPRETADOR_C

#endif // #ifndef SIMP_JAN_INTERPRETADOR_H

#endif // #ifndef SIMP_JAN_H
