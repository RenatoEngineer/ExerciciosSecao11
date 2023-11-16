/*
 * ex019.c
 *
 *  Criado em: 16 de nov de 2023
 *      Autor: Renato Gomes de Sousa
 *
 *      https://github.com/RenatoEngineer/ExerciciosSecao11
 */

#include <stdio.h>
#include <string.h>

int main(){

	char nomeArquivo[100];
	printf("Digite o nome do Arquivo: ");
	fflush(stdout);
	scanf("%s", nomeArquivo);

	FILE *arquivo;
	arquivo = fopen(nomeArquivo, "r");

	if (arquivo == NULL){
		printf("\nErro ao abrir o arquivo %s!!!\n", nomeArquivo);
		return 1;
	}

	char nome[100];
	float nota;
	char melhorAluno[100];
	float melhorNota = - 1; //Inicializando com um valor negativo para garantir que qualquer nota seja maior

	//Le cada linha do arquivo e verifica a melhor nota
	while (fscanf(arquivo, "NOME: %99s NOTA: %f ", nome, &nota) == 2){
		printf("Aluno: %s, Nota: %.2f\n", nome, nota);

		//Verifica se a nota atual e a melhor
		if (nota > melhorNota){
			melhorNota = nota;
			strcpy(melhorAluno, nome);
		}
	}

	fclose(arquivo);

	//Verifica se pelo menos um aluno foi lido
	if (melhorAluno >= 0){
		printf("\nMelhor Aluno: %s, Nota: %.2f\n", melhorAluno, melhorNota);
	} else {
		printf("\nNenhum Aluno Encontrado no Arquivo!!!\n");
	}

	return 0;
}

/*Certifique-se de criar o arquivo de texto com conteudo, no diretorio onde o programa esta sendo executado*/
