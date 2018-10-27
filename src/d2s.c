#include <stdio.h>
#include <stdlib.h>

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

int main() {
  // Initialisation des tableaux
  int n = 13;
	int U[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 };
  int m = 13;
	int V[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 };

  printf("U : ");
  for(int i = 0; i < n; i++)
    printf("%d ", U[i]);
  printf("\n");

  printf("V : ");
  for(int i = 0; i < m; i++)
    printf("%d ", V[i]);
  printf("\n");

  // Fusion séquentielle
	int T[n + m];
	fusion(U, n, V, m, T);

  // Affichage du résultat
  printf("T : ");
	for(int i = 0; i < n + m; i++)
		printf("%d ", T[i]);
  printf("\n");

	return EXIT_SUCCESS;
}
