#include <pthread.h>
#include <stdio.h>
#include <unistd.h>


pthread_mutex_t v;
void incr(int* a)
{
  for(int i = 0; i < 5000; i++) {
    //printf("a: %d\n", *a);
    pthread_mutex_lock(&v);
    *a = *a+1;
    pthread_mutex_unlock(&v);
  }
}

void decr(int* a)
{
  for(int i = 0; i < 5000; i++) {
    //printf("a: %d\n", *a);
    pthread_mutex_lock(&v);
    *a = *a-1;
    pthread_mutex_unlock(&v);
  }
}
int main()
{
  pthread_t th1;
  pthread_t th2;
  int *a;
  pthread_mutex_init(&v, NULL);
  *a = 0;

  if (pthread_create(&th1, NULL, (void *)incr, (void *)a) < 0)
    printf("err\n");
  if (pthread_create(&th2, NULL, (void *)decr, (void *)a) < 0)
    printf("err\n");

  pthread_join(th1, NULL);
  pthread_join(th2, NULL);

  printf("a: %d\n", *a);

  return 0;
}
