/*
 * ex027.c
 *
 *  Criado em: 5 de dez de 2023
 *      Autor: Renato Gomes de Sousa
 *
 *      https://github.com/RenatoEngineer/ExerciciosSecao11
 */

#include <stdio.h>
#include <stdlib.h>

//Estrutura para armazenar os dados de um aluno
typedef struct{
	char nome[50];
	float nota1;
	float nota2;
	float media;
} Aluno;

//Funcao para definir as informacoes da turma
void definirTurma(char *nomeTurma, int *quantidadeAlunos){
	printf("\nDigite o nome da Turma: ");
	fflush(stdout);
	scanf("%s", nomeTurma);

	printf("Digite a quantidade de Alunos: ");
	fflush(stdout);
	scanf("%d", quantidadeAlunos);
}

//Funcao para inserir o nome do aluno e as notas
void inserirAluno(Aluno *aluno){
	printf("\nDigite o nome do Aluno: ");
	fflush(stdout);
	scanf("%s", aluno->nome);

	printf("Digite a Primeira Nota: ");
	fflush(stdout);
	scanf("%f", &aluno->nota1);

	printf("Digite a Segunda Nota: ");
	fflush(stdout);
	scanf("%f", &aluno->nota2);

	//Calcula a media aritmetica das notas
	aluno->media = (aluno->nota1 + aluno->nota2) / 2;
}

//Funcao para exibir os alunos e as medias
void exibirAlunos(Aluno *turma, int quantidadeAlunos){
	printf("\n.:: ALUNOS E MEDIAS ::.\n");
	for (int i = 0; i < quantidadeAlunos; i++){
		printf("%s: %.2f\n", turma[i].nome, turma[i].media);
	}
}

//Funcao para exibir os alunos aprovados
void exibirAprovados(Aluno *turma, int quantidadeAlunos){
	printf("\n.:: ALUNOS APROVADOS ::.\n");
	for (int i = 0; i < quantidadeAlunos; i++){
		//Considera que a nota minima para aprovacao eh 6.0
		if (turma[i].media >= 6.0){
			printf("%s: %.2f\n", turma[i].nome, turma[i].media);
		}
	}
}

//Funcao para exibir os alunos reprovados
void exibirReprovados(Aluno *turma, int quantidadeAlunos){
	printf("\n.:: ALUNOS REPROVADOS ::.\n");
	for (int i = 0; i < quantidadeAlunos; i++){
		//Considera que a nota minima para aprovacao eh 6.0
		if (turma[i].media < 6.0){
			printf("%s: %.2f\n", turma[i].nome, turma[i].media);
		}
	}
}

//Funcao para salvar os dados em um arquivo
void salvaDados(Aluno *turma, int quantidadeAlunos, char *nomeArquivo){
	FILE *arquivo = fopen(nomeArquivo, "w");
	if (arquivo == NULL){
		printf("\nErro ao abrir o Arquivo!!!\n");
		return;
	}

	//Escreve os dados de cada aluno no arquivo
	for (int i = 0; i < quantidadeAlunos; i++){
		fprintf(arquivo, "%s %.2f %.2f %.2f\n", turma[i].nome, turma[i].nota1, turma[i].nota2, turma[i].media);
	}

	fclose(arquivo);
	printf("\nDados salvos em %s.\n", nomeArquivo);
}

//Funcao principal
int main(){

	char nomeTurma[50];
	int quantidadeAlunos;
	Aluno *turma;
	char nomeArquivo[] = "alunos.txt";
	char opcao;

	//Aloca memoria para a turma
	turma = (Aluno *) malloc(sizeof(Aluno));

	//Exibe o menu
	do {
		printf("\n.:: MENU ::.\n");
		printf("(a) Definir informacoes da Turma\n");
		printf("(b) Inserir Aluno e Notas\n");
		printf("(c) Exibir Alunos e Medias\n");
		printf("(d) Exibir Alunos Aprovados\n");
		printf("(e) Exibir Alunos Reprovados\n");
		printf("(f) Salvar dados em Disco\n");
		printf("(g) Sair do Programa (Fim)!!!\n");
		printf("\nDigite a Sua Opcao: ");
		fflush(stdout);
		scanf(" %c", &opcao);

		//Executa a opcao escolhida
		switch (opcao){
		case 'a':
			definirTurma(nomeTurma, &quantidadeAlunos);
			//Realoca memoria para a turma de acordo com a quantidade de alunos
			turma = (Aluno *) realloc(turma, quantidadeAlunos * sizeof(Aluno));
			break;

		case 'b':
			//Insere os dados de cada aluno na turma
			for (int i = 0; i < quantidadeAlunos; i++){
				inserirAluno(&turma[i]);
			}
			break;

		case 'c':
			exibirAlunos(turma, quantidadeAlunos);
			break;

		case 'd':
			exibirAprovados(turma, quantidadeAlunos);
			break;

		case 'e':
			exibirReprovados(turma, quantidadeAlunos);
			break;

		case 'f':
			salvaDados(turma, quantidadeAlunos, nomeArquivo);
			break;

		case 'g':
			printf("Fim do Programa!!!\n");
			break;

		default:
			printf("Opcao Invalida!!!\n");
			break;
		}

	} while (opcao != 'g');

	//Libera a memoria alocada para a turma
	free(turma);

	return 0;
}
