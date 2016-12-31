# simplesmenteJanela
Framework para simplificar o uso de janelas na linguagem C, no Windows

### Instalação
Baixe ou clone o repositório, e copie somente o arquivo '**simpJan.c**' para o diretório do seu projeto.

### Instruções

#### 1. Adicione o cabecalho da biblioteca

```c
#include "simpJan.c"
```

#### 2. Crie a funcão que gerencia os eventos das janelas
Essa função só precisa ser utilizada em caso de criar uma janela customizada, caso utilize uma janela já definida 
(janela retornada de uma das funções do framework) apenas retorne 1

```c
int manipulaEventosJanela(sj_Janela jan, UINT msg, WPARAM param1, LPARAM param2) {
  // Caso crie uma janela customaizada, manipule os eventos dela aqui
  
  ...
  
  // Caso utilize as janelas ja definidas apenas deixe a linha abaixo
  
  return 1;
}
```

#### 3. Crie a função principal
Essa função é como se fosse a 'main', o simplesmenteJanela já tem uma função 'main' do C implementada, logo tudo
que iria na 'main' irá nessa função

```c
int mainSimplesmenteJanela(sj_Id idProcesso, char *strCmd, int inciarProg) {
  // Seu código vai aqui
  
  ...
  
  return 0;
}
```

### Exemplo

Se você seguiu as instruções acima então seu código deve ser parecido com esse

```c
#include "simpJan.c"

int mainSimplesmenteJanela(sj_Id idProcesso, char *strCmd, int inciarProg) {
  ConfiguracoesJanela *conf = criaConfiguracoesJanela(idProcesso, "Window", "Minha Janela", 350, 250);
  sj_Janela jan = criaJanela(conf);
  executaJanela(jan);
  return 0;
}

int manipulaEventosJanela(sj_Janela jan, UINT msg, WPARAM param1, LPARAM param2) {
  return 1;
}

```

## No momento só funciona no Windows
