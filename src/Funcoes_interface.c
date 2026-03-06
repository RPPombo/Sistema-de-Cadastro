#include "Funcoes_interface.h"

void abertura_do_programa() {
    printf("-------------------------------\n");
    printf("--Sistema de Cadastro Escolar--\n");
    printf("-------------------------------\n\n");
}

unsigned short escolher_acao() {
    printf("Qual banco de dados deseja fazer?\n");
    printf("(1)Ver Alunos\n(2)Ver Professores\n(0)Sair\n");
    printf("Escolha:");

    unsigned short escolha = 0;
    scanf("%d", escolha);

    printf("\n");

    return escolha;
}

void mostrar_alunos(ALUN info_alunos) {
    printf("Total de alunos: %d\n\n", info_alunos.quantidade);

    printf("Nome do aluno | Turma\n");

    for (int i=0; i<info_alunos.quantidade; i++) {
        printf("%d | %s | %d\n", i, info_alunos.nome[i], info_alunos.turma[i]);
    }

    printf("\n");
}

void mostrar_professores(PROF info_professores) {
    printf("Total de professores: %d\n\n", info_professores.quantidade);

    printf("Nome do professor | Matéria Lessionada\n");

    for (int i=0; i<info_professores.quantidade; i++) {
        printf("%d |%s | %s\n", i, info_professores.nome[i], info_professores.materia[i]);
    }

    printf("\n");
}