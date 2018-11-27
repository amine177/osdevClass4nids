#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
int i;
for (i = 0; i < 3; i++)
fork();
printf("plop!\n");
exit(0);
}
