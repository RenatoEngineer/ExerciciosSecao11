/*
 * ex006.c
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
		printf("Erro ao abrir o arquivo!!!\n");
		return 1;
	}

	int contadorLetras[26] = {0}; //Um array para contar as ocorrencias de cada letra do alfabeto
	char caractere;

	while ((caractere = fgetc(arquivo)) != EOF){
		if (isalpha(caractere)){ //Verifica se o caractere e uma letra
			caractere = tolower(caractere); //Converte o caractere para minuscula para facilitar a contagem
			contadorLetras[caractere - 'a']++; //Incrementa o contador da letra correspondente
		}
	}

	fclose(arquivo);

	printf("Ocorrencias de Cada letra do Alfabeto no Arquivo:\n");
	for (int i = 0; i < 26; i++){
		printf("%c: %d\n", 'a' + i, contadorLetras[i]);
	}

	return 0;
}

/*Certifique-se de criar o arquivo "arquivo.txt" no diretório onde o programa está sendo executado*/

