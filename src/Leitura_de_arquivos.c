#include "Leitura_de_arquivos.h"

FILE* carregar_arquivo(char* nome_do_arquivo) {
    char caminho[50];
    sprintf(caminho, "./data/%s", nome_do_arquivo);

    FILE* f;
    f = fopen(caminho, "r");

    if (f == 0) {
        printf("Arquivo %s não encontrado! Criando um novo!\n", nome_do_arquivo);

        f = fopen(caminho, "w");
        fprintf(f, "Quantidade: 0\n");
        fclose(f);

        f = fopen(caminho, "r");
    }
    
    return f;
}

void carregar_alunos(ALUN* info_alunos) {
    FILE* f;
    f = carregar_arquivo("alunos.txt");

    fscanf(f, "Quantidade: %d", &info_alunos->quantidade);

    alocar_memoria_alunos(info_alunos);

    for (int i=0; i<info_alunos->quantidade; i++) {
        fscanf(f, "%s | %d", info_alunos->nome[i], &info_alunos->turma[i]);
    }

    fclose(f);
}

void carregar_professores(PROF* info_professores) {
    FILE* f;
    f = carregar_arquivo("professores.txt");

    fscanf(f, "Quantidade: %d", &info_professores->quantidade);

    alocar_memoria_professores(info_professores);

    for (int i=0; i<info_professores->quantidade; i++) {
        fscanf(f, "%s | %s", info_professores->nome[i], info_professores->materia[i]);
    
    }

    fclose(f);
}