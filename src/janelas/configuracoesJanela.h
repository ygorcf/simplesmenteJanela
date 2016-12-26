#ifndef SIMP_JAN_CONF_JAN_H
#define SIMP_JAN_CONF_JAN_H

#include "../tipos/tiposBasicos.h"

#include <windows.h>

ConfiguracoesJanela *criaConfiguracoesJanela(HINSTANCE instancia, char *classe, char *titulo, int largura, int altura);
void defineEstiloJanela(ConfiguracoesJanela *config, DWORD estilo);
void defineTamanhoJanela(ConfiguracoesJanela *config, int largura, int altura);
void defineLocalInicioJanela(ConfiguracoesJanela *config, int x, int y);
void defineTituloJanela(ConfiguracoesJanela *config, char *titulo);

#include "configuracoesJanela.c"

#endif // #ifndef SIMP_JAN_CONF_JAN_H