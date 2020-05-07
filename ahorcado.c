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

    for (int k = 0; k < 5; k++) {
      if (*(attemps + i) == word[k]) {
        printf("\nLa letra '%c' se encuentra en la posición %d.\n", *(attemps + i), k+1);
        count++;
        if (count == 5) {
          printf("\n¡FELICIDADES! Me ganaste, la palabra es 'Kirby'.\n");
          exit(1);
        }
        break;
      }
      else if (k == 4 && *(attemps + i) != word[k]) {
        printf("\nLa letra '%c' no esta en la palabra.\n", *(attemps + i));
      }
    }

    for (int j = 0; j < i; j++) {
      if (*(attemps + i) == *(attemps + j)) {
        printf("Recuerda que ya la habias utilizado\n");
        i--;
        break;
      }
    }

  }

  printf("\nLo siento, perdiste. Ya no te quedan intentos. :c\n");

  free(attemps);

  return 0;
}
