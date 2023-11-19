/*
 * ex023.c
 *
 *  Criado em: 19 de nov de 2023
 *      Autor: Renato Gomes de Sousa
 *
 *      https://github.com/RenatoEngineer/ExerciciosSecao11
 */

#include <stdio.h>

#define MAX_PROF 50

//Estrutura para armazenar informacoes dos funcionarios
struct Funcionario{
	char profissao[MAX_PROF + 1];
	int tempoServico;
};

int main(){

	FILE *arquivo;

	//Abre arquivo para escrita
	arquivo = fopen("emp.txt", "w");

	if (arquivo == NULL){
		printf("\nErro ao Abrir o Arquivo 'emp.txt' para Escrita!!!\n");
		return 1;
	}

	struct Funcionario funcionarios[5];

	//Recebe do usuario a profissao e o tempo de servico de cada funcionario
	for (int i = 0; i < 5; i++){
		printf("Digite a Profissao do Funcionario %d: ", i + 1);
		fflush(stdout);
		scanf(" %[^\n]", funcionarios[i].profissao);

		printf("Digite o Tempo de Servico (em anos) do Funcionario %d: ", i + 1);
		fflush(stdout);
		scanf("%d", &funcionarios[i].tempoServico);

		//Escreve os dados no arquivo usando fprintf
		fprintf(arquivo, "%s %d\n", funcionarios[i].profissao, funcionarios[i].tempoServico);
	}

	//Fecha o arquivo
	fclose(arquivo);

	//Abre o arquivo para Leitura
	arquivo = fopen("emp.txt", "r");

	if (arquivo == NULL){
		printf("\nErro ao Abrir o arquivo 'emp.txt' para Leitura!!!\n");
		return 1;
	}

	//Le os dados do arquivo usando fscanf e apresenta na tela
	printf("\nDados dos Funcionarios lidos do arquivo 'emp.txt':\n\n");
	for (int i = 0; i < 5; i++){
		fscanf(arquivo, "%s %d", funcionarios[i].profissao, &funcionarios[i].tempoServico);
		printf("Funcionario %d:\n", i + 1);
		printf("Profissao: %s\n", funcionarios[i].profissao);
		printf("Tempo de Servico: %d anos\n", funcionarios[i].tempoServico);
		printf("\n");
	}

	//Fecha o arquivo
	fclose(arquivo);

	return 0;
}
