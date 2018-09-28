#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  int s;

  if (argc != 3) {
    printf("Usage: ./somme.c a b");
    exit(1);
  }

  s = atoi(*++argv) + atoi(*++argv);

  printf("s = %d\n", s);

  return 0;
}
