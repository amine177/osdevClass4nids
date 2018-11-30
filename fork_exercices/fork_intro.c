#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>

int main()
{
  pid_t n;
  int child_status;

  n = fork();

  if (n > 1) {
    printf("I am the father, my child PID is: %d\n", n);
    wait(&child_status);
    errno = child_status;
    perror("parent");
  }
  else if (!n) {
    printf("I am child and my pid is: %d and my parent's id is: %d\n", getpid(), getppid());
    sleep(15);
    exit(1);
  }
  else
    printf("err\n");

  printf("PID: %d, dying!\n", getpid());
  return 0;
}
