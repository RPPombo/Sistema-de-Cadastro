#include "Sistema_de_cadastro.h"

ALUN info_alunos;
PROF info_professores;

int main() {
    carregar_alunos(&info_alunos);
    carregar_professores(&info_professores);

    int escolha;
    int fechar = 0;

    /*while (!fechar){
        escolha = escolher_acao();

        switch (escolha)
        {
        case 1:
            mostrar_alunos();
            alterar_alunos();
            break;

        case 2:
            mostrar_professores();
            alterar_professores();
            break;
            
        default:
            fechar = 1;
            break;
        }

    }*/
}