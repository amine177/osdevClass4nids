#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <errno.h>


int main()
{
  int *p = malloc(sizeof(int));
  switch (fork()) {
    case 0:
      sleep(5);
      exit(2);
      break;
    case -1:
      perror("main/fork");
      break;
    default:
      wait(p);
      errno = 2;
      printf("My child exited with: %x\n", *p);
      perror("child");
      sleep(20);
      break;
  }
  return 0;
}
