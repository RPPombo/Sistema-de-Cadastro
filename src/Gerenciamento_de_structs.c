#include "Gerenciamento_de_structs.h"

#define TAMANHO_NOME 50
void alocar_memoria_alunos(ALUN* info_alunos) {
    int qtd = info_alunos->quantidade;

    info_alunos->nome = malloc(sizeof(char*) * qtd);
    info_alunos->turma = malloc(sizeof(int) * qtd);

    for (int i=0; i<qtd; i++) {
        info_alunos->nome[i] = malloc(sizeof(char) * TAMANHO_NOME);
    }
}

void alocar_memoria_professores(PROF* info_professores) {
    int qtd = info_professores->quantidade;

    info_professores->nome = malloc(sizeof(char*) * qtd);
    info_professores->materia = malloc(sizeof(char*) * qtd);

    for (int i=0; i<qtd; i++) {
        info_professores->nome[i] = malloc(sizeof(char) * TAMANHO_NOME);
    }

    for (int i=0; i<qtd; i++){
        info_professores->materia[i] = malloc(sizeof(char) * TAMANHO_NOME);
    }
    
}

void realocar_memoria_alunos(ALUN* info_alunos) {
    int qtd = info_alunos->quantidade;

    info_alunos->nome = realloc(info_alunos->nome, sizeof(char*) * qtd);
    info_alunos->turma = realloc(info_alunos->turma, sizeof(int) * qtd);

    info_alunos->nome[qtd-1] = malloc(sizeof(char) * TAMANHO_NOME);
}

void realocar_memoria_professores(PROF* info_professores) {
    int qtd = info_professores->quantidade;

    info_professores->nome = realloc(info_professores->nome, sizeof(char*) * qtd);
    info_professores->materia = realloc(info_professores->materia, sizeof(char*) * qtd);

    info_professores->nome[qtd-1] = malloc(sizeof(char) * TAMANHO_NOME);
    info_professores->materia[qtd-1] = malloc(sizeof(char) * TAMANHO_NOME);
}

void liberar_memoria_alunos(ALUN* info_alunos) {
    for (int i = 0; i < info_alunos->quantidade; i++) {
        free(info_alunos->nome[i]);
    }

    free(info_alunos->turma);
    free(info_alunos->nome);
}

void liberar_memoria_professores(PROF* info_professores) {
    for (int i = 0; i < info_professores->quantidade; i++) {
        free(info_professores->nome[i]);
        free(info_professores->materia[i]);
    }

    free(info_professores->nome);
    free(info_professores->materia);
}

void liberar_memoria_structs(ALUN* info_alunos, PROF* info_professores) {
    liberar_memoria_alunos(info_alunos);
    liberar_memoria_professores(info_professores);
}