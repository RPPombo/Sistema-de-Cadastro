#include "Ordem_alfabetica.h"

int comparar_elementos(const void *a, const void *b){
    char *const *str1 = a;
    char *const *str2 = b;
    return strcmp(*str1, *str2);
}

ALUN ordenar_alfabeticamente_alunos(ALUN info_alunos) {
    ALUN copia;
    copia.quantidade = info_alunos.quantidade;

    alocar_memoria_alunos(&copia);

    for (int i=0; i<copia.quantidade; i++) {
        strcpy(copia.nome[i], info_alunos.nome[i]);
    }

    qsort(copia.nome, copia.quantidade, sizeof(char*), comparar_elementos);

    int usado[copia.quantidade];

    for (int i=0; i<copia.quantidade; i++)
        usado[i] = 0;

    for (int i=0; i<info_alunos.quantidade; i++) {
        for (int j=0; j<copia.quantidade; j++) {

            if (strcmp(copia.nome[j], info_alunos.nome[i]) == 0 && !usado[j]) {
                copia.turma[j] = info_alunos.turma[i];
                usado[j] = 1;
                break;
            }

        }
    }

    return copia;
}

PROF ordenar_alfabeticamente_professores(PROF info_professores) {
    PROF copia;
    copia.quantidade = info_professores.quantidade;

    alocar_memoria_professores(&copia);

    for (int i = 0; i < copia.quantidade; i++) {
        strcpy(copia.nome[i], info_professores.nome[i]);
    }

    qsort(copia.nome, copia.quantidade, sizeof(char*), comparar_elementos);

    int usado[copia.quantidade];

    for (int i=0; i<copia.quantidade; i++)
        usado[i] = 0;

    for (int i=0; i<info_professores.quantidade; i++) {
        for (int j=0; j<copia.quantidade; j++) {

            if (strcmp(copia.nome[j], info_professores.nome[i]) == 0 && !usado[j]) {
                strcpy(copia.materia[j], info_professores.materia[i]);
                usado[j] = 1;
                break;
            }

        }
    }

    return copia;
}