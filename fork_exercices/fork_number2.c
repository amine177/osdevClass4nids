#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>


int main()

{
  if (fork() || fork())
    fork();

  printf("A\n");

  return 0;
}
