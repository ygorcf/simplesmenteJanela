#ifndef SIMP_JAN_H
#define SIMP_JAN_H

#ifdef WIN32
#include <windows.h>
#else
#include <X11/Xlib.h>
#endif // #ifdef WIN32

#include "./recursos/alocacao.h"
#include "./recursos/wstr.c"

#include "./tipos/tiposBasicos.h"

#include "./janelas/retornoBase.h"
#include "./janelas/configuracoesJanela.h"
#include "./janelas/janelas.h"

#endif // #ifndef SIMP_JAN_H