#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
  char *attemps;
  attemps = (char*) malloc(10 * sizeof(char));
  if (attemps == NULL) {
    printf("No se pudo reservar el espacio de memoria");
    exit(1);
  }

  char word[5] = "kirby";

  printf("\nJUGUEMOS AHORCADO.\n");
  int count = 0;

  for (int i = 0; i < 10; i++) {
    if ( 10-i > 1) {
      printf("\nPrueba con una letra (tienes %d intentos): ", 10 - i);
      scanf("%s", &attemps[i]);
    }
    else {
      printf("\nPrueba con una letra (tienes %d intento): ", 10 - i);
      scanf("%s", &attemps[i]);
    }

    for (int j = 0; j < i; j++) {
      if (*(attemps + i) == *(attemps + j)) {
        printf("\nYa utilizaste la letra '%c'\n", *(attemps + i));
        i--;
        break;
      }
    }

    for (int k = 0; k < 5; k++) {
      if (*(attemps + i) == word[k]) {
        printf("\nLa letra %c se encuentra en la posición %d\n", *(attemps + i), k+1);
        count++;
        if (count == 5) {
          printf("\n¡FELICIDADES! Me ganaste, la palabra es 'Kirby'.\n");
          exit(1);
        }
      }
    }
  }

  printf("\nLo siento, perdiste. Ya no te quedan intentos. :c\n");
  //
  // for (int i = 0; i < 10; i++) {
  //   printf("%c", *(attemps + i));
  // }

  free(attemps);

  return 0;
}
