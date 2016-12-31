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