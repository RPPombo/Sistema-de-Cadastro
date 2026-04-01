#include "Alteracao_de_dados.h"

int adicionar_aluno(ALUN* info_alunos) {
    int erro = 0;

    printf("Insira o nome do aluno: ");
    
    char nome[50];
    ler_string(50, nome);

    printf("\nInsira a turma(número): ");

    int turma;
    turma = ler_int();

    printf("\n");

    info_alunos->quantidade++;
    
    erro = realocar_memoria_alunos(info_alunos);

    if (erro) {
        goto final;
    }

    snprintf(info_alunos->nome[info_alunos->quantidade-1], 50, "%s", nome);
    info_alunos->turma[info_alunos->quantidade-1] = turma;

    final:
        return erro;
}

void retirar_aluno(ALUN* info_alunos) {
    printf("Insira o índice do aluno a ser retirado: ");

    int indice;
    indice = ler_int();

    printf("\n");

    free(info_alunos->nome[indice]);

    for (int i = indice; i < info_alunos->quantidade - 1; i++) {
        info_alunos->nome[i] = info_alunos->nome[i+1];
        info_alunos->turma[i] = info_alunos->turma[i+1];
    }

    info_alunos->quantidade--;
}

void alterar_turma(ALUN* info_alunos) {
    printf("Insira o índice do aluno que deseja alterar a turma: ");

    int indice;
    indice = ler_int();

    printf("\nQual turma ele irá: ");
    
    int turma_nova;
    turma_nova = ler_int();

    printf("\n");

    info_alunos->turma[indice] = turma_nova;
}

unsigned short alterar_alunos(ALUN* info_alunos, int* erro) {
    unsigned short voltar = 0;
    printf("Deseja alterar algo?\n");
    printf("(1)Adicionar aluno\n(2)Retirar aluno\n(3)Alterar turma de um aluno\n(4)Buscar Aluno\n(0)Sair\n");
    printf("Escolha: ");

    unsigned short escolha = 0;
    escolha = ler_escolha();

    switch (escolha)
    {
    case 1:
        if (adicionar_aluno(info_alunos)) {
            *erro = 1;
            voltar = 1;
        }
        break;
    
    case 2:
        retirar_aluno(info_alunos);
        break;

    case 3:
        alterar_turma(info_alunos);
        break;

    case 4:
        bsucar_aluno(*info_alunos);
        break;

    default:
        voltar = 1;
        break;
    }
    return voltar;
}


int adicionar_professor(PROF* info_professores) {
    int erro = 0;

    printf("Insira o nome do professor: ");

    char nome[50];
    ler_string(50, nome);

    printf("\nInsira a matéria que ele lecionará: ");

    char materia[50];
    ler_string(50, materia);

    printf("\n");

    info_professores->quantidade++;

    erro = realocar_memoria_professores(info_professores);

    if (erro) {
        goto final;
    }

    snprintf(info_professores->nome[info_professores->quantidade-1], 50, "%s", nome);
    snprintf(info_professores->materia[info_professores->quantidade-1], 50, "%s", materia);

    final:
        return erro;
}

void retirar_professor(PROF* info_professores) {
    printf("Insira o índice do professor a ser retirado: ");

    int indice;
    indice = ler_int();

    printf("\n");

    free(info_professores->nome[indice]);
    free(info_professores->materia[indice]);

    for (int i = indice; i < info_professores->quantidade - 1; i++) {
        info_professores->nome[i] = info_professores->nome[i+1];
        info_professores->materia[i] = info_professores->materia[i+1];
    }

    info_professores->quantidade--;
}

void alterar_materia(PROF* info_professores) {
    printf("Insira o índice do professor que deseja alterar a matéria: ");

    int indice;
    indice = ler_int();

    printf("\nQual matéria ele irá lecionar: ");
    
    char materia_nova[50];
    ler_string(50, materia_nova);

    printf("\n");

    snprintf(info_professores->materia[indice], 50, "%s", materia_nova);
}

unsigned short alterar_professores(PROF* info_professores, int* erro) {
    unsigned short voltar = 0;

    printf("Deseja alterar algo?\n");
    printf("(1)Adicionar professor\n(2)Retirar professor\n(3)Alterar matéria lecionada\n(4)Buscar Professor\n(0)Sair\n");
    printf("Escolha: ");

    unsigned short escolha = 0;
    escolha = ler_escolha();

    printf("\n");

    switch (escolha)
    {
    case 1:
        if (adicionar_professor(info_professores)) {
            *erro = 1;
            voltar = 1;
        }
        break;
    
    case 2:
        retirar_professor(info_professores);
        break;

    case 3:
        alterar_materia(info_professores);
        break;

    case 4:
        buscar_professor(*info_professores);
        break;

    default:
        voltar = 1;
        break;
    }

    return voltar;

}