#ifndef _ORDEM_ALFABETICA_H_
#define _ORDEM_ALFABETICA_H_

#include <stdlib.h>
#include <string.h>
#include "Structs.h"
#include "Gerenciamento_de_structs.h"

int comparar_elementos(const void *a, const void *b);
ALUN ordenar_alfabeticamente_alunos(ALUN info_alunos);
PROF ordenar_alfabeticamente_professores(PROF info_professores);
#endif