#include "arquivos.h"


Nodo* converte_ABP(FILE *arq) {
    
    Nodo *arvore = NULL;
    char jogo_info[256];
    char titulo[256];
    float horas;
    char *token;

    while (fgets(jogo_info, sizeof(jogo_info), arq)) {
        // remover \n do final
        jogo_info[strcspn(jogo_info, "\r\n")] = '\0';

        token = strtok(jogo_info, ",");
        strcpy(titulo, token);
        // nome do jogo,<hora>
        token = strtok(NULL, ",");

        horas = strtof(token, NULL);   // função que converte string pra float

        arvore = ABP_insere(arvore, titulo, horas);
    }

    return arvore;
}

