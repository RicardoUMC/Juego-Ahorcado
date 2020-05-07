#include <stdio.h>
#include <stdlib.h>

int main(void) {
  char *attemps;
  attemps = (char*) malloc(10 * sizeof(char));
  if (attemps == NULL) {
    printf("No se pudo reservar el espacio de memoria");
    exit(1);
  }

  char word[5] = "kirby";

  printf("Juguemos ahorcado.\n");

  for (int i = 0; i < 10; i++) {
    if ( 10-i > 1) {
      printf("Prueba con una letra (tienes %d intentos): ", 10 - i);
      scanf("%s", attemps + i);
    }
    else {
      printf("Prueba con una letra (tienes %d intento): ", 10 - i);
      scanf("%s", attemps + i);
    }
  }

  free(attemps);

  return 0;
}
