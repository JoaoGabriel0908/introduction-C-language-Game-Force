#include <stdio.h>
#include <string.h>

int soma(int* num,int tam){

  int total = 0;

  for(int i = 0; i < tam; i++){
    total = total + num[i];
  }

  return total;

}

int main() {
  int num[3];

  num[0] = 10;
  num[1] = 20;
  num[2] = 30;

  int total = soma(num, 3);

  printf("%d", total);
}