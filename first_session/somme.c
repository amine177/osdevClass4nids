#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  int s;

  if (argc < 2) {
    printf("Usage: ./somme.c [...]");
    exit(1);
  }

  s = 0;
  while (--argc)
    s += atoi(*++argv);

  printf("s = %d\n", s);

  return 0;
}
