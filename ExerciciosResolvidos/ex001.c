/*
 * ex001.c
 *
 *  Criado em: 6 de nov de 2023
 *      Autor: Renato Gomes de Sousa
 *
 *      https://github.com/RenatoEngineer/ExerciciosSecao11
 */

#include <stdio.h>

int main(){

	char nomeArquivo[] = "arq.txt";
	char caractere;

	//(a) Crie/abra um arquivo texto de nome “arq.txt”
	FILE *arquivo = fopen(nomeArquivo, "w");
	if (arquivo == NULL){
		printf("\nErro ao Criar o Arquivo!!!\n");
		return 1;
	}

	printf("Digite os Caracteres que deseja Salvar no Arquivo (Digite '0' para Encerrar):\n");
	fflush(stdout);

	//Permita que o usuário grave diversos caracteres nesse arquivo, até que o usuário entre com o caractere ‘0’
	while (1){
		scanf(" %c", &caractere); //Usado um espaco em " %c" para evitar a leitura de espacos em branco
		if (caractere == '0'){
			break;
		}
		fputc(caractere, arquivo);
	}

	//(c) Feche o arquivo
	fclose(arquivo);

	//Abre o arquivo para leitura
	arquivo = fopen(nomeArquivo, "r");
	if (arquivo == NULL){
		printf("Erro ao Abrir o Arquivo!!!\n");
		return 1;
	}

	printf("\nConteudo do Arquivo:\n");

	//Le e escreve na tela todos os caracteres armazenados
	while ((caractere = fgetc(arquivo)) != EOF){
		putchar(caractere);
	}

	fclose(arquivo);

	return 0;
}
