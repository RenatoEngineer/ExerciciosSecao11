/*
 * ex005.c
 *
 *  Criado em: 8 de nov de 2023
 *      Autor: Renato Gomes de Sousa
 *
 *      https://github.com/RenatoEngineer/ExerciciosSecao11
 */

#include <stdio.h>

int main(){

	FILE *arquivo;
	char nomeArquivo[] = "arquivo.txt"; //Nome do arquivo
	char caractereDigitado;

	printf("Digite o Caractere que deseja buscar no arquivo: ");
	fflush(stdout);
	scanf(" %c", &caractereDigitado); //Espaco em brando antes do %c para consumir possivel quebra de linha

	arquivo = fopen(nomeArquivo, "r"); //Abre o arquivo no modo de leitura

	if (arquivo == NULL){
		printf("Erro ao abrir o arquivo!!!\n");
		return 1;
	}

	int contadorOcorrencias = 0;
	char caractere;

	while ((caractere = fgetc(arquivo)) != EOF){
		if (caractere == caractereDigitado){
			contadorOcorrencias++;
		}
	}

	fclose(arquivo);

	printf("\nO Caractere '%c' ocorre %d vezes no Arquivo!!!\n", caractereDigitado, contadorOcorrencias);

	return 0;
}

/*Certifique-se de criar o arquivo "arquivo.txt" no diretório onde o programa está sendo executado*/

