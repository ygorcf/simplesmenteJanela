#ifndef SIMP_JAN_DIALOGOS_H
#define SIMP_JAN_DIALOGOS_H

#include "../tipos/tiposBasicos.h"

int sj_mostrarDialogoMensagem(char *, ...);
int sj_mostrarDialogoConfirmar(char *, ...);
int sj_mostrarDialogoEntrada(char *, char *, ...);
BOOL CALLBACK DialogProc(HWND, UINT, WPARAM, LPARAM);
LPWORD lpwAlign(LPWORD);

#define ID_EDIT   3000
#define ID_BTN    3001
#define ID_TEXT   3002

#include "dialogos.c"

#endif // #ifndef SIMP_JAN_DIALOGOS_H