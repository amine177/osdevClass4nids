#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>


int main()
{
  int i;
  for (i = 0; i < 3; i++)
    fork();

  printf("A\n");
}
