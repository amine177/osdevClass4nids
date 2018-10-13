#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

//testing the wait(), fork() and sleep() systems calls
int main()
{
  int n;
  int status;
  pid_t cpid;
  if ((n = fork()) > 0)  {
    cpid = wait(&status);
    printf("Child exited with status: %d\n", status);
  } else if(n < 0) {
    printf("Error on fork");
  } else {
    printf("I am the child of %d\n", getppid());
    sleep(15);
    exit(0);
  }
}
