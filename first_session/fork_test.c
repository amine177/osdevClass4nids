#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>


int main(void)
{
  pid_t n;

  n = fork();
  if (!n)
    printf("I am child of %d\n", getppid());
  else if (n == -1) {
    printf("Child creation failed!\n");
    return -1;
  }
  else
    printf("I am the father process!\n");

  printf("My PID: %d\n", getpid());

  return 0;
}
