#include <stdio.h>
#include <omp.h>
#include <math.h>

int rechercheDichotomique(int valeurRecherchee, int tab[], int indDebut, int indFin) {
	int indMilieu;
	while (indDebut <= indFin) {
		indMilieu = (indFin + indDebut) / 2;
		if (tab[indMilieu] == valeurRecherchee)
			return indMilieu;
		else if (valeurRecherchee > tab[indMilieu])
			indDebut = indMilieu + 1;
		else
			indFin = indMilieu - 1;
	}
	return -1;
}

void parallele_fusion(int T[], int p1, int r1, int A[], int p2, int r2, int p3) {
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
		int q2 = rechercheDichotomique(T[q1], T, p2, r2);
		if (q2 == -1) return; // Erreur
		int q3 = p3 + (q1 - p1) + (q2 - p2);
		A[q3] = T[q1];
		parallele_fusion(T, p1, q1 - 1, A, p2, q2 - 1, p3);
		parallele_fusion(T, q1 + 1, r1, A, q2, r2, q3 + 1);
	}
}

int main() {
	printf("Hello world !\n");
	int T[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 };
	int A[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 };
	//V�rification que rechercheDichotomique fonctionne correctement
	int a;
	int length = sizeof T / (sizeof(int));
	printf("Taille = %d\n", length);
	for (int i = 0; i < length; i++)
	{
		a = rechercheDichotomique(i, T, 0, length);
		printf("%d\n", a);
	}


	parallele_fusion(T, 0, 1, A, 0, 1, 0);

	length = 2 * sizeof A / (sizeof(int));
	for (int i = 0; i < length; i++)
	{
		printf("%d\n", A[i]);
	}

	return 0;
}
