#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int U[100000000];
int V[100000000];
int T[100000000];

void fusion(int U[], int n, int V[], int m, int T[]) {
	int i = 0;
	int j = 0;

  int k = 0;
	for(k = 0; k < n + m; k++) {
    // Si on arrive au bout des tableaux
    if(i == n && j == m)
      return;
    else if(i == n)
      T[k] = V[j++];
    else if(j == m)
      T[k] = U[i++];
    // Sinon
    else {
      if(U[i] < V[j])
        T[k] = U[i++];
      else
        T[k] = V[j++];
    }
	}
}

int get_next_number(char *input, int *offset) {
  input += *offset;

  int length = 0;
  while((*(input + length) != ' ') && (*(input + length) != '\0')) length++;

  char n[length + 1];
  n[length] = '\0';
  strncpy(n, input, length);
  *offset += length + 1;

  return atoi(n);
}

int main(int argc, char *argv[]) {
  // On lit le fichier test
  char *file = 0;
  long length;

  if(stdin) {
    fseek(stdin, 0, SEEK_END);
    length = ftell(stdin);
    fseek(stdin, 0, SEEK_SET);
    file = malloc(length);
    if(file) fread(file, 1, length, stdin);
  }

  if(file) {
    // Initialisation des tableaux
    int offset = 0;
    int n = get_next_number(file, &offset);
    int m = n;

    int i = 0;
    for(i = 0; i < n; i++) U[i] = get_next_number(file, &offset);
    for(i = 0; i < n; i++) V[i] = get_next_number(file, &offset);

    // Fusion séquentielle
    double start = omp_get_wtime();
    fusion(U, n, V, m, T);
    double end = omp_get_wtime();

    // Vérification du tableau
    for(i = 1; i < n + m; i++) {
      if(T[i - 1] > T[i]) {
        printf("Tableau trié incorrect %d\n", i);
        return EXIT_FAILURE;
      }
    }

    #ifdef TEST
      // Affichage du temps
      double elapsed_time = (end - start);
      printf("%.8f\n", elapsed_time);
    #else
      // Affichage du résultat
      for(i = 0; i < n + m; i++)
        printf("%d ", T[i]);
      printf("\n");
    #endif
  }

  free(file);

	return EXIT_SUCCESS;
}
