/*
 * ex008.c
 *
 *  Criado em: 9 de nov de 2023
 *      Autor: Renato Gomes de Sousa
 *
 *      https://github.com/RenatoEngineer/ExerciciosSecao11
 */

#include <stdio.h>
#include <ctype.h>

int main(){

	FILE *arquivoEntrada, *arquivoSaida;
	char nomeArquivoEntrada[100], nomeArquivoSaida[100];
	char caractere;

	//Solicita o nome do Arquivo de Entrada
	printf("Digite o Nome do Arquivo de Entrada: ");
	fflush(stdout);
	scanf("%s", nomeArquivoEntrada);

	//Solicita o nome do Arquivo de Saida
	printf("Digite o Nome do Arquivo de Saida: ");
	fflush(stdout);
	scanf("%s", nomeArquivoSaida);

	//Abre o arquivo de entrada no modo leitura
	arquivoEntrada = fopen(nomeArquivoEntrada, "r");
	if (arquivoEntrada == NULL){
		printf("\nErro ao Abrir o Arquivo de Entrada!!!\n");
		return 1;
	}

	//Abre o arquivo de Saida no Modo Escrita
	arquivoSaida = fopen(nomeArquivoSaida, "w");
	if (arquivoSaida == NULL){
		fclose(arquivoEntrada);
		printf("\nErro ao Criar o Arquivo de Saida!!!\n");
		return 1;
	}

	//Processa o arquivo de entrada
	while ((caractere = fgetc(arquivoEntrada)) != EOF){
		fputc(toupper(caractere), arquivoSaida); //Converte para maiuscula e escreve no arquivo de saida
	}

	//Fecha os arquivos
	fclose(arquivoEntrada);
	fclose(arquivoSaida);

	printf("\nOperacao Concluida!!!\nVerifique o Arquivo de Saida!!!\n");

	return 0;
}

/*Certifique-se de criar um arquivo de texto com conteudo, no diretório onde o programa esta sendo executado*/
