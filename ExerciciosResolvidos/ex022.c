/*
 * ex022.c
 *
 *  Criado em: 19 de nov de 2023
 *      Autor: Renato Gomes de Sousa
 *
 *      https://github.com/RenatoEngineer/ExerciciosSecao11
 */

#include <stdio.h>
#include <stdlib.h>

#define MAX_NOME 40

//Estrutura para armazenar informacoes dos alunos
struct Aluno{
	char nome[MAX_NOME + 1];
	int notas[3];
};

//Funcao de comparacao para qsort
int comparaNotas(const void *a, const void *b){
	return (*(int *)a - *(int *)b);
}

int main(){

	char nomeArquivoEntrada[100];
	char nomeArquivoSaida[100];

	//Solicita o Arquivo de Entrada
	printf("Digite o nome do Arquivo de Entrada: ");
	fflush(stdout);
	scanf("%s", nomeArquivoEntrada);

	//Solicita o Arquivo de Saida
	printf("Digite o nome do Arquivo de Saida: ");
	fflush(stdout);
	scanf("%s", nomeArquivoSaida);

	FILE *arquivoEntrada = fopen(nomeArquivoEntrada, "r");
	FILE *arquivoSaida = fopen(nomeArquivoSaida, "w");

	if (arquivoEntrada == NULL || arquivoSaida == NULL){
		printf("\nErro ao abrir os Arquivos!!!\n");
		return 1;
	}

	struct Aluno aluno;

	//Le as informacoes dos alunos do arquivo de entrada
	while (fscanf(arquivoEntrada, "%40s %d %d %d", aluno.nome, &aluno.notas[0], &aluno.notas[1], &aluno.notas[2]) == 4){
		//Ordena as notas em ordem crescente
		qsort(aluno.notas, 3, sizeof(int), comparaNotas);

		//Escrece as notas ordenadas no arquivo de saida
		fprintf(arquivoSaida, "%-40s %d %d %d\n", aluno.nome, aluno.notas[0], aluno.notas[1], aluno.notas[2]);
	}

	//Fecha os arquivos
	fclose(arquivoEntrada);
	fclose(arquivoSaida);

	printf("\nNotas Ordenadas no Arquivo: '%s'!!!\n", nomeArquivoSaida);

	return 0;
}

/*Certifique-se de criar o arquivo de texto com conteudo, no diretorio onde o programa esta sendo executado*/

