#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[]) {
  if(argc != 2) {
    printf("Wrong usage, example: ./generator 25\n");
    return EXIT_FAILURE;
  }

  int n = atoi(argv[1]);
  srand(time(NULL));

  FILE *file = fopen("fichier_test", "w");

  fprintf(file, "%d", n);

  for(int i = 0; i < 2 * n; i++) fprintf(file, " %d", rand());

  fclose(file);

  return EXIT_SUCCESS;
}