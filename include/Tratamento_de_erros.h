#ifndef _TRATAMENTO_ERROS_H_
#define _TRATAMENTO_ERROS_H_

#include <stdio.h>
#include "Structs.h"
#include "Gerenciamento_de_structs.h"

void erro_alocacao(ALUN* info_alunos, PROF* info_professores);
void erro_realocacao(ALUN* info_alunos, PROF* info_professores);

#endif