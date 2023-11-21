/*
 * ex026.c
 *
 *  Criado em: 21 de nov de 2023
 *      Autor: Renato Gomes de Sousa
 *
 *      https://github.com/RenatoEngineer/ExerciciosSecao11
 */

#include <stdio.h>
#include <stdlib.h>

//Estrutura para o Cadastro de Alunos
struct Aluno{
	int matricula;
	char sobrenome[50];
	int anoNascimento;
};

//Funcao para ler os dados do aluno
void lerAluno(struct Aluno *aluno){
	printf("Matricula: ");
	fflush(stdout);
	scanf("%d", &aluno->matricula); //Pode ser usado (*aluno).matricula

	printf("Sobrenome: ");
	fflush(stdout);
	scanf(" %[^\n]", aluno->sobrenome); //Pode ser usado (*aluno).sobrenome

	printf("Ano de Nascimento: ");
	fflush(stdout);
	scanf("%d", &aluno->anoNascimento); //Pode ser usado (*aluno).anoNascimento
}

//Funcao para gravar os dados dos alunos em um arquivo
void gravaArquivo(struct Aluno *alunos, int numAlunos, const char *nomeArquivo){
	FILE *arquivo = fopen(nomeArquivo, "wb");
	if (arquivo == NULL){
		printf("\nErro ao abir o Arquivo!!!\n");
		exit(1);
	}

	fwrite(alunos, sizeof(struct Aluno), numAlunos, arquivo);

	fclose(arquivo);
}

//Funcao para ler os dados dos alunos de um Arquivo
struct Aluno *lerArquivo(const char *nomeArquivo, int *numAlunos){
	FILE *arquivo = fopen(nomeArquivo, "rb");
	if (arquivo == NULL){
		printf("\nErro ao Abrir o Arquivo!!!\n");
		exit(1);
	}

	fseek(arquivo, 0, SEEK_END);
	long tamanho = ftell(arquivo);
	rewind(arquivo);

	*numAlunos = tamanho / sizeof(struct Aluno);

	struct Aluno *alunos = malloc(tamanho);
	if (alunos == NULL){
		printf("\nErro ao Alocar Memoria!!!\n");
		fclose(arquivo);
		exit(1);
	}

	fread(alunos, sizeof(struct Aluno), *numAlunos, arquivo);

	fclose(arquivo);

	return alunos;
}

int main(){

	int numAlunos;

	//Solicita ao usuario o numero de alunos
	printf("Informe o Numero de Alunos: ");
	fflush(stdout);
	scanf("%d", &numAlunos);

	//Aloca dinamicamente memoria para armazenar os registros dos alunos
	struct Aluno *alunos = malloc(numAlunos * sizeof(struct Aluno));
	if (alunos == NULL){
		printf("\nErro ao Alocar Memoria!!!\n");
		return 1;
	}

	//Entrada de informacoes dos Alunos
	for (int i = 0; i < numAlunos; ++i){ //Pre-incremento
		printf("\nEntre com os dados do Aluno %d:\n", i + 1);
		lerAluno(&alunos[i]);
	}

	//Grava os dados no arquivo "alunos.bin"
	gravaArquivo(alunos, numAlunos, "alunos.bin");
	printf("\nDados Gravados em 'alunos.bin'!!!\n");

	//Libera a memoria alocada
	free(alunos);

	//Opcao para carregar registros do arquivo para a memoria
	int opcao;
	printf("\nDeseja Carregar os Registros do Arquivo para a Memoria?\n(1 - Sim / 0 - Nao):\n");
	fflush(stdout);
	scanf("%d", &opcao);

	if (opcao == 1){
		//Le os dados do arquivo e imprime na tela
		int numAlunosArquivo;
		struct Aluno *alunosArquivo = lerArquivo("alunos.bin", &numAlunosArquivo);

		printf("\n.:: Dados carregados do Arquivo ::.\n");
		for (int i = 0; i < numAlunosArquivo; ++i){ //Pre-Incremento
			printf("\nAluno %d:\n", i + 1);
			printf("Matricula: %d\n", alunosArquivo[i].matricula);
			printf("Sobrenome: %s\n", alunosArquivo[i].sobrenome);
			printf("Ano de Nascimento: %d\n", alunosArquivo[i].anoNascimento);
		}

		//Libera a Memoria Alocada
		free(alunosArquivo);
	} else {
		printf("\nSaindo do Programa!!!\n");
	}

	return 0;
}
