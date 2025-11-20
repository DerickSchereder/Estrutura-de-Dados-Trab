#include "arquivos.h"


Nodo* converte_ABP(FILE *arq) {
    
    Nodo *arvore = NULL;
    char jogo_info[256];
    char titulo[256];
    float horas;
    char *token;
    
    while (fgets(jogo_info, sizeof(jogo_info), arq)) {
        // jogo_info = <nome do jogo>,<hora>
        // remover \n do final
        jogo_info[strcspn(jogo_info, "\r\n")] = '\0';
        
        token = strtok(jogo_info, ","); // token = <nome do jogo>
        strcpy(titulo, token);

        token = strtok(NULL, ","); // token = <hora>
        horas = strtof(token, NULL);   // função que converte string pra float

        arvore = ABP_insere(arvore, titulo, horas);
    } // insere cada arquivo do csv em uma ABP

    return arvore;
}

void cria_relatorio(char arq[]){
    FILE *arquivo;
    arquivo = fopen(arq, "w");
    fprintf(arquivo, "Tempo total estimado: %f horas\n\n", horas_totais);
    fprintf(arquivo, "======== ESTATÍSTICAS ABP ============\n");
    fprintf(arquivo, "Número de Nodos: %d\n", numero_nodos);
    fprintf(arquivo, "Altura: \n");
    fprintf(arquivo, "Rotações: \n");
    fprintf(arquivo, "Comparações: %d\n\n", comp);
    


    fclose(arquivo);

}
