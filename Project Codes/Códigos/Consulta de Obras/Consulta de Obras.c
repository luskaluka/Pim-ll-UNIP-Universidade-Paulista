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
    int tema, obra;
    char temas[][50] = {"100 Anos da Semana de Arte Moderna", "150 Anos de Santos Dumont", "A Evolução dos Vídeo-Games", "Jogos Olímpicos de Paris 2024"};
    char arquivos[5][256];

    while (1) {
        for (int i = 1; i <= 4; i++) {
            printf("%d: %s\n", i, temas[i - 1]);
        }
        printf("5: Sair\nR: ");
        scanf("%d", &tema);
        getchar();
        system("cls");

        if (tema == 5) {
            break;
        }

        if (tema >= 1 && tema <= 4) {
            char caminho[100];
            sprintf(caminho, "../Temas/%s", temas[tema - 1]);

            int quantidadeObras = listarArquivos(caminho, arquivos);
            system("cls");

            if (quantidadeObras > 0) {
                while (1) {
                    listarArquivos(caminho, arquivos);
                    printf("Escolha uma obra (1-%d): ", quantidadeObras);
                    scanf("%d", &obra);
                    getchar();
                    system("cls");

                    if (obra > 0 && obra <= quantidadeObras) {
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
                            printf("%s", conteudo_obra);
                        }

                        fclose(ler_obra);
                        printf("\nPressione ENTER para continuar");
                        while (getchar() != '\n');
                        system("cls");
                        break;
                    } else {
                        printf("Escolha inválida. Tente novamente.\n");
                    }
                }
            } else {
                printf("Nenhuma obra disponível para este tema.\n");
            }
        } else {
            printf("Escolha inválida. Tente novamente.\n");
        }
    }

    return 0;
}
