#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define MAX_GADO 100

struct Gado {  // atributos de cada cabeça de gado
    int codigo;
    float leite;
    float alimento;
    int mes_nascimento;
    int ano_nascimento;
    char abate;};
void lerDados(struct Gado gado[], int *total_gado) { //Solicita ao usuário que insira os dados de cada cabeça de gado.Armazena os dados em um vetor de estruturas `gado[]`.
    printf("Quantidade de gado a ser cadastrado (máximo %d): ", MAX_GADO);
    scanf("%d", total_gado);

    for (int i = 0; i < *total_gado; i++) 
	{   printf("\nCabeça de gado %d:\n", i+1);
        printf("Código: ");
        scanf("%d", &gado[i].codigo);
        printf("Leite produzido por semana (litros): ");
        scanf("%f", &gado[i].leite);
        printf("Alimento ingerido por semana (kg): ");
        scanf("%f", &gado[i].alimento);
        printf("Mês de nascimento: ");
        scanf("%d", &gado[i].mes_nascimento);
        printf("Ano de nascimento: ");
        scanf("%d", &gado[i].ano_nascimento);
        gado[i].abate = 'N'; // Inicializa como 'N' (não irá para o abate) por padrão
    }
}

void preencherAbate(struct Gado gado[], int total_gado) { //Verifica se cada cabeça de gado atende aos criterios para abate e marca para abate se necessário.
    for (int i = 0; i < total_gado; i++) 
	{
        if ((2024 - gado[i].ano_nascimento > 5) ||
            (gado[i].leite < 40) ||
            ((gado[i].leite >= 50 && gado[i].leite <= 70) && gado[i].alimento > 50)) {
            gado[i].abate = 'S'; // Vai para o abate
        }
    }
}

void imprimirTotalLeite(struct Gado gado[], int total_gado) { //Calcula e imprime a quantidade total de leite produzido na fazenda.
    float total_leite = 0;
    for (int i = 0; i < total_gado; i++) {
        total_leite += gado[i].leite;
    }
    printf("Total de leite produzido por semana na fazenda: %.2f litros\n", total_leite);
}

void imprimirTotalAlimento(struct Gado gado[], int total_gado) {
    float total_alimento = 0;
    for (int i = 0; i < total_gado; i++) {
        total_alimento += gado[i].alimento;
    }
    printf("Total de alimento consumido por semana na fazenda: %.2f kg\n", total_alimento);
}

void imprimirLeiteAposAbate(struct Gado gado[], int total_gado) {
    float total_leite_apos_abate = 0;
    for (int i = 0; i < total_gado; i++) {
        if (gado[i].abate == 'N') { // Se não vai para o abate, conta o leite
            total_leite_apos_abate += gado[i].leite;
        }
    }
    printf("Total de leite que será produzido por semana na fazenda, após o abate: %.2f litros\n", total_leite_apos_abate);
}

void imprimirAlimentoAposAbate(struct Gado gado[], int total_gado) {
    float total_alimento_apos_abate = 0;
    for (int i = 0; i < total_gado; i++) {
        if (gado[i].abate == 'N') { // Se não vai para o abate, conta o alimento
        total_alimento_apos_abate += gado[i].alimento;
        }
    }
    printf("Total de alimento que será consumido por semana na fazenda, após o abate: %.2f kg\n", total_alimento_apos_abate);
}

void imprimirGadoParaAbate(struct Gado gado[], int total_gado) {
    int total_abate = 0;
    for (int i = 0; i < total_gado; i++) {
        if (gado[i].abate == 'S') {
            total_abate++;
        }
    }
    printf("Número de cabeças de gado que irão para o abate: %d\n", total_abate);
}

int main() {                                //Principal 
     setlocale(LC_ALL, "Portuguese");
	struct Gado gado[MAX_GADO];
    int total_gado;
    char opcao;

    do {
        printf("-----------------------------------------------\n");
		printf("\nMenu:\n");
        printf("A) Ler base de dados\n");
        printf("B) Preencher campo abate\n");
        printf("C) Imprimir total de leite produzido\n");
        printf("D) Imprimir total de alimento consumido\n");
        printf("E) Imprimir total de leite após abate\n");
        printf("F) Imprimir total de alimento após abate\n");
        printf("G) Imprimir gado para abate\n");
        printf("H) Sair do menu\n");

        printf("Escolha uma opção: ");
        scanf(" %c", &opcao);

        switch (opcao) {
            case 'A':
                lerDados(gado, &total_gado);
                break;
            case 'B':
                preencherAbate(gado, total_gado);
                printf("Campos de abate preenchidos.\n");
                break;
            case 'C':
                imprimirTotalLeite(gado, total_gado);
                break;
            case 'D':
                imprimirTotalAlimento(gado, total_gado);
                break;
            case 'E':
                imprimirLeiteAposAbate(gado, total_gado);
                break;
            case 'F':
                imprimirAlimentoAposAbate(gado, total_gado);
                break;
            case 'G':
                imprimirGadoParaAbate(gado, total_gado);
                break;
            case 'H':
                printf("Encerrando o programa.\n");
                break;
            default:
                printf("Opção inválida.\n");
        }
    } while (opcao != 'H');

    return 0;
}
