#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

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

	// Vérification que la recherche dichotomique fonctionne correctement
  // On teste la recherche sur une valeau qui n'existe pas puis sur
  // toutes les autres valeurs par ordre décroissant
	int a;
  printf("Résultats recherche dich. : ");
	for (int i = n; i >= 0; i--)
	{
		a = recherche_dichotomique(i, U, 0, n);
		printf("%d ", a);
	}
  printf("\n");

  // Fusion parallèle
	int T[n + m];
  // TODO: V doit avoir une taille plus grande
	fusion(U, 0, 1, V, 0, 1, 0);

	int length = 2 * sizeof V / (sizeof(int));
	for (int i = 0; i < length; i++)
	{
		printf("%d ", V[i]);
	}
  printf("\n");

  // Affichage du résultat
  printf("T : ");
	for(int i = 0; i < n + m; i++)
		printf("%d ", T[i]);
  printf("\n");

	return EXIT_SUCCESS;
}
