#include <pthread.h>
#include <stdio.h>
#include <unistd.h>


void afficher(int a)
{
  printf("int is: %d\n", a);
}

int main()
{
  pthread_t th1;
  pthread_t th2;

  if(pthread_create(&th1, NULL, (void *)afficher, (void *)5) < 0)
    printf("err\n");
  if(pthread_create(&th2, NULL, (void *)afficher, (void *)5) < 0)
    printf("err\n");

  pthread_join(th1, NULL);
  pthread_join(th2, NULL);
  return 0;
}
