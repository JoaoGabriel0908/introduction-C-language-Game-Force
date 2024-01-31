#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

// Header Files
#include "jogodaforca.h"

char palavrasecreta[TAMANHO_PALAVRA];
char chutes[26];
int chutesdados = 0;

int chutesErrados()
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
    return erros;
}

int enforcou()
{
    return chutesErrados() >= 5;
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
    int erros = chutesErrados();

    printf("  _______      \n");
    printf(" |/      |     \n");

    printf(" |      %c%c%c    \n", (erros >= 1 ? '(' : ' '), (erros >= 1 ? '_' : ' '), (erros >= 1 ? ')' : ' '));

    printf(" |      %c%c%c   \n", (erros >= 3 ? '\\' : ' '), (erros >= 2 ? '|' : ' '), (erros >= 3 ? '/' : ' '));
    printf(" |       %c     \n", (erros >= 2 ? '|' : ' '));
    printf(" |       %c     \n", (erros >= 2 ? '|' : ' '));
    printf(" |      %c %c   \n", (erros >= 4 ? '/' : ' '), (erros >= 4 ? '\\' : ' '));
    printf(" |             \n");
    printf("_|___          \n");
    printf("\n\n");

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
        char novaPalavra[TAMANHO_PALAVRA];
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

    if (ganhou())
    {
        printf("Você Ganhou! Parabéns! ");
        printf("       ___________      \n");
        printf("      '._==_==_=_.'     \n");
        printf("      .-\\:      /-.    \n");
        printf("     | (|:.     |) |    \n");
        printf("      '-|:.     |-'     \n");
        printf("        \\::.    /      \n");
        printf("         '::. .'        \n");
        printf("           ) (          \n");
        printf("         _.' '._        \n");
        printf("        '-------'       \n\n");
    }
    else
    {
        printf("Você Perdeu, mas valeu o esforço!\n");
        printf("Palavra secreta era **%s**", palavrasecreta);

                printf("    _______________         \n");
        printf("   /               \\       \n"); 
        printf("  /                 \\      \n");
        printf("//                   \\/\\  \n");
        printf("\\|   XXXX     XXXX   | /   \n");
        printf(" |   XXXX     XXXX   |/     \n");
        printf(" |   XXX       XXX   |      \n");
        printf(" |                   |      \n");
        printf(" \\__      XXX      __/     \n");
        printf("   |\\     XXX     /|       \n");
        printf("   | |           | |        \n");
        printf("   | I I I I I I I |        \n");
        printf("   |  I I I I I I  |        \n");
        printf("   \\_             _/       \n");
        printf("     \\_         _/         \n");
        printf("       \\_______/           \n");
    }

    adicionaPalavra();
}