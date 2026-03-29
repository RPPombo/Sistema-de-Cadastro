#ifndef _GERENCIAMENTO_STRUCTS_H_
#define _GERENCIAMENTO_STRUCTS_H_
#include <stdlib.h>
#include <stdio.h>
#include "Structs.h"

int alocar_memoria(void** ponteiro, size_t tamanho, int qtd);
int realocar_memoria(void** ponteiro, size_t tamanho_novo);
int alocar_memoria_alunos(ALUN* info_alunos);
int alocar_memoria_professores(PROF* info_professores);
int realocar_memoria_alunos(ALUN* info_alunos);
int realocar_memoria_professores(PROF* info_professores);
void liberar_memoria_alunos(ALUN* info_alunos);
void liberar_memoria_professores(PROF* info_professores);
void liberar_memoria_structs(ALUN* info_alunos, PROF* info_professores);
#endif