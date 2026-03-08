#include "Alteracao_de_dados.h"

void adicionar_aluno(ALUN* info_alunos) {
    printf("Insira o nome do aluno: ");
    
    char nome[50];
    fgets(nome, 50, stdin);

    nome[strcspn(nome, "\n")] = '\0';

    printf("\nInsira a turma: ");

    int turma;
    scanf("%d", &turma);
    getchar();

    printf("\n");

    info_alunos->quantidade++;
    realocar_memoria_alunos(info_alunos);

    sprintf(info_alunos->nome[info_alunos->quantidade-1], nome);
    info_alunos->turma[info_alunos->quantidade-1] = turma;
}

void retirar_aluno(ALUN* info_alunos) {
    printf("Insira o índice do aluno a ser retirado: ");

    int indice;
    scanf("%d", &indice);
    getchar();

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
    scanf("%d", &indice);
    getchar();

    printf("\nQual turma ele irá: ");
    
    int turma_nova;
    scanf("%d", &turma_nova);
    getchar();

    printf("\n");

    info_alunos->turma[indice] = turma_nova;
}

void alterar_alunos(ALUN* info_alunos) {
    printf("Deseja alterar algo?\n");
    printf("(1)Adicionar aluno\n(2)Retirar aluno\n(3)Alterar turma de um aluno\n(0)Sair\n");
    printf("Escolha: ");

    unsigned short escolha = 0;
    scanf("%hu", &escolha);
    getchar();
    printf("\n");

    switch (escolha)
    {
    case 1:
        adicionar_aluno(info_alunos);
        break;
    
    case 2:
        retirar_aluno(info_alunos);
        break;

    case 3:
        alterar_turma(info_alunos);
        break;

    default:
        break;
    }
}

void adicionar_professor(PROF* info_professores) {
    printf("Insira o nome do professor: ");

    char nome[50];
    fgets(nome, 50, stdin);

    nome[strcspn(nome, "\n")] = '\0';

    printf("\nInsira a matéria que ele lecionará: ");

    char materia[50];
    fgets(materia, 50, stdin);

    materia[strcspn(materia, "\n")] = '\0';

    printf("\n");

    info_professores->quantidade++;

    realocar_memoria_professores(info_professores);

    sprintf(info_professores->nome[info_professores->quantidade-1], nome);
    sprintf(info_professores->materia[info_professores->quantidade-1], materia);
}

void retirar_professor(PROF* info_professores) {
    printf("Insira o índice do professor a ser retirado: ");

    int indice;
    scanf("%d", &indice);
    getchar();

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
    scanf("%d", &indice);
    getchar();

    printf("\nQual matéria ele irá lecionar: ");
    
    char materia_nova[50];
    fgets(materia_nova, 50, stdin);

    materia_nova[strcspn(materia_nova, "\n")] = '\0';

    printf("\n");

    sprintf(info_professores->materia[indice], materia_nova);
}

void alterar_professores(PROF* info_professores) {
    printf("Deseja alterar algo?\n");
    printf("(1)Adicionar professor\n(2)Retirar professor\n(3)Alterar matéria lecionada\n(0)Sair\n");
    printf("Escolha: ");

    unsigned short escolha = 0;
    scanf("%hu", &escolha);
    getchar();
    printf("\n");

    switch (escolha)
    {
    case 1:
        adicionar_professor(info_professores);
        break;
    
    case 2:
        retirar_professor(info_professores);
        break;

    case 3:
        alterar_materia(info_professores);
        break;

    default:
        break;
    }
}