#include <stdio.h>

void calcula(int c) {
  printf("Calcular %d", c);
  c++;
  printf("Calcular %d", c);
}

int main() {
  int c = 10;

  printf("%d\n", c);
  calcula(c);
  printf("%d\n", c);
}