#include "arquivos.h"


Nodo* converte_ABP(FILE *arq) {
    
    rewind(arq);

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

void cria_relatorio(char arq[], ARVORE_INFO arvores[], int numero_arvores){
    FILE *arquivo;
    arquivo = fopen(arq, "w");

    fprintf(arquivo, "Tempo total estimado: %.2f horas\n\n", horas_totais);
    for(int i = 0; i < numero_arvores; i++)
    {
    fprintf(arquivo, "======== ESTATÍSTICAS %s ============\n", arvores[i].nome);
    fprintf(arquivo, "Número de Nodos: %d\n", arvores[i].numero_nodos);
    fprintf(arquivo, "Altura: %d\n", arvores[i].altura);
    fprintf(arquivo, "Rotações: %d\n", arvores[i].rotacoes);
    fprintf(arquivo, "Comparações: %d\n\n", arvores[i].comparacoes);
    }
    


    fclose(arquivo);

}
