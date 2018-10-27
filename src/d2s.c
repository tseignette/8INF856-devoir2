#include <stdio.h>
#include <math.h>

void fusion(int U[], int n, int V[], int m, int T[]){
	int i = 0;
	int j = 0;
	U[n] = V[m] = pow(2, (8 * sizeof(int))-2);
	printf("%d", U[n]);
	for (int k = 0; i < n + m; k++){
		if (U[i] < V[j])
			T[k] = U[i++];
		else
			T[k] = V[j++];
	}
}

int main() {
	printf("Hello world !\n");
	int T[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 };
	int A[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 };

	//Vérification de la fonction fusion séquentielle
	int resultat[(sizeof T + sizeof A) / sizeof(int)];
	fusion(T, sizeof T / sizeof(int), A, sizeof A / sizeof(int), resultat);
	int length = sizeof resultat / (sizeof(int));
	printf("Taille = %d\n", length);
	for (int i = 0; i < length; i++)
	{
		printf("%d\n", resultat[i]);
	}

	// while (1);
	return 0;
}
