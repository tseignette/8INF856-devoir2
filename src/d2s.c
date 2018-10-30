#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void fusion(int U[], int n, int V[], int m, int T[]){
	int i = 0;
	int j = 0;

	for(int k = 0; k < n + m; k++) {
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
    int U[n];
    int V[n];

    for(int i = 0; i < n; i++) U[i] = get_next_number(file, &offset);
    for(int i = 0; i < n; i++) V[i] = get_next_number(file, &offset);

    printf("\nU : ");
    for(int i = 0; i < n; i++)
      printf("%d ", U[i]);
    printf("\n");

    printf("\nV : ");
    for(int i = 0; i < m; i++)
      printf("%d ", V[i]);
    printf("\n");

    // Fusion séquentielle
    int T[n + m];
    fusion(U, n, V, m, T);

    // Affichage du résultat
    printf("\nT : ");
    for(int i = 0; i < n + m; i++)
      printf("%d ", T[i]);
    printf("\n");
  }

	return EXIT_SUCCESS;
}
