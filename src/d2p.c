#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int T[100000000];
int A[100000000];

void interchanger(int *a, int *b) {
	int a_tmp = *a;
	int b_tmp = *b;
	*a = b_tmp;
	*b = a_tmp;
}

int recherche_dichotomique(int valeur_recherchee, int tab[], int ind_debut, int ind_fin) {
	if(ind_debut > ind_fin) ind_fin = ind_debut;

	while(ind_debut < ind_fin) {
		int ind_milieu = (ind_debut + ind_fin) / 2;

		if(valeur_recherchee <= tab[ind_milieu])
			ind_fin = ind_milieu;
		else
			ind_debut = ind_milieu + 1;
	}

	return ind_fin;
}

void fusion(int T[], int p1, int r1, int p2, int r2, int A[], int p3) {
	int n1 = r1 - p1 + 1;
	int n2 = r2 - p2 + 1;

	//interchanger (n1,p1,r1) et (n2,p2,r2) 
	if(n1 < n2) {
		interchanger(&n1, &n2);
		interchanger(&p1, &p2);
		interchanger(&r1, &r2);
	}

	if(n1 > 0) {
		int q1 = (p1 + r1) / 2;
		int q2 = recherche_dichotomique(T[q1], T, p2, r2);
		int q3 = p3 + (q1 - p1) + (q2 - p2);
		A[q3] = T[q1];
		#pragma omp task
		fusion(T, p1, q1 - 1, p2, q2 - 1, A, p3);
		#pragma omp task
		fusion(T, q1 + 1, r1, q2, r2, A, q3 + 1);
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

    for(int i = 0; i < 2 * n; i++) T[i] = get_next_number(file, &offset);

		// printf("T1 : ");
		// for(int i = 0; i < n; i++)
		// 	printf("%d ", T[i]);
		// printf("\n");

		// printf("T2 : ");
		// for(int i = n; i < 2 * n; i++)
		// 	printf("%d ", T[i]);
		// printf("\n");

    // Fusion parallèle
    double start = omp_get_wtime();
		#pragma omp parallel num_threads(1)
		fusion(T, 0, n - 1, n, 2 * n, A, 0);
    double end = omp_get_wtime();

		// // Affichage du résultat
		// printf("A : ");
		// for(int i = 0; i < 2 * n; i++)
		// 	printf("%d ", A[i]);
		// printf("\n");

    // Affichage du temps
    printf("%f\n", end - start);
  }

  free(file);

	return EXIT_SUCCESS;
}
