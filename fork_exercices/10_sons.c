#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>


int main()
{
  int i, j;
  for  (i = 0; i < 10; i++)
    if (!fork()) {
      for (j = 0; j < 10; j++)
        printf("son: %d\n", j);
      break;
    }

  for (i = 0; i < 10; i++)
    wait(NULL);
  return 0;
}
