#include "Busca_nomes.h"

void bsucar_aluno(ALUN info_alunos) {
    printf("Escreva o nome do aluno: ");

    char nome[50];
    ler_string(50, nome);

    printf("\nResultado da pesquisa:\n");

    for (int aluno = 0; aluno<info_alunos.quantidade; aluno++) {
        int achou = 0;
        for (size_t caractere = 0; caractere<strlen(nome); caractere++){
            if (info_alunos.nome[aluno][caractere] == nome[caractere]){
                achou = 1;
            } else {
                break;
            }
        }

        if (achou) {
            printf("%s | %d\n", info_alunos.nome[aluno], info_alunos.turma[aluno]);
        }
    }
    printf("\n");
}

void buscar_professor(PROF info_professores) {
    printf("Escreva o nome do professor: ");

    char nome[50];
    ler_string(50, nome);

    printf("\nResultado da pesquisa:\n");

    for (int professor = 0; professor<info_professores.quantidade; professor++) {
        int achou = 0;
        for (size_t caractere = 0; caractere<strlen(nome); caractere++){
            if (info_professores.nome[professor][caractere] == nome[caractere]){
                achou = 1;
            } else {
                break;
            }
        }

        if (achou) {
            printf("%s | %s\n", info_professores.nome[professor], info_professores.materia[professor]);
        }
    }
    printf("\n");
}