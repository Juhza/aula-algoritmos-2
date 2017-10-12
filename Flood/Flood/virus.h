#ifndef VIRUS_H
#define VIRUS_H  

/*
Constante para definir o raio maximo de alcance do virus
*/
const int LIMITE_MAX_LINHA_COLUNA_VIRUS = 1;

/*
Constante para definir o raio minimo de alcance do virus
*/
const int LIMITE_MIN_LINHA_COLUNA_VIRUS = -1;

/*
Função para verificar se a posição do array é igual a VAZIO, retorno verdadeiro ou falso.
*/
bool posicaoVazio(int linha, int coluna, char campo[][QUANTIDADE_COLUNAS]) {
	return campo[linha][coluna] == VAZIO;
}

/*
Função recursiva para fazer a proliferação do vírus no array, utilizando a proliferação natural (casa por casa),
Precisa da linha, coluna e o array com coluna fixa na constante QUANTIDADE_COLUNA.
*/
void virus(int linha, int coluna, char campo[][QUANTIDADE_COLUNAS]) {
	for (int linhaAux = LIMITE_MIN_LINHA_COLUNA_VIRUS; linhaAux <= LIMITE_MAX_LINHA_COLUNA_VIRUS; linhaAux++) {
		for (int colunaAux = LIMITE_MIN_LINHA_COLUNA_VIRUS; colunaAux <= LIMITE_MAX_LINHA_COLUNA_VIRUS; colunaAux++) {
			if (posicaoVazio(linha+linhaAux, coluna+colunaAux, campo)) {
				campo[linha+linhaAux][coluna+colunaAux] = VIRUS;
				virus(linha+linhaAux, coluna+colunaAux, campo);
			}
		}
	}
	return;
}

/*
Função para marcar o VIRUS em uma posição determinada (Apenas para testarr a função virus)
*/
void  marcarVirus(int linha, int coluna, char campo[][QUANTIDADE_COLUNAS]) {
	campo[linha][coluna] = VIRUS;
	return;
}

#endif