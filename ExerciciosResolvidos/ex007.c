/*
 * ex007.c
 *
 *  Criado em: 9 de nov de 2023
 *      Autor: Renato Gomes de Sousa
 *
 *      https://github.com/RenatoEngineer/ExerciciosSecao11
 */

#include <stdio.h>
#include <ctype.h>

int main(){

	FILE *arquivoEntrada, *arquivoSaida;
	char nomeArquivoEntrada[] = "arquivo.txt";      //Nome do arquivo de entrada
	char nomeArquivoSaida[] = "arquivo_out.txt";   //Nome do arquivo de saida
	char caractere;

	//Abre o arquivo de entrada no modo de leitura
	arquivoEntrada = fopen(nomeArquivoEntrada, "r");
	if (arquivoEntrada == NULL){
		printf("Erro ao abrir o arquivo de Entrada!!!\n");
		return 1;
	}

	//Abre o arquivo de saida no modo de escrita
	arquivoSaida = fopen(nomeArquivoSaida, "w");
	if (arquivoSaida == NULL){
		fclose(arquivoEntrada);
		printf("Erro ao Criar o Arquivo de Saida!!!\n");
		return 1;
	}

	//Processa o arquivo de Entrada
	while ((caractere = fgetc(arquivoEntrada)) != EOF){
		if (isalpha(caractere)){ //Verifica se o caractere e uma letra
			caractere = tolower(caractere); //Converte o caractere para minuscula para facilitar a comparacao
			if (caractere == 'a' || caractere == 'e' || caractere == 'i' || caractere == 'o' || caractere == 'u'){
				fputc('*', arquivoSaida); //Substitui vogais por '*'
			} else {
				fputc(caractere, arquivoSaida); //Mantem as outras letras inalteradas
			}
		} else {
			fputc(caractere, arquivoSaida); //Mantem caracteres nao alfabeticos inalterados
		}
	}

	//Fecha os arquivos
	fclose(arquivoEntrada);
	fclose(arquivoSaida);

	printf("Operacao Concluida!!!\nVerifique o arquivo 'arquivo_out.txt'!!!\n");

	return 0;
}

/*Certifique-se de criar o arquivo "arquivo.txt" no diretório onde o programa está sendo executado*/
