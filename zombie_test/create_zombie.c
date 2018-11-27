#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>


int main()
{
  int n ;
  if ((n = fork()) > 0) {
    printf("A parent will sleep without waiting for %d\n", n);
    sleep(100);
  } else {
    exit(0);
  }

  wait(NULL);
  return 0;
}
