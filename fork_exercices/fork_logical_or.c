#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>


int main()
{
  if (fork() || fork())
    fork();
  printf("plop!\n");
  return 0;
}
