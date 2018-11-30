#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>


int main()
{
  int i;
  for (i = 0; i < 4; i++) {
    if (fork()>0)
      fork();
  }

  printf("A\n");
}
