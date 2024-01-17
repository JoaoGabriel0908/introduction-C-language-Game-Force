#include <stdio.h>
#include <string.h>
int main()
{
  char palavraSecreta[20];

  sprintf(palavraSecreta, "MELANCIA");

  int acertou = 0;
  int enforcou = 0;

  char chutes[26];
  int tentativas = 0;

  // Primeiro ele roda o loop uma vez e depois verifica a condição
  do
  {

    for (int i = 0; i < strlen(palavraSecreta); i++)
    {

      int achou = 0;

      // printf("Estou vendo a letra secreta %d %c\n",i, palavraSecreta[i]);

      for (int j = 0; j < tentativas; j++)
      {
        // printf("-> Chute %d %c\n",j, chutes[j]);
        if (chutes[j] == palavraSecreta[i])
        {
          // printf("---> Chute Correto\n");
          achou = 1;
          break;
        }
      }

      if (achou)
      {
        printf("%c ", palavraSecreta[i]);
      }
      else
      {
        printf("_ ");
      }
    };

    printf("\n");

    char chute;
    scanf(" %c", &chute);

    chutes[tentativas] = chute;
    tentativas++;

    // strlen = Conta o número de letras na palavra
    // for(int i = 0; i < strlen(palavraSecreta); i++){
    //   printf("Estou vendo a letra %c na posicao %d\n", palavraSecreta[i], i);
    //   if(palavraSecreta[i] == chute){
    //     printf("A posicao %d tem essa letra\n", i);
    //   }
    // }

  } while (!acertou && !enforcou);
}