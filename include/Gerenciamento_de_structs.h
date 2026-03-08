#ifndef _STRUCTS_H_
#define _STRUCTS_H_
#include <stdlib.h>

struct alunos
{
    int quantidade;
    char** nome;
    int* turma;
};

typedef struct alunos ALUN;

struct professores
{
    int quantidade;
    char** nome;
    char** materia; 
};

typedef struct professores PROF;

void alocar_memoria_alunos(ALUN* info_alunos);
void alocar_memoria_professores(PROF* info_professores);
void realocar_memoria_alunos(ALUN* info_alunos);
void realocar_memoria_professores(PROF* info_professores);
void liberar_memoria_alunos(ALUN* info_alunos);
void liberar_memoria_professores(PROF* info_professores);
void liberar_memoria_structs(ALUN* info_alunos, PROF* info_professores);
#endif