#include <unistd.h>
#include <stdio.h>


int main()
{
  char *args[] = {"ls", "/home/aminos", NULL};
  char *arg0 = "ls";
  char *arg1 = NULL;

  execvp("ls", args);
  printf("####################");
  execlp("ls", args[1], arg1);

  return 0;
}
