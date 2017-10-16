#include "stdafx.h"
#include <iostream>
#include "Flood.h"

using namespace std;

/*
Constante para definir o raio maximo de alcance do virus
*/
const int LIMITE_MAX_LINHA_COLUNA_VIRUS = 1;

/*
Constante para definir o raio minimo de alcance do virus
*/
const int LIMITE_MIN_LINHA_COLUNA_VIRUS = -1;

/*
Fun��o para verificar se a posi��o do array � igual a VAZIO, retorno verdadeiro ou falso.
*/
bool posicaoVazio(int linha, int coluna, char campo[][QUANTIDADE_COLUNAS]) {
	return campo[linha][coluna] == VAZIO;
}

/*
Fun��o recursiva para fazer a prolifera��o do v�rus no array, utilizando a prolifera��o natural (casa por casa),
Precisa da linha, coluna e o array com coluna fixa na constante QUANTIDADE_COLUNA.
*/
void virus(int linha, int coluna, char campo[][QUANTIDADE_COLUNAS]) {
	for (int linhaAux = LIMITE_MIN_LINHA_COLUNA_VIRUS; linhaAux <= LIMITE_MAX_LINHA_COLUNA_VIRUS; linhaAux++) {
		for (int colunaAux = LIMITE_MIN_LINHA_COLUNA_VIRUS; colunaAux <= LIMITE_MAX_LINHA_COLUNA_VIRUS; colunaAux++) {
			if (posicaoVazio(linha + linhaAux, coluna + colunaAux, campo)) {
				campo[linha + linhaAux][coluna + colunaAux] = VIRUS;
				virus(linha + linhaAux, coluna + colunaAux, campo);
			}
		}
	}
}

/*
Fun��o para marcar o VIRUS em uma posi��o determinada (Apenas para testar a fun��o virus)
*/
void  marcarVirus(int linha, int coluna, char campo[][QUANTIDADE_COLUNAS]) {
	campo[linha][coluna] = VIRUS;
}