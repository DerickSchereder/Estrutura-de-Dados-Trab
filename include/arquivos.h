#include "arvores.h"
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>


Nodo* converte_ABP(FILE *arq); // recebe o arquivo csv e retorna uma ABP os jogos por ordem alfabética

void cria_relatorio(char arq[], ARVORE_INFO arvores[], int numero_arvores);