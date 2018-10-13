#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <sys/types.h>


int main()
{
  int n;
  if ((n = fork()) > 0) {
    wait(NULL);
  } else if (n == 0) {
    printf("Executing in the child:\n");
    execlp("/usr/bin/ls", "", "-l", "/home", NULL);
    printf("Done in child\n");
  } else {
  }
}
