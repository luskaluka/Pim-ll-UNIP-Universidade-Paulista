#include "stdio.h"
#include "locale.h"
#include "string.h"
#include "time.h"

void Cadastro(char *cpf)
{
    setlocale(LC_ALL, "Portuguese");
    FILE *arquivo = fopen("Cadastro de clientes.txt", "a");

    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }
    time_t tempoAtual;
    time(&tempoAtual);
    fprintf(arquivo, "\nHorário do Cadastro: %s\n", ctime(&tempoAtual));
    char nomeCompleto[100], email[50];
    printf("Nome Completo: ");
    while (1)
    {
        fgets(nomeCompleto, sizeof(nomeCompleto), stdin);
        nomeCompleto[strcspn(nomeCompleto, "\n")] = '\0';
        int valido = 1;
        for (int i = 0; nomeCompleto[i] != '\0'; ++i)
        {
            if (!isalpha(nomeCompleto[i]) && nomeCompleto[i] != ' ')
            {
                valido = 0;
                break;
            }
        }
        if (valido && nomeCompleto[0] != '\0')
        {
            system("cls");
            printf("Nome Completo: %s", nomeCompleto);
            break;
        }
        else
        {
            system("cls");
            printf("Por favor, apenas letras: ");
        }
    }
    system("cls");
    printf("E-mail: ");
    while (1) {
        fgets(email, sizeof(email), stdin);
        email[strcspn(email, "\n")] = '\0';
        if (strchr(email, '@') != NULL) {
            break;
        } else {
            system("cls");
            printf("E-mail inválido. Tente novamente: ");
        }
    }
    system("cls");
    printf("CPF (Apenas números): ");
    while (1)
    {
        fgets(cpf, 20, stdin);
        cpf[strcspn(cpf, "\n")] = '\0';
        int len = strlen(cpf);
        if (len == 11 && strspn(cpf, "0123456789") == len)
        {
            system("cls");
            printf("-- Cadastro feito com sucesso! --\n");
            printf("Nome Completo: %s\n", nomeCompleto);
            fprintf(arquivo, "Nome Completo: %s\n", nomeCompleto);
            printf("E-mail: %s\n", email);
            fprintf(arquivo, "E-mail: %s\n", email);
            printf("CPF: %s", cpf);
            fprintf(arquivo, "CPF: %s", cpf);
            fprintf(arquivo, "\n--------------------------------------");
            printf("\n\nAperte ENTER para continuar...");
            getchar();
            break;
        }
        else
        {
            system("cls");
            printf("CPF (apenas números): ");
        }
    }

    fclose(arquivo);
}

int QuantidadeCpf(char nomes[][20]) {
    int rcpf;
    char input[20];
    printf("--------- Lembretes ---------\n");
    printf("Limite de 3 ingressos por CPF\n");
    printf("Crianças de até 10 anos não pagam\n");
    printf("A meia entrada está disponível para estudantes com comprovante\n");
    printf("E também a todos que apresentarem 1kg de alimento não perecível na entrada\n");
    printf("Inteira: R$20,00\n");
    printf("Meia: R$10,00\n");
    printf("Todos os pagamentos são feitos na entrada com a apresentação do ingresso\n\n");
    printf("Quantos ingressos deseja?\n");
    printf("R: ");
    while (1) {
        fgets(input, sizeof(input), stdin);
        if (sscanf(input, "%d", &rcpf) == 1 && rcpf >= 1 && rcpf <= 3) {
            for (int i = 0; i < rcpf; i++) {
                while (1) {
                    system("cls");
                    printf("Insira o nome do titular do ingresso %d\n", i + 1);
                    printf("R: ");
                    fgets(nomes[i], sizeof(nomes[i]), stdin);
                    nomes[i][strcspn(nomes[i], "\n")] = '\0';
                    int valido = 1;
                    for (int j = 0; nomes[i][j] != '\0'; j++) {
                        if (!isalpha(nomes[i][j]) && nomes[i][j] != ' ') {
                            valido = 0;
                            break;
                        }
                    }
                    if (valido && nomes[i][0] != '\0') {
                        break;
                    }
                }
            }
            break;
        } else {
            system("cls");
            printf("------------- Quantidade inválida -------------\n");
            printf("Lembre-se, temos um limite de 3 ingressos por CPF\n");
            printf("Digite a nova quantidade: ");
        }
    }
    return rcpf;
}

void DataMuseu(int *data)
{
    char buffer[256];
    printf("Para qual data?\n\n");
    while (1)
    {
        printf("1- 04/12/2023\n");
        printf("2- 05/12/2023\n");
        printf("3- 06/12/2023\n");
        printf("4- 07/12/2023\n");
        printf("5- 08/12/2023\n");
        printf("6- 09/12/2023\n");
        printf("7- 10/12/2023\n");
        printf("R: ");

        if (fgets(buffer, sizeof(buffer), stdin) != NULL)
        {
            char *newline = strchr(buffer, '\n');
            if (newline != NULL)
            {
                *newline = '\0';
            }
            if (sscanf(buffer, "%d", data) == 1)
            {
                if (*data >= 1 && *data <= 7)
                {
                    break;
                }
            }
        }
        system("cls");
        printf("------------- Entrada inválida -------------\n");
        printf("Por favor, digite um número de 1 a 7.\n\n");
    }
}

void HoraMuseu(int *hora)
{
    char buffer[256];
    printf("Qual horário?\n");
    printf("1- 10h as 12h\n");
    printf("2- 13h as 15h\n");
    printf("3- 16h as 18h\n");
    printf("4- 19h as 21h\n");
    printf("R: ");
    while (1)
    {
        if (fgets(buffer, sizeof(buffer), stdin) != NULL)
        {
            char *newline = strchr(buffer, '\n');
            if (newline != NULL)
            {
                *newline = '\0';
            }
            if (sscanf(buffer, "%d", hora) == 1)
            {
                if (*hora >= 1 && *hora <= 4)
                {
                    break;
                }
            }
        }
        system("cls");
        printf("--- Horário inválido ---\n");
        printf("Escolha uma das opções\n");
        printf("1- 10h as 12h\n");
        printf("2- 13h as 15h\n");
        printf("3- 16h as 18h\n");
        printf("4- 19h as 21h\n");
        printf("R: ");
    }
}

int gerarNumeroIngresso()
{
    srand(time(NULL));
    int numeroIngresso = rand() % (9999 - 1000 + 1) + 1000;
    return numeroIngresso;
}

int main()
{
    setlocale(LC_ALL, "Portuguese");
    char cpf[20];
    int rcpf, data, hora;
    int numeroIngresso = gerarNumeroIngresso();
    char datas[][20] = {"04/12/2023", "05/12/2023", "06/12/2023", "07/12/2023", "08/12/2023", "09/12/2023", "10/12/2023"};
    char horas[][20] = {"10h as 12h", "13h as 15h", "16h as 18h", "19h as 21h"};
    char nomes[3][20];

    Cadastro(cpf);
    system("cls");

    rcpf = QuantidadeCpf(nomes);
    system("cls");

    DataMuseu(&data);
    system("cls");

    HoraMuseu(&hora);
    system("cls");

    for (int i = 0; i < rcpf; i++)
    {
        printf("---------- Ingresso ----------\n");
        printf("Nome: %s\n", nomes[i]);
        printf("CPF: %s\n", cpf);
        printf("Número do ingresso: %d\n", (numeroIngresso + i));
        printf("Local: Rua dos bobos, 0\n");
        printf("Data: %s\n", datas[data - 1]);
        printf("Hora: %s\n\n", horas[hora - 1]);
    }
    return 0;
}
