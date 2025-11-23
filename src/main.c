#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <time.h>
#include "arvores.h"
#include "arquivos.h"

//ctrl + shift + b
// .\src\output\main.exe .\data\dataset.csv .\data\lista_jogador1.txt .\data\saida_lista.txt
void f(Nodo* ar, FILE* arq)
    {
        if(!ar) return;
        f(ar->dir, arq);
        fprintf(arq, "%s,%.2f\n", ar->jogo, ar->horas);
        f(ar->esq, arq);

    }

int main(int argc, char *argv[]) //argc conta o número de parâmetros e argv armazena as strings correspondentes aos parâmentros digitados
{
    if (argc!=4) {
        printf ("Numero incorreto de parametros.\n Para chamar o programa digite: exemplo <arq_entrada.csv> <arq_entrada.txt> <arq_saida.txt>\n");
        return 1;
    }

    FILE * lista_jogos_steam;
    FILE * lista_jogos_jogador;

    ARVORE_INFO arvores[5];
    int numero_arvores = 0;

    lista_jogos_steam = fopen (argv[1], "r"); 
    lista_jogos_jogador = fopen (argv[2], "r"); 
        
    if (lista_jogos_steam == NULL) {
        printf ("Erro ao abrir o arquivo %s",argv[1]);
        return 1;
    }

    if (lista_jogos_jogador == NULL) {
        printf ("Erro ao abrir o arquivo %s",argv[2]);
        return 1;
    }


    // cria arvores com os jogos do arquivo
    arvores[numero_arvores++] = gera_info(converte_ABP(lista_jogos_steam), "ABP");
    //arvores[numero_arvores++] = gera_info(converte_AVL(lista_jogos_steam), "AVL");
    //arvores[numero_arvores++] = gera_info(converte_SPLAY(lista_jogos_steam), "SPLAY");
    //arvores[numero_arvores++] = gera_info(converte_RN(lista_jogos_steam), "RUBRO-NEGRA");


    

    consulta_lista_jogador(lista_jogos_jogador, arvores, numero_arvores); // consulta os jogos e preenche a lista de árvores com as informações 
    
    cria_relatorio(argv[3], arvores, numero_arvores); // cria arquivo com o relatório

    // deleta tudo depois de usar 
    destroi_arvores(arvores, numero_arvores);

    fclose (lista_jogos_steam); 
    fclose (lista_jogos_jogador);

        return 0;
    }



