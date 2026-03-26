#ifndef _ALTERAR_DADOS_H_
#define _ALTERAR_DADOS_H_

#include <stdio.h>
#include <string.h>
#include "Gerenciamento_de_structs.h"
#include "Tratamento_de_entradas.h"

void adicionar_aluno(ALUN* info_alunos);
void retirar_aluno(ALUN* info_alunos);
void alterar_turma(ALUN* info_alunos);
unsigned short alterar_alunos(ALUN* info_alunos);
void adicionar_professor(PROF* info_professores);
void retirar_professor(PROF* info_professores);
void alterar_materia(PROF* info_professores);
unsigned short alterar_professores(PROF* info_professores);
#endif