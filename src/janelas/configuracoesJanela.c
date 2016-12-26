#ifndef SIMP_JAN_CONF_JAN_C
#define SIMP_JAN_CONF_JAN_C

#include "configuracoesJanela.h"

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