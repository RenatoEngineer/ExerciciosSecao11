/*
 * ex020.c
 *
 *  Criado em: 17 de nov de 2023
 *      Autor: Renato Gomes de Sousa
 *
 *      https://github.com/RenatoEngineer/ExerciciosSecao11
 */

#include <stdio.h>
#include <stdlib.h>

#define MAX_NOME 40

int main(){

	int numAlunos;

	//Solicita o numero de alunos ao usuario
	printf("Digite o Numero de Alunos: ");
	fflush(stdout);
	scanf("%d", &numAlunos);

	//Aloca dinamicamente os vetores de nomes e notas
	char **nomes = (char **)malloc(numAlunos * sizeof(char *));
	float *notas = (float *)malloc(numAlunos * sizeof(float));

	if (nomes == NULL || notas == NULL){
		printf("\nErro ao Alocar Memoria!!!\n");
		return 1;
	}

	//Solicita ao usuario os nomes e notas dos alunos
	for (int i = 0; i < numAlunos; i++){
		//Aloca dinamicamente espaco para o nome do aluno (40 caracteres)
		nomes[i] = (char *)malloc((MAX_NOME + 1) * sizeof(char));

		if (nomes[i] == NULL){
			printf("\nErro ao Alocar Memoria para o Nome do Aluno!!!\n");
			return 1;
		}

		printf("\nDigite o Nome do Aluno %d: ", i + 1);
		fflush(stdout);
		scanf(" %[^\n]", nomes[i]); //" %[^\n]" Le toda a linha ate a proxima linha

		printf("Digite a Nota Final do Aluno %d: ", i + 1);
		fflush(stdout);
		scanf("%f", &notas[i]);
	}

	//Cria e abre o arquivo para escrita
	FILE *arquivo = fopen("alunos_notas.txt", "w");
	if (arquivo == NULL){
		printf("\nErro ao Criar o Arquivo 'alunos_notas.txt'!!!\n");
		return 1;
	}

	//Escreve as informacoes no arquivo
	for (int i = 0; i < numAlunos; i++){
		fprintf(arquivo, "%-40s %.2f\n", nomes[i], notas[i]);
	}

	//Fecha o arquivo
	fclose(arquivo);

	//Libera a memoria alocada dinamicamente
	for (int i = 0; i < numAlunos; i++){
		free(nomes[i]);
	}
	free(nomes);
	free(notas);

	printf("\nInformacoes dos Alunos Armazenadas no Arquivo 'alunos_notas.txt'!!!\n");

	return 0;
}
