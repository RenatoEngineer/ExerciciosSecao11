/*
 * ex028.c
 *
 *  Criado em: 6 de dez de 2023
 *      Autor: Renato Gomes de Sousa
 *
 *      https://github.com/RenatoEngineer/ExerciciosSecao11
 */

#include <stdio.h>
#include <string.h>

#define TAMANHO_LINHA 30

//Funcao para inverter uma string
void inverterString(char *str){
	int tamanho = strlen(str);

	for (int inicio = 0, fim = tamanho - 1; inicio < fim; inicio++, fim--){
		char temp = str[inicio];
		str[inicio] = str[fim];
		str[fim] = temp;
	}
}

//Funcao para processar o arquivo de entrada e gerar o arquivo de saida invertido
void processarArquivos(FILE *arquivoEntrada, FILE *arquivoSaida){
	char linha[TAMANHO_LINHA + 1];

	while (fgets(linha, sizeof(linha), arquivoEntrada) != NULL){
		//Remover o caractere de nova linha, se existir
		int tamanho = strlen(linha);
		if (linha[tamanho - 1] == '\n'){
			linha[tamanho - 1] = '\0';
		}

		inverterString(linha);
		fprintf(arquivoSaida, "%s\n", linha);
	}
}

int main(){

	char nomeArquivoEntrada[100];
	char nomeArquivoSaida[100];

	//Obter nomes de arquivo do usuario
	printf("Digite o Nome do Arquivo de Entrada: ");
	fflush(stdout);
	scanf("%s", nomeArquivoEntrada);

	printf("Digite o Nome do Arquivo de Saida: ");
	fflush(stdout);
	scanf("%s", nomeArquivoSaida);

	//Abrir o arquivo de entrada para leitura
	FILE *arquivoEntrada = fopen(nomeArquivoEntrada, "r");
	if (arquivoEntrada == NULL){
		printf("\nErro ao Abrir o Arquivo de Entrada!!!\n");
		return 1;
	}

	//Abrir o arquivo de saida para escrita
	FILE *arquivoSaida = fopen(nomeArquivoSaida, "w");
	if (arquivoSaida == NULL){
		printf("\nErro ao Abrir o Arquivo de Saida!!!\n");
		fclose(arquivoEntrada);
		return 1;
	}

	//Processar os arquivos
	processarArquivos(arquivoEntrada, arquivoSaida);

	//Fechar os arquivos
	fclose(arquivoEntrada);
	fclose(arquivoSaida);

	printf("\nOperacao Concluida com Sucesso!!!\n");

	return 0;
}
