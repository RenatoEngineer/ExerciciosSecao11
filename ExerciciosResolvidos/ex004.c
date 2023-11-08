/*
 * ex004.c
 *
 *  Criado em: 8 de nov de 2023
 *      Autor: Renato Gomes de Sousa
 *
 *      https://github.com/RenatoEngineer/ExerciciosSecao11
 */

#include <stdio.h>
#include <ctype.h>

int main(){

	FILE *arquivo;
	char nomeArquivo[] = "arquivo.txt"; //Nome do Arquivo

	arquivo = fopen(nomeArquivo, "r"); //Abre o arquivo no modo de leitura

	if (arquivo == NULL){
		printf("Erro ao abrir o Arquivo!!!\n");
		return 1;
	}

	int contadorVogais = 0;
	int contadorConsoantes = 0;
	char caractere;

	while ((caractere = fgetc(arquivo)) != EOF){
		if (isalpha(caractere)){ //Verfica se o caractere e uma letra
			caractere = tolower(caractere); //Converte o caractere para minuscula para facilitar a comparacao
			if (caractere == 'a' || caractere == 'e' || caractere == 'i' || caractere == 'o' || caractere == 'u'){
				contadorVogais++;
			} else {
				contadorConsoantes++;
			}
		}
	}

	fclose(arquivo);

	printf("O Arquivo possui %d Vogais e %d Consoantes.\n", contadorVogais, contadorConsoantes);

	return 0;
}

/*Certifique-se de criar o arquivo "arquivo.txt" no diretório onde o programa está sendo executado*/

