/*
 * ex011.c
 *
 *  Criado em: 11 de nov de 2023
 *      Autor: Renato Gomes de Sousa
 *
 *      https://github.com/RenatoEngineer/ExerciciosSecao11
 */

#include <stdio.h>
#include <string.h>

#define TAMANHO_PALAVRA 100

int main(){

	FILE *arquivo;
	char nomeArquivo[100], palavra[TAMANHO_PALAVRA];
	char buffer[TAMANHO_PALAVRA];
	int contador = 0;

	//Solicita o nome do arquivo
	printf("Digite o nome do Arquivo: ");
	fflush(stdout);
	scanf("%s", nomeArquivo);

	//Solicita a palavra a ser contada
	printf("Digite a Palavra a ser Contada: ");
	fflush(stdout);
	scanf("%s", palavra);

	//Abre o arquivo no modo leitura
	arquivo = fopen(nomeArquivo, "r");
	if (arquivo == NULL){
		printf("\nErro ao abrir o Arquivo!!!");
		return 1;
	}

	//Processa o arquivo
	while (fscanf(arquivo, "%99s", buffer) == 1){
		//Compara a palavra no arquivo com a palavra fornecida pelo usuario
		if (strcmp(buffer, palavra) == 0){
			contador++;
		}
	}

	//Fecha o arquivo
	fclose(arquivo);

	printf("\nA Palavra '%s' aparece %d vezes no arquivo!!!\n", palavra, contador);

	return 0;
}

/*Certifique-se de criar o arquivo de texto com conteudo, no diretorio onde o programa esta sendo executado*/
