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
        escolha = escolher_acao();

        switch (escolha)
        {
        case 1:
            mostrar_alunos(info_alunos);
            alterar_alunos(&info_alunos);
            break;

        case 2:
            mostrar_professores(info_professores);
            alterar_professores(&info_professores);
            break;
            
        default:
            fechar = 1;
            break;
        }
    }

    liberar_memoria_structs(&info_alunos, &info_professores);
}