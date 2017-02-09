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
#ifndef SIMP_JAN_ALOCACAO_H
#define SIMP_JAN_ALOCACAO_H

#include <stdlib.h>

#define alocas(t, q) ((t*)malloc((q) * sizeof(t)))
#define aloca(t) alocas(t, 1)

#endif // #ifndef SIMP_JAN_ALOCACAO_H

wchar_t *strToWstr(char *_str) {
  int len = strlen(_str);
  wchar_t *ret;
  ret = alocas(wchar_t, len);
  if (ret != NULL) {
    swprintf(ret, len + 1, L"%hs\0", _str);
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

#ifndef SIMP_JAN_RETORNO_BASE_H
#define SIMP_JAN_RETORNO_BASE_H

#include <windows.h>

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);
int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR pCmdLine, int nCmdShow);

int manipulaEventosJanela(sj_Janela, UINT, WPARAM, LPARAM);
int mainSimplesmenteJanela(sj_Id, char *, int);


#endif // #ifndef SIMP_JAN_RETORNO_BASE_H
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

#ifndef SIMP_JAN_CONF_JAN_H
#define SIMP_JAN_CONF_JAN_H


#include <windows.h>

ConfiguracoesJanela *criaConfiguracoesJanela(HINSTANCE instancia, char *classe, char *titulo, int largura, int altura);
void defineEstiloJanela(ConfiguracoesJanela *config, DWORD estilo);
void defineTamanhoJanela(ConfiguracoesJanela *config, int largura, int altura);
void defineLocalInicioJanela(ConfiguracoesJanela *config, int x, int y);
void defineTituloJanela(ConfiguracoesJanela *config, char *titulo);


#endif // #ifndef SIMP_JAN_CONF_JAN_H

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

#ifndef SIMP_JAN_DIALOGOS_H
#define SIMP_JAN_DIALOGOS_H


int sj_mostrarDialogoMensagem(char *, ...);
int sj_mostrarDialogoConfirmar(char *, ...);
int sj_mostrarDialogoEntrada(char *, char *, ...);
BOOL CALLBACK DialogProc(HWND, UINT, WPARAM, LPARAM);
LPWORD lpwAlign(LPWORD);

#define ID_EDIT   3000
#define ID_BTN    3001
#define ID_TEXT   3002

#ifndef SIMP_JAN_DIALOGOS_C
#define SIMP_JAN_DIALOGOS_C


int sj_mostraMensagem(char *titulo, ...) {
  if (titulo == NULL)
    return -1;
  char *msg = NULL;
  va_list paramentrosExtras;
  va_start(paramentrosExtras, titulo);
  int tam = _vscprintf(titulo, paramentrosExtras) + 1;
  if (tam < 0) {
    va_end(paramentrosExtras);
    return -2;
  }
  msg = alocas(char, tam);
  if (msg == NULL) {
    va_end(paramentrosExtras);
    return -3;
  }
  int caracGravados = vsnprintf_s(msg, tam, tam, titulo, paramentrosExtras);
  if ((caracGravados + 1) != tam) {
    free(msg);
    va_end(paramentrosExtras);
    return -4;
  }
  va_end(paramentrosExtras);
  wchar_t *wmsg = strToWstr(msg);
  MessageBoxW(NULL, wmsg, L"Mensagem", MB_OK);
  free(wmsg);
  free(msg);
  return 0;
}

int sj_mostrarDialogoConfirmar(char *titulo, ...) {
  if (titulo == NULL)
    return -1;
  char *msg = NULL;
  va_list paramentrosExtras;
  va_start(paramentrosExtras, titulo);
  int tam = _vscprintf(titulo, paramentrosExtras) + 1;
  if (tam < 0) {
    va_end(paramentrosExtras);
    return -2;
  }
  msg = alocas(char, tam);
  if (msg == NULL) {
    va_end(paramentrosExtras);
    return -3;
  }
  int caracGravados = vsnprintf_s(msg, tam, tam, titulo, paramentrosExtras);
  if ((caracGravados + 1) != tam) {
    free(msg);
    va_end(paramentrosExtras);
    return -4;
  }
  va_end(paramentrosExtras);
  wchar_t *wmsg = strToWstr(msg);
  int msgboxID = MessageBoxW(NULL, wmsg, L"Confirmar", MB_ICONEXCLAMATION | MB_YESNO);
  free(wmsg);
  free(msg);
  return msgboxID == IDYES;
}

int sj_mostrarDialogoEntrada(char *retMsg, char *titulo, ...) {
  if (titulo == NULL)
    return -1;
  if (retMsg == NULL)
    return -2;
  char *msg = NULL;
  va_list paramentrosExtras;
  va_start(paramentrosExtras, titulo);
  int tam = _vscprintf(titulo, paramentrosExtras) + 1;
  if (tam < 0) {
    va_end(paramentrosExtras);
    return -3;
  }
  msg = alocas(char, tam);
  if (msg == NULL) {
    va_end(paramentrosExtras);
    return -4;
  }
  int caracGravados = vsnprintf_s(msg, tam, tam, titulo, paramentrosExtras);
  if ((caracGravados + 1) != tam) {
    free(msg);
    va_end(paramentrosExtras);
    return -4;
  }
  va_end(paramentrosExtras);
  wchar_t *wmsg = strToWstr(msg);
  
       HGLOBAL hgbl;
       LPDLGTEMPLATE lpdt;
       LPDLGITEMTEMPLATE lpdit;
       LPWORD lpw;
       LPWSTR lpwsz;
       LRESULT ret;
	   int nchar;

       hgbl = GlobalAlloc(GMEM_ZEROINIT, 1024);
       if (!hgbl)
           return -5;

       lpdt = (LPDLGTEMPLATE)GlobalLock(hgbl);

       // Define a dialog box.

       lpdt->style = 0x0004 | DS_CENTER | WS_CAPTION | WS_MINIMIZEBOX | 
WS_SYSMENU | WS_VISIBLE | WS_OVERLAPPED | DS_MODALFRAME | DS_3DLOOK ;
       lpdt->cdit = 2;  // number of controls
       lpdt->x  = 10;  lpdt->y  = 10;
       lpdt->cx = 205; lpdt->cy = 60;

       lpw = (LPWORD) (lpdt + 1);
       *lpw++ = 0;   // no menu
       *lpw++ = 0;   // predefined dialog box class (by default)

       lpwsz = (LPWSTR) lpw;
       nchar = 1+ MultiByteToWideChar(CP_ACP, 0, msg, -1, lpwsz, 50);
       lpw   += nchar;
       
       //-----------------------
       // Define an OK button.
       //-----------------------
       lpw = lpwAlign (lpw);

       lpdit = (LPDLGITEMTEMPLATE) lpw;
       lpdit->x  = 141; lpdit->y  = 26;
       lpdit->cx = 52; lpdit->cy = 13;
       lpdit->id = ID_BTN;  // OK button identifier
       lpdit->style = WS_GROUP | WS_CHILD | WS_VISIBLE;

       lpw = (LPWORD) (lpdit + 1);
       *lpw++ = 0xFFFF;
       *lpw++ = 0x0080;    // button class

       lpwsz = (LPWSTR) lpw;
       nchar = 1+MultiByteToWideChar (CP_ACP, 0, "OK", -1, lpwsz, 50);
       lpw   += nchar;
       *lpw++ = 0;              // no creation data

/*
       //-----------------------
       // Define a static text control.
       //-----------------------
       lpw = lpwAlign (lpw);

       lpdit = (LPDLGITEMTEMPLATE) lpw;
       lpdit->x  = 141; lpdit->y  = 10;
       lpdit->cx = 52; lpdit->cy = 13;
    lpdit->id = ID_TEXT;    // Text identifier
    lpdit->style =  WS_CHILD | WS_VISIBLE;

    lpw = (LPWORD)(lpdit + 1);
    *lpw++ = 0xFFFF;
    *lpw++ = 0x0082;        // Static class

    lpwsz = (LPWSTR)lpw;
    nchar = 1 + MultiByteToWideChar(CP_ACP, 0, lpszMessage, -1, lpwsz, 150);
    lpw += nchar;
    *lpw++ = 0;             // No creation data
*/

       //-----------------------
       // Define a EDIT.
       //-----------------------
       lpw = lpwAlign (lpw);

       lpdit = (LPDLGITEMTEMPLATE) lpw;
       lpdit->x  = 15; lpdit->y  = 17;
       lpdit->cx = 111; lpdit->cy = 13;
       lpdit->id = ID_EDIT;    // Edit identifier
       lpdit->style =  ES_LEFT | WS_BORDER | WS_TABSTOP | WS_CHILD | WS_VISIBLE;

       lpw = (LPWORD) (lpdit + 1);
       *lpw++ = 0xFFFF;
       *lpw++ = 0x0081;                 // edit class atom
       //lpwsz = (LPWSTR) lpw;
       //lstrcpyW(lpwsz, L"Edit");        // button label (Unicode)
       //lpw = (LPWORD) (lpwsz + lstrlenW(lpwsz) + 1);
       *lpw++ = 0;                      // no creation data
       GlobalUnlock(hgbl);


       ret = DialogBoxIndirectParam(NULL,
                               (LPDLGTEMPLATE) hgbl,
                               NULL,
                               (DLGPROC) DialogProc,
                               (LPARAM)retMsg);

       GlobalFree(hgbl);

       return (ret == 0) ? 0 : -6;
}

BOOL CALLBACK DialogProc(HWND hDlg, UINT iMsg, WPARAM wParam, LPARAM lParam) {
  static char *textoDigitado = NULL;
     switch (iMsg)
	 {
          case WM_INITDIALOG :
               textoDigitado = (char *)lParam;
               return TRUE ;
			   
			   
          case WM_COMMAND :
               switch (LOWORD (wParam))
               {
					case ID_EDIT :
						 GetDlgItemText (hDlg, ID_EDIT, textoDigitado, 127);
						 return TRUE;
					/*case ID_BTN :
						 MessageBox( NULL, textoDigitado, "Input Data", MB_OK | MB_SYSTEMMODAL | MB_NOFOCUS);
						 return TRUE;*/
		            case ID_BTN :
					case IDCANCEL:
						EndDialog(hDlg, LOWORD(wParam));
						return TRUE;
                         //EndDialog (hDlg, 0) ;
			             //return TRUE ;
			   }
              break ;
     }
     return FALSE ;
}

LPWORD lpwAlign(LPWORD lpIn) {
    ULONG ul;

    ul = (ULONG)lpIn;
    ul ++;
    ul >>=1;
    ul <<=1;
    return (LPWORD)ul;
}

#endif // #ifndef SIMP_JAN_DIALOGOS_C

#endif // #ifndef SIMP_JAN_DIALOGOS_H

sj_Janela criaJanela(ConfiguracoesJanela *config);
int executaJanela(sj_Janela jan);

#ifndef SIMP_JAN_JANELAS_C
#define SIMP_JAN_JANELAS_C

#ifndef SIMP_JAN_JANELAS_H
#define SIMP_JAN_JANELAS_H


sj_Janela criaJanela(ConfiguracoesJanela *config);
int executaJanela(sj_Janela jan);


#endif // #ifndef SIMP_JAN_JANELAS_H


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
