#include <stdio.h>
#include <locale.h>
#include <conio.h>
#include <time.h>

int main() {
    setlocale(LC_ALL, "Portuguese");
    int respostas[10];
    int op;

    FILE *arquivo = fopen("Registro Pesquisa.txt", "a");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    time_t tempoAtual;
    time(&tempoAtual);

    fprintf(arquivo, "\nHor�rio da Pesquisa: %s\n", ctime(&tempoAtual));

    char perguntas[][140] = {
        "1: Muito Ruim   2: Ruim  3: Normal    4: Bom   5: Muito bom\n1�: O que achou da visita?",
        "1: Muito Ruim   2: Ruim  3: Normal    4: Bom   5: Muito bom\n2�: O que achou das obras do tema 100 anos de arte moderna?",
        "1: Muito Ruim   2: Ruim  3: Normal    4: Bom   5: Muito bom\n3�: O que achou das obras do tema 150 anos de Santos Dumont?",
        "1: Muito Ruim   2: Ruim  3: Normal    4: Bom   5: Muito bom\n4�: O que achou das obras do tema Jogos ol�mpicos de Paris 2024?",
        "1: Muito Ruim   2: Ruim  3: Normal    4: Bom   5: Muito bom\n5�: O que achou das obras do tema A Evolu��o dos V�deo-Games?",
        "1: Muito Ruim   2: Ruim  3: Normal    4: Bom   5: Muito bom\n6�: O que achou da higiene local?",
        "1: Muito Ruim   2: Ruim  3: Normal    4: Bom   5: Muito bom\n7�: O que achou do atendimento?",
        "1: Sim  2: N�o\n8�: Recomendaria para um amigo?",
        "1: Sim  2: N�o\n9�: Pretende voltar para a pr�xima edi��o?",
        "1: Sim  2: N�o\n10�: Foi dif�cil chegar ao Museu?"
    };

    while (1) {
        printf("Voc� gostaria de participar da pesquisa de satisfa��o?");
        printf("\n1- Sim\n2- N�o\n");
        printf("R: ");
        scanf("%d", &op);
        system("cls");

        if (op == 1) {
            break;
        }
        if (op == 2) {
            printf("Obrigado pela visita, tenha um �timo dia!\n");
            fclose(arquivo);
            return 0;
        }
    }
    for (int i = 0; i <= 9; i++) {
        printf("%s\n", perguntas[i]);
        scanf("%d", &respostas[i]);
        system("cls");

        if (i < 7 && (respostas[i] < 6 && respostas[i] > 0))
        {
            fprintf(arquivo, "%s: \nR:%d\n\n", perguntas[i], respostas[i]);
        }
        else if (i > 6 && (respostas[i] == 1 || respostas[i] == 2))
        {
            fprintf(arquivo, "%s: \nR:%d\n\n", perguntas[i], respostas[i]);
        }

        if (respostas[i] > 5 || respostas[i] < 1)
        {
            i--;
        }
        else if (i > 6 && (respostas[i] > 2 || respostas[i] < 1))
        {
            i--;
        }
    }

    fprintf(arquivo, "-----------------------------------------------------------------------");
    printf("Obrigado Pela Visita!\n");
    fclose(arquivo);
    return 0;
}
