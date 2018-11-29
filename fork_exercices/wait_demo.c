#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>



int main()
{
  if (fork()>0)
    if (fork()>0) {
      wait(NULL);
      wait(NULL);
    }
}
