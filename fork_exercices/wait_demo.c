#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>



int main()
{
  int p, p2;
  pid_t fils;
  pid_t fils2;
  int n;
  if ((n=fork())>0)
        fils2 = wait(&p2);
  else {
    sleep(3);
    printf("I am fils 1, mon pid is: %d\n", getpid());
    exit(2);
  }
  if (n > 0) {
    printf("mon fils %d, exited aved code: %d\n", fils3, p2);
  }
