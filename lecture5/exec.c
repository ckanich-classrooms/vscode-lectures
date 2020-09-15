#include <unistd.h>
#include <stdio.h>

int main()
{
  char * args[] = {"/bin/ls", NULL};

  printf("pid: %d\n", getpid());

  //sleep(60);
  execv("/bin/ls", args);
}