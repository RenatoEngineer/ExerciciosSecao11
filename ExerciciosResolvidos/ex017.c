/*
 * ex017.c
 *
 *  Criado em: 15 de nov de 2023
 *      Autor: Renato Gomes de Sousa
 *
 *      https://github.com/RenatoEngineer/ExerciciosSecao11
 */

#include <stdio.h>
#include <stdlib.h>

void imprimeMatriz(int **matriz, int linhas, int colunas){
	for (int i = 0; i < linhas; i++){
		for (int j = 0; j < colunas; j++){
			printf("%d ", matriz[i][j]);
		}
		printf("\n");
	}
}

int main(){

	FILE *arquivoEntrada, *arquivoSaida;
	char nomeArquivoEntrada[] = "matriz.txt";
	char nomeArquivoSaida[] = "matriz_saida.txt";

	//Abre o arquivo de entrada no modo de leitura
	arquivoEntrada = fopen(nomeArquivoEntrada, "r");
	if (arquivoEntrada == NULL){
		printf("\nErro ao abrir o Arquivo de Entrada!!!\n");
		return 1;
	}

	//Obtem as dimensoes da matriz e a quantidade de posicoes a serem anuladas
	int linhas, colunas, quantidadeAnuladas;
	fscanf(arquivoEntrada, "%d %d %d", &linhas, &colunas, &quantidadeAnuladas);

	//Aloca dinamicamente a matriz
	int **matriz = (int **)malloc(linhas * sizeof(int *));
	for (int i = 0; i < linhas; i++){
		matriz[i] = (int *)malloc(colunas * sizeof(int));
	}

	//Inicializa a matriz com 1
	for (int i = 0; i < linhas; i++){
		for (int j = 0; j < colunas; j++){
			matriz[i][j] = 1;
		}
	}

	//Le as posicoes a serem anuladas e zera a matriz
	for (int i = 0; i < quantidadeAnuladas; i++){
		int linha, coluna;
		fscanf(arquivoEntrada, "%d %d", &linha, &coluna);
		matriz[linha][coluna] = 0;
	}

	//Fecha arquivo de entrada
	fclose(arquivoEntrada);

	//Abre o arquivo de Saida no modo de Escrita
	arquivoSaida = fopen(nomeArquivoSaida, "w");
	if (arquivoSaida == NULL){
		for (int i = 0; i < linhas; i++){
			free(matriz[i]);
		}
		free(matriz);
		printf("\nErro ao Criar o Arquivo de Saida!!!\n");
		return 1;
	}

	//Imprime a matriz no arquivo de saida
	for (int i = 0; i < linhas; i++){
		for (int j = 0; j < colunas; j++){
			fprintf(arquivoSaida, "%d ", matriz[i][j]);
		}
		fprintf(arquivoSaida, "\n");
	}

	//Fecha o arquivo de saida
	fclose(arquivoSaida);

	//Libera a memoria alocada para a matriz
	for (int i = 0; i < linhas; i++){
		free(matriz[i]);
	}
	free(matriz);

	printf("Operacao Concluida!!!\nVerifique o arquivo de Saida '%s'\n", nomeArquivoSaida);

	return 0;
}

/*Certifique-se de criar o arquivo de texto "matriz.txt" com conteudo, no diretorio onde o programa esta sendo executado*/

