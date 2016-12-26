#ifndef SIMP_JAN_JANELAS_H
#define SIMP_JAN_JANELAS_H

#include "../tipos/tiposBasicos.h"

Janela criaJanela(ConfiguracoesJanela *config);
int executaJanela(Janela jan);

#include "janelas.c"

#endif // #ifndef SIMP_JAN_JANELAS_H