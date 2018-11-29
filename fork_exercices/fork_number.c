#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>


int main()
{
  fork();
  fork();
  fork();

  printf("A\n");

  return 0;
}

