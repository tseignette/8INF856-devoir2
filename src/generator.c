#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[]) {
  if(argc != 2) {
    printf("Wrong usage: ./bin/generator [array_size]\n");
    return EXIT_FAILURE;
  }

  int n = atoi(argv[1]);
  srand(time(NULL));

  FILE *file = fopen("./test/fichier_test", "w");

  fprintf(file, "%d", n);

  // Premier tableau
  int num = rand() % (10000 + 1);
  for(int i = 0; i < n; i++) {
    num += rand() % (1000 + 1);
    fprintf(file, " %d", num);
  }

  // Deuxième tableau
  num = rand() % (10000 + 1);
  for(int i = 0; i < n; i++) {
    num += rand() % (1000 + 1);
    fprintf(file, " %d", num);
  }

  fclose(file);

  return EXIT_SUCCESS;
}