#include "Alteracao_de_dados.h"

void alterar_alunos(ALUN* info_alunos) {
    printf("Deseja alterar algo?\n");
    printf("(1)Adicionar aluno\n(2)Retirar aluno\n(3)Alterar turma de um aluno\n(0)Sair");
    printf("Escolha: ");

    unsigned short escolha = 0;
    escolha = scanf("%d", escolha);

    switch (escolha)
    {
    case 1:
        adicionar_pessoa();
        break;
    
    case 2:
        retirar_pessoa();
        break;

    case 3:
        alterar_turma();
        break;

    default:
        break;
    }
}

void alterar_professores(PROF* info_professores) {
    printf("Deseja alterar algo?\n");
    printf("(1)Adicionar professor\n(2)Retirar professor\n(3)Alterar matéria lessionada\n(0)Sair");
    printf("Escolha: ");

    unsigned short escolha = 0;
    escolha = scanf("%d", escolha);

    switch (escolha)
    {
    case 1:
        adicionar_pessoa();
        break;
    
    case 2:
        retirar_pessoa();
        break;

    case 3:
        alterar_materia();
        break;

    default:
        break;
    }
}