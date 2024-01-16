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
    scanf("%c", chute);

    // strlen = Conta o número de letras na palavra
    for(int i = 0; i < strlen(palavraSecreta); i++){
      if(palavraSecreta[i] == chute){
        printf("A posição %d tem essa letra\n", i);
      }
    }

  } while (!acertou && !enforcou);
  

}