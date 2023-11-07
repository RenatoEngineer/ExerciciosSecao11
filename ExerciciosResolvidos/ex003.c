/*
 * ex003.c
 *
 *  Criado em: 7 de nov de 2023
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
		printf("Erro ao Abrir o Arquivo!!!\n");
		return 1;
	}

	int contadorVogais = 0;
	char caractere;

	while ((caractere = fgetc(arquivo)) != EOF){
		caractere = tolower(caractere); //Converte o caractere para minuscula para facilitar a comparacao
		if (caractere == 'a' || caractere == 'e' || caractere == 'i' || caractere == 'o' || caractere == 'u'){
			contadorVogais++;
		}
	}

	fclose(arquivo);

	printf("O Arquivo possui %d Vogais.\n", contadorVogais);

	return 0;
}

/*Certifique-se de criar o arquivo "arquivo.txt" no diretório onde o programa está sendo executado*/
