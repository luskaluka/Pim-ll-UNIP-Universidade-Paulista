#include <stdio.h>
#include <locale.h>
#include <dirent.h>
#include <string.h>

int listarArquivos(const char *caminho, char arquivos[][256]) {
    struct dirent *entry;
    DIR *dir = opendir(caminho);

    if (dir == NULL) {
        perror("Erro ao abrir o diretório");
        return -1;
    }

    int contadorArquivos = 0;

    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_REG) {
            strcpy(arquivos[contadorArquivos], entry->d_name);
            printf("%d: %s\n", ++contadorArquivos, entry->d_name);
        }
    }

    closedir(dir);

    return contadorArquivos;
}

int main() {
    setlocale(LC_ALL, "Portuguese");
    int op, tema, obra;
    char temas[][50] = {"100 Anos da Semana de Arte Moderna", "150 Anos de Santos Dumont", "A Evolução dos Vídeo-Games", "Jogos Olímpicos de Paris 2024"};
    char arquivos[5][256];

    while (1) {
        printf("1- Gerenciar Temas\n2- Gerenciar Obras\n3- Sair\nR: ");
        scanf("%d", &op);
        system("cls");

        if (op == 3)
        {
            return 0;
        }
        else if (op == 1) {
            int alterar;
            while (1) {
                for (int i = 1; i < 5; i++) {
                    printf("%d: %s\n", i, temas[i - 1]);
                }
                printf("5: Voltar\nR: ");
                scanf("%d", &tema);
                system("cls");
                if (tema == 5)
                {
                    break;
                }
                if (tema < 5 && tema > 0) {
                    break;
                }
            }
            if (tema >= 1 && tema <= 4) {
                char caminho[100];
                sprintf(caminho, "../Temas/%s.txt", temas[tema - 1]);

                FILE *arquivo = fopen(caminho, "r");

                if (arquivo == NULL) {
                    perror("Erro ao abrir o arquivo");
                    return 1;
                }

                char descricao[9999];
                while (fgets(descricao, sizeof(descricao), arquivo) != NULL) {
                    printf("%s\n", descricao);
                }
                fclose(arquivo);

                printf("\n\n1- Sim  2- Não\nDeseja alterar a descrição do texto?\nR: ");
                scanf("%d", &alterar);
                system("cls");

                if (alterar == 1) {
                    FILE *alterando = fopen(caminho, "w");

                    if (alterando == NULL) {
                        perror("Erro ao abrir o arquivo para escrita");
                        return 1;
                    }

                    printf("Insira a nova descrição do tema:\nR: ");
                    char novadesc[9999];
                    scanf(" %[^\n]", novadesc);

                    fprintf(alterando, "%s", novadesc);

                    fclose(alterando);
                    system("cls");
                    printf("Descrição alterada com sucesso!\n");
                } else if (alterar == 2) {
                    continue;
                } else {
                    printf("Opção inválida.\n");
                }
            }
        }

        else if (op == 2) {
            int acao;
            while (1) {
                for (int i = 1; i < 5; i++) {
                    printf("%d: %s\n", i, temas[i - 1]);
                }
                printf("5: Voltar\nR: ");

                scanf("%d", &tema);
                system("cls");

                if (tema == 5)
                {
                    break;
                }

                if (tema < 5 && tema > 0) {
                    char caminho[100];
                    sprintf(caminho, "../Temas/%s", temas[tema - 1]);

                    int quantidadeObras = listarArquivos(caminho, arquivos);
                    system("cls");

                    if (quantidadeObras > 0) {
                        while (1) {
                            listarArquivos(caminho, arquivos);

                            printf("\n1- Incluir 2-Excluir 3-Consultar 4-Alterar 5-Voltar\nR: ");
                            scanf("%d", &acao);
                            system("cls");

                            if (acao > 0 && acao < 6)
                            {
                                listarArquivos(caminho, arquivos);
                                break;
                            }
                        }
                        if (acao == 5)
                        {
                            system("cls");
                            break;
                        }
                        if (acao != 1 && acao != 5)
                        {
                            printf("Escolha a obra (1-%d):\nR: ", quantidadeObras);
                            scanf("%d", &obra);
                            system("cls");
                        }
                        else
                        {
                            obra = 1;
                            system("cls");
                        }

                        if (obra > 0 && obra <= quantidadeObras) {
                            if (acao == 1)
                            {
                                char nomeNovaObra[256];

                                printf("Digite o nome para o novo arquivo (sem espaços, incluindo .txt):\nR: ");
                                scanf("%s.txt", nomeNovaObra);

                                char caminho_nova_obra[256];
                                sprintf(caminho_nova_obra, "../Temas/%s/%s", temas[tema - 1], nomeNovaObra);

                                FILE *verificar_arquivo = fopen(caminho_nova_obra, "r");
                                if (verificar_arquivo != NULL) {
                                    fclose(verificar_arquivo);
                                    printf("O arquivo %s já existe. Escolha outro nome.\nR: ", nomeNovaObra);
                                    continue;
                                }

                                FILE *nova_obra = fopen(caminho_nova_obra, "w");
                                if (nova_obra == NULL) {
                                    perror("Erro ao criar o nova obra");
                                    break;
                                }

                                printf("Insira o conteúdo do novo arquivo:\nR: ");
                                char conteudo_nova_obra[9999];
                                scanf(" %[^\n]", conteudo_nova_obra);

                                fprintf(nova_obra, "%s", conteudo_nova_obra);

                                fclose(nova_obra);
                                system("cls");
                                printf("Nova obra criada com sucesso!\n");
                                break;
                            }
                            else if (acao == 2)
                            {
                                printf("Tem certeza que deseja excluir a obra %d? (1- Sim, 2- Não)\nR: ", obra);
                                    int confirmacao;
                                    scanf("%d", &confirmacao);

                                    if (confirmacao == 1) {
                                        char nomeDaObra[256];
                                        strcpy(nomeDaObra, arquivos[obra - 1]);

                                        char caminho_obra[256];
                                        sprintf(caminho_obra, "../Temas/%s/%s", temas[tema - 1], nomeDaObra);

                                        if (remove(caminho_obra) == 0) {
                                            system("cls");
                                            printf("Obra excluída com sucesso!\n");
                                            break;
                                        } else {
                                            perror("Erro ao excluir a obra");
                                            break;
                                        }
                                    } else {
                                        system("cls");
                                        printf("Operação de exclusão cancelada.\n");
                                        break;
                                    }
                            }
                            else if (acao == 3)
                            {
                                char nomeDaObra[256];
                                strcpy(nomeDaObra, arquivos[obra - 1]);

                                char caminho_obra[100];
                                sprintf(caminho_obra, "../Temas/%s/%s", temas[tema - 1], nomeDaObra);

                                FILE *ler_obra = fopen(caminho_obra, "r");
                                if (ler_obra == NULL) {
                                    perror("Erro ao abrir o arquivo");
                                    break;
                                }

                                char conteudo_obra[9999];
                                while (fgets(conteudo_obra, sizeof(conteudo_obra), ler_obra) != NULL) {
                                    printf("%s\n", conteudo_obra);
                                }

                                fclose(ler_obra);
                                printf("\nPressione ENTER para continuar");
                                while (getchar() != '\n');
                                getchar();
                                system("cls");
                                break;
                            }
                            else if (acao == 4)
                            {
                                char nomeDaObra[256];
                                strcpy(nomeDaObra, arquivos[obra - 1]);

                                char caminho_obra[100];
                                sprintf(caminho_obra, "../Temas/%s/%s", temas[tema - 1], nomeDaObra);

                                FILE *alterar_obra = fopen(caminho_obra, "w");
                                if (alterar_obra == NULL) {
                                    perror("Erro ao abrir o arquivo");
                                    break;
                                }

                                printf("Insira a nova descrição da obra:\nR: ");
                                char novadesc[9999];
                                scanf(" %[^\n]", novadesc);

                                fprintf(alterar_obra, "%s", novadesc);

                                fclose(alterar_obra);
                                system("cls");
                                printf("Descrição alterada com sucesso!\n");
                                break;
                            }
                        } else {
                            printf("Escolha inválida. Insira novamente.\n");
                        }
                        break;
                    }
                }
            }
        }
    }
    return 0;
}
