#include "Sistema_de_cadastro.h"

ALUN info_alunos;
PROF info_professores;

int main() {
    abertura_do_programa();

    carregar_alunos(&info_alunos);
    carregar_professores(&info_professores);

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
                voltar = alterar_alunos(&info_alunos);
            }
            printf("\n");
            break;

        case 2:
            while (!voltar){
                mostrar_professores(info_professores);
                alterar_professores(&info_professores);
            }
            printf("\n");
            break;
            
        default:
            fechar = 1;
            break;
        }
    }

    salvar_arquivos(info_alunos, info_professores);

    liberar_memoria_structs(&info_alunos, &info_professores);
}