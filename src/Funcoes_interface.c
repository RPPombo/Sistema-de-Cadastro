#include "Funcoes_interface.h"

void abertura_do_programa() {
    printf("-------------------------------\n");
    printf("--Sistema de Cadastro Escolar--\n");
    printf("-------------------------------\n\n");
}

unsigned short escolher_acao() {
    printf("Qual banco de dados deseja ver?\n");
    printf("(1)Ver Alunos\n(2)Ver Professores\n(0)Sair\n");
    printf("Escolha: ");

    unsigned short escolha;

    escolha = ler_escolha();

    return escolha;
}

void mostrar_alunos(ALUN info_alunos) {
    printf("---------------------\n");
    printf("Total de alunos: %d\n\n", info_alunos.quantidade);

    printf("Índice | Nome do aluno | Turma\n");

    for (int i=0; i<info_alunos.quantidade; i++) {
        printf("%d | %s | %d\n", i, info_alunos.nome[i], info_alunos.turma[i]);
    }

    printf("\n");
}

void mostrar_professores(PROF info_professores) {
    printf("---------------------\n");
    printf("Total de professores: %d\n\n", info_professores.quantidade);

    printf("Índice | Nome do professor | Matéria Lecionada\n");

    for (int i=0; i<info_professores.quantidade; i++) {
        printf("%d | %s | %s\n", i, info_professores.nome[i], info_professores.materia[i]);
    }

    printf("\n");
}