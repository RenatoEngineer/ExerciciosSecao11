/*
 * ex016.c
 *
 *  Criado em: 14 de nov de 2023
 *      Autor: Renato Gomes de Sousa
 *
 *      https://github.com/RenatoEngineer/ExerciciosSecao11
 */

#include <stdio.h>

//Funcao para converter um numero para binario e gravar em um arquivo
void converteBinario(int numero, FILE *arquivo){
	//Converte o numero para binario e grava no arquivo
	fprintf(arquivo, "%d em Binario: ", numero);
	for (int i = 31; i >= 0; i--){ //Usado 31 para garantir percorrer todos os bits de um numero de 32 bits
		int bit = (numero >> i) & 1;
		fprintf(arquivo, "%d", bit);
	}

	fprintf(arquivo, "\n");
}

int main(){

	int numeros[10];

	//Solicita os 10 numeros
	printf("Digite 10 Numeros Inteiros:\n");
	for (int i = 0; i < 10; i++){
		printf("Numero %d: ", i + 1);
		fflush(stdout);
		scanf("%d", &numeros[i]);
	}

	//Abre o arquivo no modo de Escrita
	FILE *arquivo = fopen("saidaBinario.txt", "w");
	if (arquivo == NULL){
		printf ("\nErro ao Criar o Arquivo!!!\n");
		return 1;
	}

	//Converte e grava cada numero no arquivo
	for (int i = 0; i < 10; i++){
		converteBinario(numeros[i], arquivo);
	}

	//Fecha o arquivo
	fclose(arquivo);

	printf("\nOperacao Concluida!!!\nVerifique o arquivo 'saidaBinario.txt'\n");

	return 0;
}
