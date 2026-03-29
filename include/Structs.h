#ifndef _STRUCTS_H_
#define _STRUCTS_H_

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

#endif