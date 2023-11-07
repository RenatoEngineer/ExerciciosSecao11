/*
 * ex002.c
 *
 *  Criado em: 7 de nov de 2023
 *      Autor: Renato Gomes de Sousa
 *
 *      https://github.com/RenatoEngineer/ExerciciosSecao11
 */

#include <stdio.h>

int main(){

	FILE *arquivo;
	char nomeArquivo[] = "arquivo.txt"; //Nome do Arquivo

	arquivo = fopen(nomeArquivo, "r"); //Abre o arquivo no modo de leitura

	if (arquivo == NULL){
		printf("Erro ao Abrir o Arquivo!!!\n");
		return 1;
	}

	int contadorLinhas = 0;
	char caractere;

	while ((caractere = fgetc(arquivo)) != EOF){
		if (caractere == '\n'){
			contadorLinhas++;
		}
	}

	//Verifica se o arquivo não termina com uma quebra de linha
	if (caractere != '\n' && contadorLinhas > 0){
		contadorLinhas++;
	}

	fclose(arquivo);

	printf("O arquivo possui %d linhas.\n", contadorLinhas);

	return 0;
}

/*Certifique-se de criar o arquivo "arquivo.txt" no diretorio onde o programa esta sendo executado*/
