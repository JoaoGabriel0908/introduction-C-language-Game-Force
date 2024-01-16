#include <stdio.h>
#include <string.h>
int main()
{
  char palavraSecreta[20];

  sprintf(palavraSecreta, "MELANCIA");

  int acertou = 0;
  int enforcou = 1;

  // Primeiro ele roda o loop uma vez e depois verifica a condição
  do
  {
    char chute;
    scanf("%c", &chute);

    // strlen = Conta o número de letras na palavra
    for(int i = 0; i < strlen(palavraSecreta); i++){
      printf("Estou vendo a letra %c na posicao %d\n", palavraSecreta[i], i);
      if(palavraSecreta[i] == chute){
        printf("A posicao %d tem essa letra\n", i);
      }
    }

  } while (!acertou && !enforcou);
  

}