#ifndef SIMP_JAN_DIALOGOS_C
#define SIMP_JAN_DIALOGOS_C

#include "dialogos.h"

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