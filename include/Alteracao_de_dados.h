#ifndef _ALTERAR_DADOS_H_
#define _ALTERAR_DADOS_H_

#include <stdio.h>
#include <string.h>
#include "Gerenciamento_de_structs.h"
#include "Tratamento_de_entradas.h"
#include "Structs.h"
#include "Tratamento_de_erros.h"
#include "Busca_nomes.h"
#include "Ordem_alfabetica.h"

int adicionar_aluno(ALUN* info_alunos);
void retirar_aluno(ALUN* info_alunos);
void alterar_turma(ALUN* info_alunos);
unsigned short alterar_alunos(ALUN* info_alunos, int* erro);
int adicionar_professor(PROF* info_professores);
void retirar_professor(PROF* info_professores);
void alterar_materia(PROF* info_professores);
unsigned short alterar_professores(PROF* info_professores, int* erro);

#endif