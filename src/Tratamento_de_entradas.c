#include "Tratamento_de_entradas.h"

unsigned short ler_escolha() {
    char buffer[50];
    unsigned short valor;

    while (1){
        fgets(buffer, sizeof(buffer), stdin);

        if (sscanf(buffer, "%hu", &valor) ==1) {
            return valor;
        } else {
            printf("\nEntrada inválida!\nEscolha: ");
        }
    }
}

int ler_int() {
    char buffer[50];
    int valor;

    while (1){
        fgets(buffer, sizeof(buffer), stdin);

        if (sscanf(buffer, "%d", &valor) ==1){
            return valor;
        } else {
            printf("\nEntrada inválida!\nInsira um número: ");
        }
    }
    
}

void ler_string(int tamanho, char string[tamanho]) {
    char buffer[tamanho];

    while (1) {
        fgets(buffer, sizeof(buffer), stdin);

        buffer[strcspn(buffer, "\n")] = '\0';

        if (strlen(buffer) > 0) {
            strncpy(string, buffer, tamanho);
            string[tamanho - 1] = '\0'; 
            return;
        }

        printf("\nA entrada não pode ser vazia!\nDigite novamente: ");
    }
}