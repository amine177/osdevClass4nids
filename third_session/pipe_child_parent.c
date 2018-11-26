#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char *argv[])
{
  int pipefd[2];
  pid_t cpid;
  char buf, f='f';

  if (argc != 2) {
    fprintf(stderr, "Usage: %s string\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  if(pipe(pipefd) == -1) {
    perror("pipe");
    exit(EXIT_FAILURE);
  }

  cpid = fork();
  if (cpid == -1) {
    perror("Couldn't fork!");
    exit(EXIT_FAILURE);
  }

  if (cpid == 0) {
    close(pipefd[0]);
    write(pipefd[1], argv[1], strlen(argv[1]));
    close(pipefd[1]);
    _exit(EXIT_SUCCESS);
  } else {
    close(pipefd[1]);
    printf("My son said:\n");
    while(read(pipefd[0],&buf, 1) > 0)
      write(STDOUT_FILENO, &buf, 1);
    close(pipefd[0]);
    wait(NULL);
  }

  return 0;
}
