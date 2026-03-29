#include "Salvamento_de_arquivo.h"

#define ARQ_ALUNOS "./data/alunos.txt"
#define ARQ_PROFESSORES "./data/professores.txt"
#define TMP_ALUNOS "./data/alunos.tmp"
#define TMP_PROFESSORES "./data/professores.tmp"
#define BCKP_ALUNOS "./data/alunos_bckp.txt"
#define BCKP_PROFESSORES "./data/professores_bckp.txt"

void salvar_arquivo_professores(PROF info_professores) {
    FILE* f;
    f = fopen(TMP_PROFESSORES, "w");

    int qtd = info_professores.quantidade;

    fprintf(f, "Quantidade: %d\n", qtd);

    for (int i = 0; i<qtd; i++) {
        fprintf(f, "%s|%s\n", info_professores.nome[i], info_professores.materia[i]);
    }

    fclose(f);

    remove(ARQ_PROFESSORES);
    if (rename(TMP_PROFESSORES, ARQ_PROFESSORES) != 0) {
        printf("Erro na renomeação de arquivo! %s -> %s\n", TMP_PROFESSORES, ARQ_PROFESSORES);
    }

    printf("Arquivo de professores salvo!\n");
}

void salvar_arquivo_alunos(ALUN info_alunos) {
    FILE* f;
    f = fopen(TMP_ALUNOS, "w");

    int qtd = info_alunos.quantidade;

    fprintf(f, "Quantidade: %d\n", qtd);

    for (int i=0; i<qtd; i++) {
        fprintf(f, "%s|%d\n", info_alunos.nome[i], info_alunos.turma[i]);
    }

    fclose(f);

    remove(ARQ_PROFESSORES);
    if (rename(TMP_ALUNOS, ARQ_ALUNOS) != 0) {
        printf("Erro na renomeação de arquivo! %s -> %s\n", TMP_ALUNOS, ARQ_ALUNOS);
    }

    printf("Arquivo de alunos salvo!\n");
}

void salvar_arquivos(ALUN info_alunos, PROF info_professores) {
    salvar_arquivo_alunos(info_alunos);
    salvar_arquivo_professores(info_professores);
}

void salvar_arquivo_aluno_bckp(ALUN info_alunos) {
    FILE* f;
    f = fopen(BCKP_ALUNOS, "w");

    int qtd = info_alunos.quantidade;

    fprintf(f, "Quantidade: %d\n", qtd);

    for (int i=0; i<qtd; i++) {
        fprintf(f, "%s|%d\n", info_alunos.nome[i], info_alunos.turma[i]);
    }

    fclose(f);
}

void salvar_arquivo_professor_bckp(PROF info_professores) {
    FILE* f;

    f = fopen(BCKP_PROFESSORES, "w");

    int qtd = info_professores.quantidade;

    fprintf(f, "Quantidade: %d\n", qtd);

    for (int i = 0; i<qtd; i++) {
        fprintf(f, "%s|%s\n", info_professores.nome[i], info_professores.materia[i]);
    }

    fclose(f);
}