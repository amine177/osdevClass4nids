#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

#define NBMAX 5000

typedef struct {
  int tab[NBMAX];
  int index;
} MEM_TAB;


int main()
{
  int shmid;
  int w_1, w_2;
  key_t key;
  MEM_TAB *ptr;

  if ((shmid = shmget(IPC_PRIVATE, sizeof(MEM_TAB), IPC_CREAT|0666)) < 0) {
    perror("shmget, main");
    exit(1);
  }

  if ((ptr = (MEM_TAB *) shmat(shmid, NULL, 0)) == NULL) {
    perror("shmat, main");
    exit(1);
  }


  switch (fork()) {
    case 0:
          printf("getting in firat child [%d]\n", ptr->index);
          while (ptr->index < 5000)
            ptr->tab[ptr->index++] = 2;
          break;
    case -1:
      perror("main, first fork");
      break;
     default:
      switch (fork()) {
        case 0:
          printf("getting in second child [%d]\n", ptr->index);
          while (ptr->index < 5000)
            ptr->tab[ptr->index++] = 1;
          break;
        case -1:
          perror("main, second fork");
          break;
        default:
          printf("waiting\n");
          wait(NULL);
          wait(NULL);
          printf("done\n");
          w_1 = w_2 = 0;
          for (int i = 0; i < 5000; i++) {
            if (ptr->tab[i] == 1)
              w_1++;
            else
              w_2++;
          }
          if (w_1 > w_2)
            printf("Child 1 won!\n");
          else if (w_1 < w_2)
            printf("Child 2 won!\n");
          else
            printf("Tie!\n");
          break;
      }
      break;
  }


  return 0;

}
