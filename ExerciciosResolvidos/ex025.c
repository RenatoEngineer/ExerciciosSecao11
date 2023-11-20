/*
 * ex025.c
 *
 *  Criado em: 20 de nov de 2023
 *      Autor: Renato Gomes de Sousa
 *
 *      https://github.com/RenatoEngineer/ExerciciosSecao11
 */

#include <stdio.h>
#include <string.h>

#define MAX_NOME 50

//Estrutura para armazenar informacoes dos contatos
struct Contato{
	char nome[MAX_NOME + 1];
	char telefone[15]; //Considerando o formato "xx-xxxxx-xxxx"
	int diaAniversario;
	int mesAniversario;
};

//Funcao para inserir um contato na agenda
void insereContato(FILE *arquivo, struct Contato *contato){
	fseek(arquivo, 0, SEEK_END); //Move o ponteiro para o final do arquivo

	//Escreve os dados do contato no arquivo
	fwrite(contato, sizeof(struct Contato), 1, arquivo);

	printf("\nContato Inserido com Sucesso!!!\n");
}

//Remove um contato da agenda pelo nome
void removeContato(FILE *arquivo, const char *nome){
	fseek(arquivo, 0, SEEK_SET); //Move o ponteiro para o inicio do arquivo

	struct Contato contato;

	//Cria um arquivo temporario para armazenar os contatos excluindo o contato desejado
	FILE *arquivoTemp = fopen("temp.bin", "wb");
	if (arquivoTemp == NULL){
		printf("\nErro ao abrir o arquivo Temporario!!!\n");
		return;
	}

	//Le os dados do arquivo e escreve no arquivo temporario, excluindo o contato desejado
	while (fread(&contato, sizeof(struct Contato), 1, arquivo) == 1){
		if (strcmp(contato.nome, nome) != 0){
			fwrite(&contato, sizeof(struct Contato), 1, arquivoTemp);
		}
	}

	fclose(arquivo);
	fclose(arquivoTemp);

	//Remove o arquivo original
	remove("contatos.bin");

	//Renomeia o arquivo temporario para o nome original
	rename("temp.bin", "contatos.bin");

	printf("\nContato removido com Sucesso!!!\n");
}

//Funcao para pesquisar um contato pelo nome
void pesquisaContato(FILE *arquivo, const char *nome){
	fseek(arquivo, 0, SEEK_SET); //Move o ponteiro para o inicio do arquivo

	struct Contato contato;

	//Le os dados do arquivo e procura o contato com o nome especificado
	while (fread(&contato, sizeof(struct Contato), 1, arquivo) == 1){
		if (strcmp(contato.nome, nome) == 0){
			printf("\nContato Encontrado:\n");
			printf("Nome: %s\n", contato.nome);
			printf("Telefone: %s\n", contato.telefone);
			printf("Aniversario: %d/%d\n", contato.diaAniversario, contato.mesAniversario);
			return;
		}
	}

	printf("\nContato nao Encontrado!!!\n");
}

//Funcao para listar todos os contatos na agenda
void listaContatos(FILE *arquivo){
	fseek(arquivo, 0, SEEK_SET); //Move o ponteiro para o inicio do arquivo

	struct Contato contato;

	printf("\nLista de Contatos:\n");

	//Le os dados do arquivo e imprime as informacoes de cada contato
	while (fread(&contato, sizeof(struct Contato), 1, arquivo) == 1){
		printf("Nome: %s\n", contato.nome);
		printf("Telefone: %s\n", contato.telefone);
		printf("Aniversario: %d/%d\n", contato.diaAniversario, contato.mesAniversario);
		printf("\n");
	}
}

//Funcao para listar os contatos cujo nome indica com uma dada letra
void listaContatoLetra(FILE *arquivo, char letra){
	fseek(arquivo, 0, SEEK_SET); //Move o ponteiro para o inicio do arquivo

	struct Contato contato;

	printf("\nContatos que o nome inicia com: '%c':\n", letra);

	//Le os dados do arquivo e imprime as informacoes dos contatos que inicia com a letra especificada
	while (fread(&contato, sizeof(struct Contato), 1, arquivo) == 1){
		if (contato.nome[0] == letra){
			printf("Nome: %s\n", contato.nome);
			printf("Telefone: %s\n", contato.telefone);
			printf("Aniversario: %d/%d\n", contato.diaAniversario, contato.mesAniversario);
			printf("\n");
		}
	}
}

//Funcao para imprimir os aniversariantes do mes
void imprimeAniversariantesMes(FILE *arquivo, int mes){
	fseek(arquivo, 0, SEEK_SET); //Move o ponteiro para o inicio do arquivo

	struct Contato contato;

	printf("\nAniversariantes do Mes %d:\n", mes);

	//Le os dados do arquivo e imprime as informacoes dos contatos que fazem aniversario no mes especificado
	while (fread(&contato, sizeof(struct Contato), 1, arquivo) == 1){
		if (contato.mesAniversario == mes){
			printf("Nome: %s\n", contato.nome);
			printf("Telefone: %s\n", contato.telefone);
			printf("Aniversario: %d/%d\n", contato.diaAniversario, contato.mesAniversario);
			printf("\n");
		}
	}
}

int main(){

	FILE *arquivo;

	//Abre o arquivo para leitura e escrita binaria
	arquivo = fopen("contatos.bin", "rb+");

	//Se o arquivo nao existir, cria um novo arquivo
	if (arquivo == NULL){
		arquivo = fopen("contatos.bin", "wb+");
		if (arquivo == NULL){
			printf("\nErro ao Criar o arquivo 'contatos.bin'!!!\n");
			return 1;
		}
	}

	int escolha;
	struct Contato novoContato;

	//Le os contatos do arquivo
	fread(&novoContato, sizeof(struct Contato), 1, arquivo);

	while (1){
		printf("\n.:: Gerenciamento de Agenda de Contatos ::.\n");
		printf("[1] Inserir Contato\n");
		printf("[2] Remover Contato\n");
		printf("[3] Pesquisar Contato\n");
		printf("[4] Listar Todos os Contatos\n");
		printf("[5] Listar Contatos por Inicial do Nome\n");
		printf("[6] Imprimir Aniversariante do Mes\n");
		printf("[0] Sair\n");
		printf("Escolha uma Opcao: ");
		fflush(stdout);
		scanf("%d", &escolha);

		switch (escolha){
		case 1:
			printf("Digite o nome do Contato: ");
			fflush(stdout);
			scanf(" %[^\n]", novoContato.nome);

			printf("Digite o Telefone do Contato (formato xx-xxxxx-xxxx): ");
			fflush(stdout);
			scanf("%s", novoContato.telefone);

			printf("Digite o dia do Aniversario do Contato: ");
			fflush(stdout);
			scanf("%d", &novoContato.diaAniversario);

			printf("Digite o mes do Aniversario do Contato: ");
			fflush(stdout);
			scanf("%d", &novoContato.mesAniversario);

			insereContato(arquivo, &novoContato);
			break;

		case 2:
			printf("Digite o Nome do Contato a ser Removido: ");
			fflush(stdout);
			scanf(" %[^\n]", novoContato.nome);

			removeContato(arquivo, novoContato.nome);
			break;

		case 3:
			printf("Digite o Nome do Contato a ser Pesquisado: ");
			fflush(stdout);
			scanf(" %[^\n]", novoContato.nome);

			pesquisaContato(arquivo, novoContato.nome);
			break;

		case 4:
			listaContatos(arquivo);
			break;

		case 5:
			printf("Digite a Letra Inicial para Listar os Contatos: ");
			fflush(stdout);
			scanf(" %c", &novoContato.nome[0]);

			listaContatoLetra(arquivo, novoContato.nome[0]);
			break;

		case 6:
			printf("Digite o Mes para Imprimir os Aniversariantes: ");
			fflush(stdout);
			scanf("%d", &novoContato.mesAniversario);

			imprimeAniversariantesMes(arquivo, novoContato.mesAniversario);
			break;

		case 0:
		printf("Saindo do Programa...!!!\n");
		fclose(arquivo);
		return 0;

		default:
			printf("\nOpcao Invalida!!! Tente novamente!\n");
		}
	}

	fclose(arquivo);

	return 0;
}
