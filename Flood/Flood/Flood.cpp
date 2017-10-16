#include "stdafx.h"
#include <iostream>
#include "Flood.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "Portuguese");

	int tipoDeTeste, tamanho, velocidade, linha, coluna, indice = 0;

	cout << "\t\t CAMPO DE TESTES \n\n"
		 << "1 - Simula��o por escolha \t 2 - Simula��o foda"
		 << endl;
	cin  >> tipoDeTeste;

	while (tipoDeTeste < 1 || tipoDeTeste > 2) {
		cout << "Op��o inv�lida. Favor selecionar novamente." << endl;
		cin  >> tipoDeTeste;
	}

	escreverUmDosCampos(TAMANHO_PEQUENO);
	cout << endl;

	escreverUmDosCampos(TAMANHO_MEDIO);
	cout << endl;

	escreverUmDosCampos(TAMANHO_GRANDE);
	cout << endl;

	cout << "\nEntre com o valor correspondente ao tamanho do campo desejado:\n"
		 << "1 - Pequeno \t 2 - M�dio \t 3 - Grande"
		 << endl;
	cin  >> tamanho;

	while (tamanho < 1 || tamanho > 3) {
		cout << "Op��o inv�lida. Favor selecionar novamente." << endl;
		cin  >> tamanho;
	}

	cout << "\nVelocidade desejada:\n"
		 << "1 - Passo a passo \t 2 - Instant�neo"
		 << endl;
	cin  >> velocidade;

	while (velocidade < 1 || velocidade > 2) {
		cout << "Op��o inv�lida. Favor selecionar novamente." << endl;
		cin >> velocidade;
	}

	if (tipoDeTeste == 1) {
		cout << "\n\n\n" << "1� PASSO: posicionamento das cercas.\n" << endl;
		escreverUmDosCampos(tamanho);
		
		if (tamanho == 1) {
			while (indice < MAXIMO_PARA_PEQUENO) {
				cout << "\nPOSICIONAR CERCA: Entre com valor de linha e valor de coluna separadamente." << endl;
				cin  >> linha;
				cin  >> coluna;
				while (!verificarPosicaoLivre(linha, coluna, tamanho)) {
					cout << "\nPosi��o selecionada encontra-se ocupada ou � inv�lida. Favor selecionar outra." << endl;
					cin >> linha;
					cin >> coluna;
				}
				indice++;
				cout << "\n\n\n" << "Restam " << MAXIMO_PARA_PEQUENO - indice << " cercas.\n" << endl;
				escreverUmDosCampos(tamanho);
			}
		}
		else {
			while (indice < MAXIMO_PARA_MEDIO_GRANDE) {
				cout << "POSICIONAR CERCA: Entre com valor de linha e valor de coluna separadamente." << endl;
				cin  >> linha;
				cin  >> coluna;
				while (!verificarPosicaoLivre(linha, coluna, tamanho)) {
					cout << "Posi��o selecionada encontra-se ocupada. Favor selecionar outra." << endl;
					cin >> linha;
					cin >> coluna;
				}
				indice++;
				cout << "\n\n\n" << "Restam " << MAXIMO_PARA_MEDIO_GRANDE - indice << " cercas.\n" << endl;
				escreverUmDosCampos(tamanho);
			}
		}

		cout << "\n\n\n" << "2� PASSO: a propaga��o do v�rus."
			 << "\n\n" << "Escolha a posi��o inicial do v�rus:" << endl;
		cin  >> linha;
		cin  >> coluna;

		if (tamanho == 1) {
			virus(linha, coluna, campoPequeno, velocidade, tamanho);
		}
		else if (tamanho == 2) {
			virus(linha, coluna, campoMedio, velocidade, tamanho);
		}
		else {
			virus(linha, coluna, campoGrande, velocidade, tamanho);
		}

		escreverUmDosCampos(tamanho);
	}
	else {
		cout << "\n\n\n" << "As cercas foram posicionadas da seguinte forma:\n" << endl;
		if (tamanho == 1) {
			colocarCercasTemporarias(campoPequeno, MAXIMO_PARA_PEQUENO, QUANTIDADE_LINHAS_PARA_MENORES);
			escreverUmDosCampos(tamanho);
		}
		else if (tamanho == 2) {
			colocarCercasTemporarias(campoMedio, MAXIMO_PARA_MEDIO_GRANDE, QUANTIDADE_LINHAS_PARA_MEDIOS);
			escreverUmDosCampos(tamanho);
		}
		else {
			colocarCercasTemporarias(campoGrande, MAXIMO_PARA_MEDIO_GRANDE, QUANTIDADE_LINHAS_PARA_GRANDES);
			escreverUmDosCampos(tamanho);
		}

		cout << "\n\n\n" << "O v�rus come�a a se espalhar pelo mapa em 5 focos diferentes...\n" << endl;
		
		if (tamanho == 1) {
			rodarVirusNosPontosAleatorios(campoPequeno, QUANTIDADE_LINHAS_PARA_MENORES, velocidade, tamanho);
		}
		else if (tamanho == 2) {
			rodarVirusNosPontosAleatorios(campoMedio, QUANTIDADE_LINHAS_PARA_MEDIOS, velocidade, tamanho);
		}
		else {
			rodarVirusNosPontosAleatorios(campoGrande, QUANTIDADE_LINHAS_PARA_GRANDES, velocidade, tamanho);
		}

		escreverUmDosCampos(tamanho);
	}

	system("pause");
    return 0;
}

