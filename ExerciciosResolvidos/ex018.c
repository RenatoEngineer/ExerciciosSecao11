/*
 * ex018.c
 *
 *  Criado em: 16 de nov de 2023
 *      Autor: Renato Gomes de Sousa
 *
 *      https://github.com/RenatoEngineer/ExerciciosSecao11
 */

#include <stdio.h>

int main(){

	FILE *arquivo;
	char nomeArquivo[] = "arquivo.txt";

	//Abre o arquivo no modo de leitura
	arquivo = fopen(nomeArquivo, "r");
	if (arquivo == NULL){
		printf("\nErro ao Abrir o Arquivo %s!!!\n", nomeArquivo);
		return 1;
	}

	char nome[100];
	float preco;
	float total = 0.0;

	//Le cada linha do arquivo e calcula o total
	while (fscanf(arquivo, "%99s %f", nome, &preco) == 2){
		printf("Produto: %s, Preco: %.2f\n", nome, preco);
		total += preco;
	}

	//Fecha o arquivo
	fclose(arquivo);

	//Imprime o total da compra
	printf("\nTotal da Compra: %.2f\n", total);

	return 0;
}

/*Certifique-se de criar o arquivo de texto com conteudo, no diretorio onde o programa esta sendo executado*/

