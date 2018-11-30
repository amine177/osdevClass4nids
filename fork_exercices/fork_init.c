#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>


int main()
{
  int retour_fork;

  retour_fork = fork();

  if (retour_fork > 1) {
    printf("Je suis père de : %d et mon pid est: %d\n", retour_fork, getpid());
  } else if (retour_fork == 0) {
    printf("Je suis fils de %d mon PID est : %d\n", getppid(), getpid());
  } else {
    printf("erreur fork!\n");
  }

  if (retour_fork == 0) {
    fork();
  }


  return 0;
}
