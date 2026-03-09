#include "Salvamento_de_arquivo.h"

#define ARQ_ALUNOS "./data/alunos.txt"
#define ARQ_PROFESSORES "./data/professores.txt"
#define TMP_ALUNOS "./data/alunos.tmp"
#define TMP_PROFESSORES "./data/professores.tmp"

void salvar_arquivos_professores(PROF info_professores) {
    FILE* f;
    f = fopen(TMP_PROFESSORES, "w");

    int qtd = info_professores.quantidade;

    fprintf(f, "Quantidade: %d\n", qtd);

    for (int i = 0; i<qtd; i++) {
        fprintf(f, "%s | %s\n", info_professores.nome[i], info_professores.materia[i]);
    }

    fclose(f);

    remove("./data/professores.txt");
    if (rename("./data/professores.tmp", "./data/professores.txt") != 0) {
        printf("Erro na renomeação de arquivo! %s -> %s\n", TMP_PROFESSORES, ARQ_PROFESSORES);
    }

    printf("Arquivo de professores salvo!\n");
}

void salvar_arquivo_alunos(ALUN info_alunos) {
    FILE* f;
    f = fopen("./data/alunos.tmp", "w");

    int qtd = info_alunos.quantidade;

    fprintf(f, "Quantidade: %d\n", qtd);

    for (int i=0; i<qtd; i++) {
        fprintf(f, "%s | %d\n", info_alunos.nome[i], info_alunos.turma[i]);
    }

    fclose(f);

    remove("./data/alunos.txt");
    if (rename("./data/alunos.tmp", "./data/alunos.txt") != 0) {
        printf("Erro na renomeação de arquivo! %s -> %s\n", TMP_ALUNOS, ARQ_PROFESSORES);
    }

    printf("Arquivo de alunos salvo!\n");
}

void salvar_arquivos(ALUN info_alunos, PROF info_professores) {
    salvar_arquivo_alunos(info_alunos);
    salvar_arquivos_professores(info_professores);
}