/*
 * ex029.c
 *
 *  Criado em: 6 de dez de 2023
 *      Autor: Renato Gomes de Sousa
 *
 *      https://github.com/RenatoEngineer/ExerciciosSecao11
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definindo a estrutura do registro
typedef struct {
    int codigo_vendedor;
    char nome_vendedor[50];
    float valor_da_venda;
    int mes;
} RegistroVenda;

// Prototipos
void criarArquivo(FILE *arquivo);
void incluirRegistro(FILE *arquivo, RegistroVenda novoRegistro);
void excluirVendedor(FILE *arquivo, int codigoVendedor, int mes);
void alterarValorVenda(FILE *arquivo, int codigoVendedor, int mes, float novoValor);
void imprimirRegistros(FILE *arquivo);
void excluirArquivo();
void ordenarArquivo();

// Cria o arquivo de dados
void criarArquivo(FILE *arquivo) {
    fclose(arquivo);
    arquivo = fopen("vendas.dat", "wb");
    if (arquivo == NULL) {
        printf("Erro ao criar o arquivo de dados!!!\n");
        exit(1);
    }
    fclose(arquivo);
}

// Inclui um registro no arquivo
void incluirRegistro(FILE *arquivo, RegistroVenda novoRegistro) {
    arquivo = fopen("vendas.dat", "ab");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo de dados!!!\n");
        exit(1);
    }

    // Escreve o registro no arquivo
    fwrite(&novoRegistro, sizeof(RegistroVenda), 1, arquivo);

    // Ordena o arquivo apos a inclusao
    ordenarArquivo();

    fclose(arquivo);
}

// Exclui um vendedor no arquivo
void excluirVendedor(FILE *arquivo, int codigoVendedor, int mes) {
    arquivo = fopen("vendas.dat", "rb");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo de dados!!!\n");
        exit(1);
    }

    FILE *tempFile = fopen("temp.dat", "wb");
    if (tempFile == NULL) {
        printf("Erro ao criar o arquivo temporario!!!\n");
        fclose(arquivo);
        exit(1);
    }

    RegistroVenda registro;

    // Le e escreve registros, exceto o que deve ser excluido
    while (fread(&registro, sizeof(RegistroVenda), 1, arquivo) == 1) {
        if (registro.codigo_vendedor != codigoVendedor || registro.mes != mes) {
            fwrite(&registro, sizeof(RegistroVenda), 1, tempFile);
        }
    }

    fclose(arquivo);
    fclose(tempFile);

    // Substitui o arquivo original pelo temporario
    remove("vendas.dat");
    rename("temp.dat", "vendas.dat");
}

// Altera o valor de uma venda no arquivo
void alterarValorVenda(FILE *arquivo, int codigoVendedor, int mes, float novoValor) {
    arquivo = fopen("vendas.dat", "rb+");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo de dados!!!\n");
        exit(1);
    }

    RegistroVenda registro;

    // Busca o registro a ser alterado
    while (fread(&registro, sizeof(RegistroVenda), 1, arquivo) == 1) {
        if (registro.codigo_vendedor == codigoVendedor && registro.mes == mes) {
            // Atualiza o valor da venda
            registro.valor_da_venda = novoValor;

            // Posiciona o cursor para a posicao correta
            fseek(arquivo, -((long long int)sizeof(RegistroVenda)), SEEK_CUR);

            // Escreve o registro modificado de volta ao arquivo
            fwrite(&registro, sizeof(RegistroVenda), 1, arquivo);

            break;
        }
    }

    fclose(arquivo);
}

// Imprime os registros na saida padrao
void imprimirRegistros(FILE *arquivo) {
    arquivo = fopen("vendas.dat", "rb");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo de dados!!!\n");
        exit(1);
    }

    RegistroVenda registro;

    // Imprime os registros
    while (fread(&registro, sizeof(RegistroVenda), 1, arquivo) == 1) {
        printf("Codigo: %d, Nome: %s, Valor: %.2f, Mes: %d\n",
               registro.codigo_vendedor, registro.nome_vendedor,
               registro.valor_da_venda, registro.mes);
    }

    fclose(arquivo);
}

// Exclui o arquivo de dados
void excluirArquivo() {
    if (remove("vendas.dat") == 0) {
        printf("Arquivo de dados excluido com sucesso!!!\n");
    } else {
        printf("Erro ao excluir o arquivo de dados!!!\n");
    }
}

// Compara dois registros para ordenacao
int compararRegistros(const void *a, const void *b) {
    RegistroVenda *registroA = (RegistroVenda *)a;
    RegistroVenda *registroB = (RegistroVenda *)b;

    // Compara primeiro pelo codigo do vendedor e depois pelo mes
    if (registroA->codigo_vendedor == registroB->codigo_vendedor) {
        return registroA->mes - registroB->mes;
    } else {
        return registroA->codigo_vendedor - registroB->codigo_vendedor;
    }
}

// Ordena o arquivo
void ordenarArquivo() {
    FILE *arquivo = fopen("vendas.dat", "rb");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo de dados!!!\n");
        exit(1);
    }

    RegistroVenda registros[1000]; // Assumindo no maximo 1000 registros

    int numRegistros = 0;

    // Le os registros para o array
    while (fread(&registros[numRegistros], sizeof(RegistroVenda), 1, arquivo) == 1) {
        numRegistros++;
    }

    fclose(arquivo);

    // Ordena o array de registros
    qsort(registros, numRegistros, sizeof(RegistroVenda), compararRegistros);

    // Reescreve o arquivo ordenado
    arquivo = fopen("vendas.dat", "wb");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo de dados!!!\n");
        exit(1);
    }

    // Escreve os registros ordenados de volta ao arquivo
    for (int i = 0; i < numRegistros; i++) {
        fwrite(&registros[i], sizeof(RegistroVenda), 1, arquivo);
    }

    fclose(arquivo);
}

int main() {
    int escolha;
    FILE *arquivo = fopen("vendas.dat", "rb");

    if (arquivo == NULL) {
        printf("Arquivo de dados nao encontrado!!! Criando...\n");
        criarArquivo(arquivo);
        arquivo = fopen("vendas.dat", "rb");
    }

    do {
        printf("\n.:: MENU ::.\n");
        printf("1. Criar o arquivo de dados\n");
        printf("2. Incluir um determinado Registro no Arquivo\n");
        printf("3. Excluir um determinado Vendedor no Arquivo\n");
        printf("4. Alterar o valor de uma Venda no Arquivo\n");
        printf("5. Imprimir os registros na Saida Padrao\n");
        printf("6. Excluir o arquivo de Dados\n");
        printf("7. Finalizar o Programa\n");

        printf("\nEscolha uma opcao: ");
        fflush(stdout);
        scanf("%d", &escolha);

        switch (escolha) {
            case 1: {
                criarArquivo(arquivo);
                break;
            }
            case 2: {
                RegistroVenda novoRegistro;
                printf("Digite o Codigo do Vendedor: ");
                fflush(stdout);
                scanf("%d", &novoRegistro.codigo_vendedor);

                printf("Digite o Nome do Vendedor: ");
                fflush(stdout);
                scanf("%s", novoRegistro.nome_vendedor);

                printf("Digite o Valor da Venda: ");
                fflush(stdout);
                scanf("%f", &novoRegistro.valor_da_venda);

                printf("Digite o mes: ");
                fflush(stdout);
                scanf("%d", &novoRegistro.mes);
                incluirRegistro(arquivo, novoRegistro);
                break;
            }
            case 3: {
                int codigoVendedor, mes;
                printf("Digite o codigo do vendedor a ser excluido: ");
                fflush(stdout);
                scanf("%d", &codigoVendedor);

                printf("Digite o mes do registro a ser excluido: ");
                fflush(stdout);
                scanf("%d", &mes);
                excluirVendedor(arquivo, codigoVendedor, mes);
                break;
            }
            case 4: {
                int codigoVendedor, mes;
                float novoValor;
                printf("Digite o codigo do vendedor: ");
                fflush(stdout);
                scanf("%d", &codigoVendedor);

                printf("Digite o mes do registro: ");
                fflush(stdout);
                scanf("%d", &mes);

                printf("Digite o novo valor da venda: ");
                fflush(stdout);
                scanf("%f", &novoValor);
                alterarValorVenda(arquivo, codigoVendedor, mes, novoValor);
                break;
            }
            case 5: {
                imprimirRegistros(arquivo);
                break;
            }
            case 6: {
                excluirArquivo();
                break;
            }
            case 7: {
                printf("Programa finalizado.\n");
                break;
            }
            default: {
                printf("Opcao Invalida. Tente novamente.\n");
            }
        }
    } while (escolha != 7);

    fclose(arquivo);

    return 0;
}
