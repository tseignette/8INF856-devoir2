#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int U[100000000];
int V[100000000];

int recherche_dichotomique(int valeur_recherchee, int tab[], int ind_debut, int ind_fin) {
	int ind_milieu;
	while (ind_debut <= ind_fin) {
		ind_milieu = (ind_fin + ind_debut) / 2;
		if (tab[ind_milieu] == valeur_recherchee)
			return ind_milieu;
		else if (valeur_recherchee > tab[ind_milieu])
			ind_debut = ind_milieu + 1;
		else
			ind_fin = ind_milieu - 1;
	}
	return -1;
}

void fusion(int T[], int p1, int r1, int A[], int p2, int r2, int p3) {
	int n1 = r1 - p1 + 1;
	int n2 = r2 - p2 + 1;

	//interchanger (n1,p1,r1) et (n2,p2,r2) 
	if (n1 < n2) {
		int temp = n1;
		n1 = n2;
		n2 = temp;
		temp = p1;
		p1 = p2;
		p2 = temp;
		temp = r1;
		r1 = r2;
		r2 = temp;
	}

	if (n1 > 0) {
		int q1 = (p1 + r1) / 2;
		int q2 = recherche_dichotomique(T[q1], T, p2, r2);
		if (q2 == -1) return; // Erreur
		int q3 = p3 + (q1 - p1) + (q2 - p2);
		A[q3] = T[q1];
		fusion(T, p1, q1 - 1, A, p2, q2 - 1, p3);
		fusion(T, q1 + 1, r1, A, q2, r2, q3 + 1);
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

int main() {
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

    for(int i = 0; i < n; i++) U[i] = get_next_number(file, &offset);
    for(int i = 0; i < n; i++) V[i] = get_next_number(file, &offset);

		printf("U : ");
		for(int i = 0; i < n; i++)
			printf("%d ", U[i]);
		printf("\n");

		printf("V : ");
		for(int i = 0; i < m; i++)
			printf("%d ", V[i]);
		printf("\n");

    // Fusion séquentielle
    double start = omp_get_wtime();
		fusion(U, 0, 1, V, 0, 1, 0);
    double end = omp_get_wtime();

		// Affichage du résultat
		printf("V : ");
		for(int i = 0; i < n + m; i++)
			printf("%d ", V[i]);
		printf("\n");

    // Affichage du temps
    printf("%f\n", end - start);
  }

  free(file);

	return EXIT_SUCCESS;
}
