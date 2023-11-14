/*
 * ex015.c
 *
 *  Criado em: 14 de nov de 2023
 *      Autor: Renato Gomes de Sousa
 *
 *      https://github.com/RenatoEngineer/ExerciciosSecao11
 */

#include <stdio.h>

#define TAMANHO_NOME 40

struct Pessoa{
	char nome[TAMANHO_NOME];
	int anoNascimento;
};

//Funcao para calcular a idade com base no ano corrente
int calculaIdade(int anoCorrente, int anoNascimento){
	return anoCorrente - anoNascimento;
}

//Funcao para determinar a descricao da idade
const char *obterDescricaoIdade(int idade){
	if (idade < 18){
		return "Menor de Idade";
	} else if (idade == 18){
		return "Entrando na Maior Idade";
	} else {
		return "Maior de Idade";
	}
}

int main(){

	int anoCorrente;
	char nomeArquivoEntrada[100];
	char nomeArquivoSaida[100];

	//Solicita ano corrente
	printf("Digite o ano Corrente: ");
	fflush(stdout);
	scanf("%d", &anoCorrente);

	//Solicita nome do arquivo de entrada
	printf("Digite o nome do Arquivo de Entrada: ");
	fflush(stdout);
	scanf("%s", nomeArquivoEntrada);

	//Solicita nome do arquivo de saida
	printf("Digite o nome do Arquivo de Saida: ");
	fflush(stdout);
	scanf("%s", nomeArquivoSaida);

	FILE *arquivoEntrada, *arquivoSaida;

	//Abre arquivo de entrada no modo leitura
	arquivoEntrada = fopen(nomeArquivoEntrada, "r");
	if (arquivoEntrada == NULL){
		printf("\nErro ao abrir o Arquivo de Entrada!!!\n");
		return 1;
	}

	//Abre arquivo de saida no modo escrita
	arquivoSaida = fopen(nomeArquivoSaida, "w");
	if (arquivoSaida == NULL){
		fclose(arquivoEntrada);
		printf("\nErro ao Criar o arquivo de Saida!!!\n");
		return 1;
	}

	struct Pessoa pessoa;

	//Processa o arquivo de entrada
	while (fscanf(arquivoEntrada, "%39s %d", pessoa.nome, &pessoa.anoNascimento) == 2){
		//Calcula idade
		int idade = calculaIdade(anoCorrente, pessoa.anoNascimento);

		//Obtem a descricao da idade
		const char *descricaoIdade = obterDescricaoIdade(idade);

		//Escreve no arquivo de saida o nome da pessoa e a descricao da idade
		fprintf(arquivoSaida, "%s %s\n", pessoa.nome, descricaoIdade);
	}

	//Fecha arquivos
	fclose(arquivoEntrada);
	fclose(arquivoSaida);

	printf("\nOperacao Concluida!!!\nVerifique o Arquivo de Saida '%s'!!!\n", nomeArquivoSaida);

	return 0;
}

/*Certifique-se de criar o arquivo de texto com conteudo (nome e ano de nascimento), no diretorio onde o programa esta sendo executado*/

