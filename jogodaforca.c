#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

// Header Files
#include "jogodaforca.h"

char palavrasecreta[20];
char chutes[26];
int chutesdados = 0;

int enforcou()
{

    int erros = 0;

    for (int i = 0; i < chutesdados; i++)
    {

        int existe = 0;

        for (int j = 0; j < strlen(palavrasecreta); j++)
        {
            if (chutes[i] == palavrasecreta[j])
            {
                existe = 1;
                break;
            }
        }

        if (!existe)
            erros++;
    }

    return erros >= 5;
}

void abertura()
{
    printf("/****************/\n");
    printf("/ Jogo de Forca */\n");
    printf("/****************/\n\n");
}

void chuta()
{
    char chute;
    printf("Qual letra? ");
    scanf(" %c", &chute);

    chutes[chutesdados] = chute;
    chutesdados++;
}

int jachutou(char letra)
{
    int achou = 0;
    for (int j = 0; j < chutesdados; j++)
    {
        if (chutes[j] == letra)
        {
            achou = 1;
            break;
        }
    }

    return achou;
}

int ganhou()
{
    for (int i = 0; i < strlen(palavrasecreta); i++)
    {
        if (!jachutou(palavrasecreta[i]))
        {
            return 0;
        }
    }

    return 1;
}

void desenhaforca()
{

    printf("Você já deu %d chutes\n", chutesdados);

    for (int i = 0; i < strlen(palavrasecreta); i++)
    {

        if (jachutou(palavrasecreta[i]))
        {
            printf("%c ", palavrasecreta[i]);
        }
        else
        {
            printf("_ ");
        }
    }
    printf("\n");
}

void adicionaPalavra()
{
    char quer;
    printf("Voce deseja adicionar uma palavra no jogo (S/N)? ");
    scanf(" %c", &quer);

    if (quer == 'S')
    {
        char novaPalavra[20];
        printf("Qual a nova palavra que deseja digitar? ");
        scanf("%s", novaPalavra);

        FILE *f;
        f = fopen("palavrasForca.txt", "r+");

        if (quer == 0)
        {
            printf("Desculpe, banco de dados não disponível!\n\n");
            exit(1);
        }
        // Pegando a quantidade de palavras que está no arquivo mostrado na primeira linha
        int qntd;
        fscanf(f, "%d", &qntd);
        qntd++;

        // Posiciona o cursor no arquivo
        fseek(f, 0, SEEK_SET);
        fprintf(f, "%d", qntd);

        fseek(f, 0, SEEK_END);
        fprintf(f, "\n%s", novaPalavra);

        fclose(f);
    }
}

void escolhepalavra()
{
    FILE *f;

    // Abrir arquivo
    f = fopen("palavrasForca.txt", "r");
    if (f == 0)
    {
        printf("Desculpe, banco de dados não disponível!\n\n");
        exit(1);
    }

    int qntdPalavras;
    // Abrir o arquivo e ler a quantidade de palavra que está na primeira linha
    // Ler a quantidade de palavras
    // Ele sempre le sequencialmente
    fscanf(f, "%d", &qntdPalavras);

    srand(time(0));
    // A função rand() gera um número aleatório
    // A função % pega o resto da divisão
    // A função rand() % qntdPalavras gera um número aleatório entre 0 e qntdPalavras - 1
    int numRandow = rand() % qntdPalavras;

    for (int i = 0; i <= numRandow; i++)
    {
        // Ler a palavra do arquivo
        // Ele sempre le sequencialmente
        fscanf(f, "%s", palavrasecreta);
    }

    // Fechar Arquivo
    fclose(f);
}

int main()
{

    abertura();
    escolhepalavra();

    do
    {

        desenhaforca();
        chuta();

    } while (!ganhou() && !enforcou());

    adicionaPalavra();
}