#include "Gerenciamento_de_structs.h"

#define TAMANHO_NOME 50
#define CHECK_ERRO(x) if(x) goto final;

int alocar_memoria(void** ponteiro, size_t tamanho, int qtd) {
    *ponteiro = calloc(tamanho, qtd);
    if (*ponteiro == NULL) return 1;
    return 0;
}

int realocar_memoria(void** ponteiro, size_t tamanho_novo) {
    void* temp = meu_realloc(*ponteiro, tamanho_novo);

    if (temp == NULL) return 1;

    *ponteiro = temp;
    return 0;
}

int alocar_memoria_alunos(ALUN* info_alunos) {
    int controle = 0;

    int qtd = info_alunos->quantidade;

    controle = alocar_memoria((void**)&info_alunos->nome, sizeof(char*), qtd);
    CHECK_ERRO(controle);
    controle = alocar_memoria((void**)&info_alunos->turma, sizeof(int), qtd);
    CHECK_ERRO(controle);

    for (int i=0; i<qtd; i++) {
        controle = alocar_memoria((void**)&info_alunos->nome[i], sizeof(char), TAMANHO_NOME);
        CHECK_ERRO(controle);
    }
    CHECK_ERRO(controle);

    final:
        return controle;
}

int alocar_memoria_professores(PROF* info_professores) {
    int controle = 0;

    int qtd = info_professores->quantidade;

    controle = alocar_memoria((void**)&info_professores->nome, sizeof(char*), qtd);
    CHECK_ERRO(controle);
    controle = alocar_memoria((void**)&info_professores->materia, sizeof(char*), qtd);
    CHECK_ERRO(controle);

    for (int i=0; i<qtd; i++) {
        controle = alocar_memoria((void**)&info_professores->nome[i], sizeof(char), TAMANHO_NOME);
        CHECK_ERRO(controle);
    }

    for (int i=0; i<qtd; i++){
        controle = alocar_memoria((void**)&info_professores->materia[i], sizeof(char), TAMANHO_NOME);
        CHECK_ERRO(controle);
    }

    final:
        return controle;
}

int realocar_memoria_alunos(ALUN* info_alunos) {
    int controle = 0;

    int qtd = info_alunos->quantidade;
    
    controle = realocar_memoria((void**)&info_alunos->nome, sizeof(char*) * qtd);
    CHECK_ERRO(controle);
    controle = realocar_memoria((void**)&info_alunos->turma, sizeof(int) * qtd);
    CHECK_ERRO(controle);

    controle = alocar_memoria((void**)&info_alunos->nome[qtd-1], sizeof(char), TAMANHO_NOME);
    CHECK_ERRO(controle);

    final:
        return controle;
}

int realocar_memoria_professores(PROF* info_professores) {
    int controle = 0;

    int qtd = info_professores->quantidade;
    
    controle = realocar_memoria((void**)&info_professores->nome, sizeof(char*) * qtd);
    CHECK_ERRO(controle);
    controle = realocar_memoria((void**)&info_professores->materia, sizeof(char*) * qtd);
    CHECK_ERRO(controle);

    controle = alocar_memoria((void**)&info_professores->nome[qtd-1], sizeof(char), TAMANHO_NOME);
    CHECK_ERRO(controle);
    controle = alocar_memoria((void**)&info_professores->materia[qtd-1], sizeof(char), TAMANHO_NOME);
    CHECK_ERRO(controle);

    final:
        return controle;
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