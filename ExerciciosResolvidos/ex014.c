/*
 * ex014.c
 *
 *  Criado em: 14 de nov de 2023
 *      Autor: Renato Gomes de Sousa
 *
 *      https://github.com/RenatoEngineer/ExerciciosSecao11
 */

#include <stdio.h>
#include <time.h>

#define TAMANHO_NOME 100

struct Pessoa{
	char nome[TAMANHO_NOME];
	int dia, mes, ano;
};

//Funcao para calcular a idade com base na data de nascimento e na data atual
int calculaIdade(struct Pessoa pessoa, struct tm dataAtual){
	int idade = dataAtual.tm_year + 1900 - pessoa.ano;

	//Ajuste da idade se o aniversario ainda nao ocorreu este ano
	if (dataAtual.tm_mon < pessoa.mes - 1 || (dataAtual.tm_mon == pessoa.mes - 1 && dataAtual.tm_mday < pessoa.dia)){
		idade--;
	}

	return idade;
}

int main(){

	FILE *arquivoEntrada, *arquivoSaida;
	char nomeArquivoEntrada[] = "arquivo.txt";
	char nomeArquivoSaida[] = "idade.txt";

	//Abre o arquivo de entrada no modo de leitura
	arquivoEntrada = fopen(nomeArquivoEntrada, "r");
	if (arquivoEntrada == NULL){
		printf("\nErro ao Abrir o Arquivo de Entrada!!!\n");
		return 1;
	}

	//Abre o arquivo de saida no modo de escrita
	arquivoSaida = fopen(nomeArquivoSaida, "w");
	if (arquivoSaida == NULL){
		fclose(arquivoEntrada);
		printf("\nErro ao Criar o Arquivo de Saida!!!\n");
		return 1;
	}

	struct Pessoa pessoa;
	time_t agora;
	struct tm *dataAtual;

	//Obtem a data atual
	time(&agora);
	dataAtual = localtime(&agora);

	//Processa o arquivo de entrada
	while (fscanf(arquivoEntrada, "%99s %d %d %d", pessoa.nome, &pessoa.dia, &pessoa.mes, &pessoa.ano) == 4){
		//Calcula Idade
		int idade = calculaIdade(pessoa, *dataAtual);

		//Escreve no arquivo de saida o nome e a idade
		fprintf(arquivoSaida, "%s %d\n", pessoa.nome, idade);
	}

	//Fecha os arquivos
	fclose(arquivoEntrada);
	fclose(arquivoSaida);

	printf("Operacao Concluida!!!\nVerifique o arquivo de Saida '%s'!!!\n", nomeArquivoSaida);

	return 0;
}

/*Certifique-se de criar o arquivo "arquivo.txt" no diretório onde o programa está sendo executado*/

