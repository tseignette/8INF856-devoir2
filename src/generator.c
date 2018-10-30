#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  if(argc != 2) {
    printf("Wrong usage, example: ./generator 25\n");
    return EXIT_FAILURE;
  }

  printf("That's it!\n");

  return EXIT_SUCCESS;
}