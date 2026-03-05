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