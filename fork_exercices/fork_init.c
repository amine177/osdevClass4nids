#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>


int main()
{
  int i;
  pid_t cpid;

  i = 0;
  if((cpid = fork()) > 0) {
    printf("%x\n", &i);
    printf("I am in the parent my PID is :%d, my child have PID: %d\n", getpid(), cpid);
    i += 1;
    sleep(20);
  }
  else {
    sleep(10);
    printf("I am a child of: %d\n", getppid());
    printf("i: %d\n", i);
  }

  return 0;
}
