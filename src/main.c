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
    if (argc!=3) 
    {
        printf ("Numero incorreto de parametros.\n Para chamar o programa digite: exemplo <arq_entrada> <arq_saida>\n");
        return 1;
    }
    
    clock_t start, end; 

    FILE * lista_jogos_steam;
    FILE * lista_jogos_jogador;

    char jogo_jogador[256];

    Nodo *ABP = NULL;
    ARVORE_INFO arvores[4];


    lista_jogos_steam = fopen (argv[1], "r"); 
        
    if (lista_jogos_steam == NULL) 
    {
        printf ("Erro ao abrir o arquivo %s",argv[1]);
        return 1;
    }

    lista_jogos_jogador = fopen (argv[2], "r"); 
        
    if (lista_jogos_jogador == NULL) 
    {
        printf ("Erro ao abrir o arquivo %s",argv[2]);
        return 1;
    }



    start = clock(); 

    ABP = converte_ABP(lista_jogos_steam); // cria uma ABP com os jogos do arquivo

    while(fgets(jogo_jogador, sizeof(jogo_jogador), lista_jogos_jogador))
    {
        jogo_jogador[strcspn(jogo_jogador, "\r\n")] = '\0';  
        consulta(ABP, jogo_jogador); 
        
    } // consulta cada jogo na lista do jogador

    end = clock(); 

    cria_relatorio("saida_lista.txt", arvores, sizeof(arvores)/sizeof(ARVORE_INFO));

        
    // deleta tudo depois de usar 
    destroi(ABP);

    fclose (lista_jogos_steam); 
    fclose (lista_jogos_jogador);

        return 0;
    }



