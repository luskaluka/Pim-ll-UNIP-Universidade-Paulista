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

    fprintf(arquivo, "\nHorário da Pesquisa: %s\n", ctime(&tempoAtual));

    char perguntas[][140] = {
        "1: Muito Ruim   2: Ruim  3: Normal    4: Bom   5: Muito bom\n1ª: O que achou da visita?",
        "1: Muito Ruim   2: Ruim  3: Normal    4: Bom   5: Muito bom\n2ª: O que achou das obras do tema 100 anos de arte moderna?",
        "1: Muito Ruim   2: Ruim  3: Normal    4: Bom   5: Muito bom\n3ª: O que achou das obras do tema 150 anos de Santos Dumont?",
        "1: Muito Ruim   2: Ruim  3: Normal    4: Bom   5: Muito bom\n4ª: O que achou das obras do tema Jogos olímpicos de Paris 2024?",
        "1: Muito Ruim   2: Ruim  3: Normal    4: Bom   5: Muito bom\n5ª: O que achou das obras do tema A Evolução dos Vídeo-Games?",
        "1: Muito Ruim   2: Ruim  3: Normal    4: Bom   5: Muito bom\n6ª: O que achou da higiene local?",
        "1: Muito Ruim   2: Ruim  3: Normal    4: Bom   5: Muito bom\n7ª: O que achou do atendimento?",
        "1: Sim  2: Não\n8ª: Recomendaria para um amigo?",
        "1: Sim  2: Não\n9ª: Pretende voltar para a próxima edição?",
        "1: Sim  2: Não\n10ª: Foi difícil chegar ao Museu?"
    };

    while (1) {
        printf("Você gostaria de participar da pesquisa de satisfação?");
        printf("\n1- Sim\n2- Não\n");
        printf("R: ");
        scanf("%d", &op);
        system("cls");

        if (op == 1) {
            break;
        }
        if (op == 2) {
            printf("Obrigado pela visita, tenha um ótimo dia!\n");
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
