#ifndef SIMP_JAN_TIPOS_BASICOS_H
#define SIMP_JAN_TIPOS_BASICOS_H

typedef struct ConfiguracoesJanelaStruct {
  wchar_t *classeJanela;
  HINSTANCE instancia;
  wchar_t *tituloJanela;
  int iniX;
  int iniY;
  int largura;
  int altura;
  DWORD estilo;
} ConfiguracoesJanela;

typedef HWND Janela;

#endif // #ifndef SIMP_JAN_TIPOS_BASICOS_H