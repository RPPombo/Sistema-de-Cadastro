#ifndef _Leitura_H_
#define _Leitura_H_

#include <stdio.h>
#include <stdlib.h>
#include "Structs.h"
#include "Gerenciamento_de_structs.h"

FILE* carregar_arquivo(char* nome_do_arquivo);
int carregar_alunos(ALUN* info_alunos);
int carregar_professores(PROF* info_professores);
#endif