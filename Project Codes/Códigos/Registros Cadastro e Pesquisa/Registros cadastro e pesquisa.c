#include "stdio.h"
#include "stdlib.h"
#include <locale.h>

void Cadastro()
{
    setlocale(LC_ALL, "Portuguese");
    FILE *file;
    file = fopen("..\\Cadastro de Clientes\\Cadastro de clientes.txt","r");
    if(file == NULL)
    {
    perror("Erro ao abrir o arquivo");
    exit(1);
    }
    char frase[100];
    while(fgets(frase, 100, file) != NULL)
    {
        printf("%s", frase);
    }
    fclose(file);
    return 0;
}

void Pesquisa()
{
    setlocale(LC_ALL, "Portuguese");
    FILE *file;
    file = fopen("..\\Pesquisa de Satisfação\\Registro Pesquisa.txt","r");
    if(file == NULL)
    {
    perror("Erro ao abrir o arquivo");
    exit(1);
    }
    char frase[100];
    while(fgets(frase, 100, file) != NULL)
    {
        printf("%s", frase);
    }
    fclose(file);
    return 0;
}

int main()
{
    setlocale(LC_ALL, "Portuguese");
    int resp;
    while(1)
    {
        system("cls");
        printf("Qual deseja consultar?\n");
        printf("1- Cadastro dos clientes\n");
        printf("2- Pesquisa de satisfação\n");
        printf("3- Sair\n");
        printf("R: ");
        scanf("%d", &resp);
        while(1)
        {
            if(resp < 0 || resp > 3)
            {
                system("cls");
                printf("-------------- Numero inválido --------------\n");
                printf("Por favor, digite um numero presente nas opções\n");
                printf("1- Cadastro dos clientes\n");
                printf("2- Pesquisa de satisfação\n");
                printf("3- Sair\n");
                printf("R: ");
                scanf("%d", &resp);
            }
            if(resp == 1)
            {
                system("cls");
                Cadastro();
                printf("\nPressione ENTER para continuar");
                while (getchar() != '\n');
                getchar();
                break;
            }
            else if(resp == 2)
            {
                system("cls");
                Pesquisa();
                printf("\nPressione ENTER para continuar");
                while (getchar() != '\n');
                getchar();
                break;
            }
            else if(resp == 3)
            {
                system("cls");
                printf("Obrigado!\n");
                return 0;
            }
        }
    }
}
