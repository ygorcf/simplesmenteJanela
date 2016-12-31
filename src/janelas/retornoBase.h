#ifndef SIMP_JAN_RETORNO_BASE_H
#define SIMP_JAN_RETORNO_BASE_H

#include <windows.h>

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);
int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR pCmdLine, int nCmdShow);

int manipulaEventosJanela(sj_Janela, UINT, WPARAM, LPARAM);
int mainSimplesmenteJanela(sj_Id, char *, int);

#include "retornoBase.c"

#endif // #ifndef SIMP_JAN_RETORNO_BASE_H