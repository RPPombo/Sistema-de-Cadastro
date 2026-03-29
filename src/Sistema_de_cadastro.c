#include "Sistema_de_cadastro.h"

ALUN info_alunos;
ALUN info_alunos_copia;
PROF info_professores;
PROF info_professores_copia;

int main() {
    int erro_realoc = 0;
    info_alunos.quantidade = 0;
    info_professores.quantidade = 0;

    abertura_do_programa();
    if (carregar_alunos(&info_alunos)) {
        erro_alocacao(&info_alunos, &info_professores);
    }
    
    if (carregar_professores(&info_professores)){
        erro_alocacao(&info_alunos, &info_professores);
    }

    info_alunos_copia = info_alunos;
    info_professores_copia = info_professores;

    unsigned short escolha;
    unsigned short fechar = 0;

    while (!fechar){
        unsigned short voltar = 0;
        escolha = escolher_acao();

        switch (escolha)
        {
        case 1:
            while (!voltar){
                mostrar_alunos(info_alunos);
                salvar_arquivo_aluno_bckp(info_alunos);
                voltar = alterar_alunos(&info_alunos, &erro_realoc);
            }
            printf("\n");
            break;

        case 2:
            while (!voltar){
                mostrar_professores(info_professores);
                salvar_arquivo_professor_bckp(info_professores);
                voltar = alterar_professores(&info_professores, &erro_realoc);
            }
            printf("\n");
            break;
            
        default:
            fechar = 1;
            break;
        }

        if (erro_realoc) {
            erro_realocacao(&info_alunos, &info_professores);
        }
    }

    salvar_arquivos(info_alunos, info_professores);

    liberar_memoria_structs(&info_alunos, &info_professores);
}