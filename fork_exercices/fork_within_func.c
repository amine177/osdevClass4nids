#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>


void doit();


int main()
{
  doit();
  printf("plop!\n");
  wait(NULL);
  wait(NULL);
  wait(NULL);
  return 0;
}


void doit()
{
  printf("am in doit!\n");
  fork();
  printf("i passed throug level1\n");
  fork();
  printf("i passed through level2\n");
  fork();
  printf("i passed through level3\n");
}
