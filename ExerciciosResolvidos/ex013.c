/*
 * ex013.c
 *
 *  Criado em: 13 de nov de 2023
 *      Autor: Renato Gomes de Sousa
 *
 *      https://github.com/RenatoEngineer/ExerciciosSecao11
 */

#include <stdio.h>

int main(){

	FILE *arquivo;
	char nome[100];
	char telefone[15];

	//Solicita o nome do arquivo para armazenar os dados
	char nomeArquivo[100];
	printf("Digite o nome do arquivo para armazenar os dados: ");
	fflush(stdout);
	scanf("%s", nomeArquivo);

	//Abre o arquivo no modo de escrita
	arquivo = fopen(nomeArquivo, "w");
	if (arquivo == NULL){
		printf("\nErro ao Criar o Arquivo!!!\n");
		return 1;
	}

	//Solicita os dados ao usuario
	printf("\nEntre com os dados (0 para encerrar):\n");
	while (1){
		printf("\nNome: ");
		fflush(stdout);
		scanf("%s", nome);

		//Verifica se o usuario deseja encerrar a entrada
		if (nome[0] == '0'){
			break;
		}

		printf("Telefone: ");
		fflush(stdout);
		scanf("%s", telefone);

		//Escreve os dados no arquivo
		fprintf(arquivo, "%s %s\n", nome, telefone);
	}

	//Fecha o arquivo
	fclose(arquivo);

	printf("\nCadastro Concluido!!!\nVerifique o arquivo '%s'!!!\n", nomeArquivo);

	return 0;
}
