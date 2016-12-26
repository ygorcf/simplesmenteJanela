#ifndef SIMP_JAN_ALOCACAO_H
#define SIMP_JAN_ALOCACAO_H

#include <stdlib.h>

#define alocas(t, q) ((t*)malloc((q) * sizeof(t)))
#define aloca(t) alocas(t, 1)

#endif // #ifndef SIMP_JAN_ALOCACAO_H