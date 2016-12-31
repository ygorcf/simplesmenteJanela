#ifndef SIMP_JAN_JANELAS_H
#define SIMP_JAN_JANELAS_H

#include "../tipos/tiposBasicos.h"

sj_Janela criaJanela(ConfiguracoesJanela *config);
int executaJanela(sj_Janela jan);

#include "janelas.c"

#endif // #ifndef SIMP_JAN_JANELAS_H