/*
 * ex010.c
 *
 *  Criado em: 10 de nov de 2023
 *      Autor: Renato Gomes de Sousa
 *
 *      https://github.com/RenatoEngineer/ExerciciosSecao11
 */

#include <stdio.h>

#define TAMANHO_NOME_CIDADE 40

//Estrutura para armazenar informacoes da cidade
struct Cidade{
	char nome[TAMANHO_NOME_CIDADE];
	int habitantes;
};

int main(){

	FILE *arquivoEntrada, *arquivoSaida;
	char nomeArquivoEntrada[100], nomeArquivoSaida[100];
	struct Cidade cidadeAtual, cidadeMaisPopulosa;

	//Solicita o nome do arquivo de entrada
	printf("Digite o nome do Arquivo de Entrada: ");
	fflush(stdout);
	scanf("%s", nomeArquivoEntrada);

	//Solicita o nome do arquivo de saida
	printf("Digite o nome do Arquivo de Saida: ");
	fflush(stdout);
	scanf("%s", nomeArquivoSaida);

	//Abre o arquivo de entrada no modo leitura
	arquivoEntrada = fopen(nomeArquivoEntrada, "r");
	if (arquivoEntrada == NULL){
		printf("\nErro ao Abrir o Arquivo de Entrada!!!\n");
		return 1;
	}

	//Inicializa a cidade mais populosa com um valor inicial negativo
	cidadeMaisPopulosa.habitantes = -1;

	//Processa o arquivo de entrada
	while (fscanf(arquivoEntrada, "%39s %d", cidadeAtual.nome, &cidadeAtual.habitantes) == 2){
		//Verifica se a cidade atual tem mais habitantes que a mais populosa ate o momento
		if (cidadeAtual.habitantes > cidadeMaisPopulosa.habitantes){
			cidadeMaisPopulosa = cidadeAtual;
		}
	}

	//Fecha o arquivo de entrada
	fclose(arquivoEntrada);

	//Abre o arquivo de saida no modo de escrita
	arquivoSaida = fopen(nomeArquivoSaida, "w");
	if (arquivoSaida == NULL){
		printf("\nErro ao Criar o Arquivo de Saida!!!\n");
		return 1;
	}

	//Escreve no arquivo de saida a cidade mais populosa e seu numero de habitantes
	fprintf(arquivoSaida, "%s %d\n", cidadeMaisPopulosa.nome, cidadeMaisPopulosa.habitantes);

	//Fecha o arquivo de saida
	fclose(arquivoSaida);

	printf("\nOperacao Concluida!!!\nVerifique o Arquivo de Saida!!!\n");

	return 0;
}

/*Certifique-se de criar o arquivo de texto com conteudo, no diretorio onde o programa esta sendo executado*/

