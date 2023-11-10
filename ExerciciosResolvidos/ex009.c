/*
 * ex009.c
 *
 *  Criado em: 10 de nov de 2023
 *      Autor: Renato Gomes de Sousa
 *
 *      https://github.com/RenatoEngineer/ExerciciosSecao11
 */

#include <stdio.h>

int main(){

	FILE *arquivo1, *arquivo2, *arquivo3;
	char nomeArquivo1[100], nomeArquivo2[100], nomeArquivo3[100];
	char caractere;

	//Solicita o Primeiro Arquivo
	printf("Digite o nome do Primeiro Arquivo: ");
	fflush(stdout);
	scanf("%s", nomeArquivo1);

	//Solicita o Segundo Arquivo
	printf("Digite o nome do Segundo Arquivo: ");
	fflush(stdout);
	scanf("%s", nomeArquivo2);

	//Solicita o nome do Arquivo de Saida
	printf("Digite o nome do Arquivo de Saida: ");
	fflush(stdout);
	scanf("%s", nomeArquivo3);

	//Abre o primeiro arquivo no modo leitura
	arquivo1 = fopen(nomeArquivo1, "r");
	if (arquivo1 == NULL){
		printf("\nErro ao Abrir o Primeiro Arquivo!!!\n");
		return 1;
	}

	//Abre o segundo arquivo no modo leitura
	arquivo2 = fopen(nomeArquivo2, "r");
	if (arquivo2 == NULL){
		fclose(arquivo1);
		printf("\nErro ao Abrir o Segundo Arquivo!!!\n");
		return 1;
	}

	//Abre/Cria o arquivo concatenado no modo escrita
	arquivo3 = fopen(nomeArquivo3, "w");
	if (arquivo3 == NULL){
		fclose(arquivo1);
		fclose(arquivo2);
		printf("\nErro ao Criar o Arquivo Concatenado!!!\n");
		return 1;
	}

	//Copia o conteudo do primeiro arquivo para o arquivo concatenado
	while ((caractere = fgetc(arquivo1)) != EOF){
		fputc(caractere, arquivo3);
	}

	//Copia o conteudo do segundo arquivo para o arquivo concatenado
	while ((caractere = fgetc(arquivo2)) != EOF){
		fputc(caractere, arquivo3);
	}

	//Fecha os arquivos
	fclose(arquivo1);
	fclose(arquivo2);
	fclose(arquivo3);

	printf("\nOperacao Concluida!!!\nVerifique o Arquivo de Saida!!!\n");

	return 0;
}

/*Certifique-se de criar os dois arquivos de textos com conteudo, no diretorio onde o programa esta sendo executado*/
