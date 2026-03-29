#include "Tratamento_de_erros.h"

#define ERRO_ALOCACAO 1
#define ERRO_REALOCACAO 2

void erro_alocacao(ALUN* info_alunos, PROF* info_professores) {
    printf("Erro na alocação de memória!\n");

    liberar_memoria_structs(info_alunos, info_professores);

    exit(ERRO_ALOCACAO);
}

void erro_realocacao(ALUN* info_alunos, PROF* info_professores) {
    printf("Erro na realocação de memória!\n");

    printf("Verifique os backups dos arquivos!\n");
    
    liberar_memoria_structs(info_alunos, info_professores);

    exit(ERRO_REALOCACAO);
}