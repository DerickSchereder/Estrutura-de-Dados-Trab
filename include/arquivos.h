#include "arvores.h"
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

void normaliza_string(char *s); // põe as string todas minúsculas para que a aplicação não fique case-sensitive

Nodo* converte_ABP(FILE *arq); // recebe o arquivo csv e retorna uma ABP os jogos por ordem alfabética

Nodo* converte_AVL(FILE *arq); // recebe o arquivo csv e retorna uma ABP os jogos por ordem alfabética

void cria_relatorio(char arq[], ARVORE_INFO arvores[], int numero_arvores);

void consulta_lista_jogador(FILE *lista_jogos_jogador, ARVORE_INFO arvores[], int numero_arvores);