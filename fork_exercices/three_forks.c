#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>


int main()
{
  int a[100];
  int i = 1;
  int status;

  fork();
  fork();
  fork();
  wait(&status);
  i++;


  printf("i: %d\n",i );

  return 0;
}
