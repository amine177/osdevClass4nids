#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <sys/types.h>



int main(int argc, char *argv[])
{
  int n;
  if ((n = fork()) > 0) {
    wait(NULL);
  } else if (!n) {
    execvp(argv[1], &argv[1]);
  } else {
  }
}
