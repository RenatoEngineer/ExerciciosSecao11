/*
 * ex024.c
 *
 *  Criado em: 19 de nov de 2023
 *      Autor: Renato Gomes de Sousa
 *
 *      https://github.com/RenatoEngineer/ExerciciosSecao11
 */

#include <stdio.h>

#define MAX_DESCRICAO 50

//Estrutura para armazenar informacoes dos produtos
struct Produto{
	int codigo;
	char descricao[MAX_DESCRICAO + 1];
	int quantidade;
};

//Funcao para adicionar um produto ao estoque
void adicionaProduto(FILE *arquivo, struct Produto *produto){
	fseek(arquivo, 0, SEEK_END); //Move o ponteiro para o final do arquivo

	//Escreve os dados do produto no arquivo
	fwrite(produto, sizeof(struct Produto), 1, arquivo);

	printf("Produto adicionado com sucesso!!!\n");
}

//Funcao para retirar um produto do estoque
void retiraProduto(FILE *arquivo, int codigo){
	fseek(arquivo, 0, SEEK_SET); //Move o ponteiro para o inicio do arquivo

	struct Produto produto;

	//Le os dados do arquivo e procura o produto com o codigo especificado
	while (fread(&produto, sizeof(struct Produto), 1, arquivo) == 1){
		if (produto.codigo == codigo){
			//Atualiza a quantidade do produto no arquivo
			produto.quantidade--;

			fseek(arquivo, -sizeof(struct Produto), SEEK_CUR); //Move o ponteiro de volta para a posicao correta
			fwrite(&produto, sizeof(struct Produto), 1, arquivo);

			printf("Produto retirado com sucesso!\n");
			return;
		}
	}

	printf("Produto nao Encontrado!!!\n");
}

//Funcao para gerar um relatorio geral de produtos
void relatorioGeral(FILE *arquivo){
	fseek(arquivo, 0, SEEK_SET); //Move o ponteiro para o inicio do arquivo

	struct Produto produto;

	printf("\nRelatorio Geral de Produtos:\n");

	//Le os dados do arquivo e imprime as informacoes de cada produto
	while (fread(&produto, sizeof(struct Produto), 1, arquivo) == 1){
		printf("Codigo: %d\n", produto.codigo);
		printf("Descricao: %s\n", produto.descricao);
		printf("Quantidade: %d\n", produto.quantidade);
		printf("\n");
	}
}

//Funcao para gerar um relatorio de produtos indisponiveis
void relatorioIndisponiveis(FILE *arquivo){
	fseek(arquivo, 0, SEEK_SET); //Move o ponteiro para o inicio do arquivo

	struct Produto produto;

	printf("\nRelatorio de Produtos Nao Disponiveis:\n");

	//Le os dados do arquivo e imprime as informacoes de produtos com quantidade zero
	while (fread(&produto, sizeof(struct Produto), 1, arquivo) == 1){
		if (produto.quantidade == 0){
			printf("Codigo: %d\n", produto.codigo);
			printf("Descricao: %s\n", produto.descricao);
			printf("\n");
		}
	}
}

int main(){

	FILE *arquivo;

	//Abre o arquivo para leitura e escrita binaria
	arquivo = fopen("estoque.bin", "rb+");

	//Se o arquivo nao existir, cria um
	if (arquivo == NULL){
		arquivo = fopen("estoque.bin", "wb+");
		if (arquivo == NULL){
			printf("\nErro ao Criar o Arquivo 'estoque.bin'!!!\n");
			return 1;
		}
	}

	int escolha;
	struct Produto novoProduto;

	while (1){
		printf("\n.:: CONTROLE DE MERCADORIAS ::.\n\n");
		printf("[1] Adicionar Produto\n");
		printf("[2] Retirar Produto\n");
		printf("[3] Relatorio Geral\n");
		printf("[4] Relatorio Produtos Nao Disponiveis\n");
		printf("[0] Sair\n");
		printf("Escolha uma Opcao: ");
		fflush(stdout);
		scanf("%d", &escolha);

		switch (escolha){
		case 1:
			printf("Digite o Codigo do Produto: ");
			fflush(stdout);
			scanf("%d", &novoProduto.codigo);

			printf("Digite a Descricao do Produto: ");
			fflush(stdout);
			scanf(" %[^\n]", novoProduto.descricao);

			printf("Digite a Quantidade do Produto: ");
			fflush(stdout);
			scanf("%d", &novoProduto.quantidade);

			adicionaProduto(arquivo, &novoProduto);
			break;

		case 2:
			printf("Digite o Codigo do Produto a Ser Retirado: ");
			fflush(stdout);
			scanf("%d", &novoProduto.codigo);

			retiraProduto(arquivo, novoProduto.codigo);
			break;

		case 3:
			relatorioGeral(arquivo);
			break;

		case 4:
			relatorioIndisponiveis(arquivo);
			break;

		case 0:
			printf("Saindo do Programa...!!!\n");
			fclose(arquivo);
			return 0;

		default:
			printf("Opcao Invalida!!! Tente Novamente!!!\n");
		}
	}

	fclose(arquivo);

	return 0;
}
