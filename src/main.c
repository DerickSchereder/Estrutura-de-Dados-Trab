#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <time.h>
#include "arvores.h"
#include "arquivos.h"

//ctrl + shift + b
//.\src\output\main.exe .\data\dataset.csv .\data\lista_jogador1.txt


int main(int argc, char *argv[]) //argc conta o número de parâmetros e argv armazena as strings correspondentes aos parâmentros digitados
{
    if (argc!=4) {
        printf ("Numero incorreto de parametros.\n Para chamar o programa digite: exemplo <arq_entrada.csv> <arq_entrada.txt> <arq_saida.txt>\n");
        return 1;
    }
    
    FILE * lista_jogos_steam;
    FILE * lista_jogos_jogador;

    char jogo_jogador[256];


    ARVORE_INFO arvores[5];
    int numero_arvores = 0;


    lista_jogos_steam = fopen (argv[1], "r"); 
        
    if (lista_jogos_steam == NULL) {
        printf ("Erro ao abrir o arquivo %s",argv[1]);
        return 1;
    }

    lista_jogos_jogador = fopen (argv[2], "r"); 
        
    if (lista_jogos_jogador == NULL) {
        printf ("Erro ao abrir o arquivo %s",argv[2]);
        return 1;
    }


    // cria arvores com os jogos do arquivo
    arvores[numero_arvores++] = gera_info(converte_ABP(lista_jogos_steam), "ABP");
    //arvores[numero_arvores++] = gera_info(converte_AVL(lista_jogos_steam), "ABP");
    //arvores[numero_arvores++] = gera_info(converte_SPLAY(lista_jogos_steam), "SPLAY");
    //arvores[numero_arvores++] = gera_info(converte_RN(lista_jogos_steam), "RN");


    for(int w = 0; w < numero_arvores; w++){
        while(fgets(jogo_jogador, sizeof(jogo_jogador), lista_jogos_jogador))
        {
            jogo_jogador[strcspn(jogo_jogador, "\r\n")] = '\0';  
            consulta(arvores[w].raiz, jogo_jogador); 
            
        } // consulta cada jogo na lista do jogador
    arvores[w].comparacoes = comp;
    arvores[w].numero_nodos = numero_nodos;
    arvores[w].rotacoes = 0;
    comp = 0;
    numero_nodos = 0;
    rewind(lista_jogos_jogador);
    }

    
    cria_relatorio(argv[3], arvores, numero_arvores);

        
    // deleta tudo depois de usar 
    destroi_arvores(arvores, numero_arvores);

    fclose (lista_jogos_steam); 
    fclose (lista_jogos_jogador);

        return 0;
    }



