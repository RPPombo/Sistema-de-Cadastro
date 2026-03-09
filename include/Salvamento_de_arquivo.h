#ifndef _SALVAMENTO_H_
#define _SALVAMENTO_H_

#include <stdio.h>
#include "Gerenciamento_de_structs.h"

void salvar_arquivos_professores(PROF info_professores);
void salvar_arquivo_alunos(ALUN info_alunos);
void salvar_arquivos(ALUN info_alunos, PROF info_professores);
#endif