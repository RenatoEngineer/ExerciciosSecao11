/*
 * ex012.c
 *
 *  Criado em: 11 de nov de 2023
 *      Autor: Renato Gomes de Sousa
 *
 *      https://github.com/RenatoEngineer/ExerciciosSecao11
 */

#include <stdio.h>
#include <ctype.h>

int main(){

	FILE *arquivo;
	char nomeArquivo[100];
	char caractere;
	int numCaracteres = 0, numLinhas = 0, numPalavras = 0;
	int contagemLetras[26] = {0}; //Array para contar as ocorrencias de cada letra do alfabeto

	//Solicita o nome do arquivo
	printf("Digite o nome do Arquivo: ");
	fflush(stdout);
	scanf("%s", nomeArquivo);

	//Abre o arquivo no modo de leitura
	arquivo = fopen(nomeArquivo, "r");
	if (arquivo == NULL){
		printf("\nErro ao abrir o arquivo!!!\n");
		return 1;
	}

	int dentroPalavra = 0; //Variavel para rastrear se esta dentro de uma palavra

	//Processa o arquivo
	while ((caractere = fgetc(arquivo)) != EOF){
		numCaracteres++;

		//Contagem de letras considerando todas as letras
		if (isalpha(caractere)){
			contagemLetras[tolower(caractere) - 'a']++;
		}

		//Contagem de palavras
		if (isspace(caractere) || ispunct(caractere)){
			dentroPalavra = 0;
		} else if (!dentroPalavra){
			dentroPalavra = 1;
			numPalavras++;
		}

		//Contagem de linhas
		if (caractere == '\n'){
			numLinhas++;
		}
	}

	//Fehca o arquivo
	fclose(arquivo);

	//Exibe os resultados
	printf("\nNumero de Caracteres: %d\n", numCaracteres);
	printf("Numero de Linhas: %d\n", numLinhas);
	printf("Numero de Palavras: %d\n", numPalavras);

	printf("\nContagem de Letras:\n");
	for (int i = 0; i < 26; i++){
		printf("%c: %d\n", 'a' + i, contagemLetras[i]);
	}

	return 0;
}

/*Certifique-se de criar o arquivo de texto com conteudo, no diretorio onde o programa esta sendo executado*/

