#include <stdio.h>

// O * recebe o endereço de memória que está sendo enviado
void calcula(int* c2) {
  // Pegando o valor dentro do endereço de memória e o endereço
  printf("Calcular %d %d\n", (*c2), c2);
  // Entrando no valor da memória e pegando o valor
  (*c2)++;
  printf("Calcular %d %d\n", (*c2), c2);
}

int main() {
  int c = 10;

  printf("main %d %d\n", c, &c);

  // O & envia o endereço de memória
  calcula(&c);
  printf("main %d %d\n", c, &c);
}