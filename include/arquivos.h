#include "arvores.h"
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

void normaliza_string(char *s); // põe as string todas minúsculas para que a aplicação não fique case-sensitive

Nodo* converte_Arvore(FILE *arq, int tipo); // recebe o arquivo csv e retorna uma arvore do tipo especificado com os jogos ordenados por ordem alfabética

void cria_relatorio(char arq[], ARVORE_INFO arvores[], int numero_arvores);

void consulta_lista_jogador(FILE *lista_jogos_jogador, ARVORE_INFO arvores[], int numero_arvores);