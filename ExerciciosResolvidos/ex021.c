/*
 * ex021.c
 *
 *  Criado em: 17 de nov de 2023
 *      Autor: Renato Gomes de Sousa
 *
 *      https://github.com/RenatoEngineer/ExerciciosSecao11
 */

#include <stdio.h>
#include <stdlib.h>

#define MAX_NOME 40

//Definicao da estrutura para armazenar informacoes dos alunos
struct Aluno{
	char nome[MAX_NOME + 1];
	float nota;
};

int main(){

	int numAlunos;

	//Solicita o numero de Alunos ao Usuario
	printf("Digite o Numero de Alunos: ");
	fflush(stdout);
	scanf("%d", &numAlunos);

	//Aloca dinamicamente a estrutura para armazenar informacoes dos alunos
	struct Aluno *alunos = (struct Aluno *)malloc(numAlunos * sizeof(struct Aluno));

	if (alunos == NULL){
		printf("\nErro ao Alocar Memoria!!!\n");
		return 1;
	}

	//Solicita ao usuario os nomes e notas dos alunos
	for (int i = 0; i < numAlunos; i++){
		printf("\nDigite o Nome do Aluno %d: ", i + 1);
		fflush(stdout);
		scanf(" %[^\n]", alunos[i].nome);

		printf("Digite a Nota Final do Aluno %d: ", i + 1);
		fflush(stdout);
		scanf("%f", &alunos[i].nota);
	}

	//Cria e abre o arquivo binario para escrita
	FILE *arquivo = fopen("alunos.bin", "wb");
	if (arquivo == NULL){
		printf("Erro ao Criar o Arquivo 'alunos.bin'!!!\n");
		return 1;
	}

	//Escreve as informacoes dos alunos no arquivo
	fwrite(alunos, sizeof(struct Aluno), numAlunos, arquivo);

	//Fecha o arquivo
	fclose(arquivo);

	//Libera a memoria alocada dinamicamente
	free(alunos);

	//Abre o arquivo binario para leitura
	arquivo = fopen("alunos.bin", "rb");
	if (arquivo == NULL){
		printf("\nErro ao Abrir o Arquivo 'alunos.bin' para Leitura!!!\n");
		return 1;
	}

	//Le as informacoes dos alunos do arquivo
	struct Aluno melhorAluno;
	fread(&melhorAluno, sizeof(struct Aluno), 1, arquivo);

	//Encontra o aluno com a maior nota
	for (int i = 1; i < numAlunos; i++){
		struct Aluno alunoAtual;
		fread(&alunoAtual, sizeof(struct Aluno), 1, arquivo);

		if (alunoAtual.nota > melhorAluno.nota){
			melhorAluno = alunoAtual;
		}
	}

	//Fecha o arquivo
	fclose(arquivo);

	//Imprime o nome do aluno com a maior nota
	printf("\nAluno com a maior nota: %s, Nota: %.2f\n", melhorAluno.nome, melhorAluno.nota);

	return 0;
}
