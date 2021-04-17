#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int counter = 2;

void myHandler(int sig)
{
  counter++;
  printf("%d ", counter);
  fflush(stdout);
  exit(0);
}

int main()
{
  int pid;
  signal(SIGUSR1, myHandler);
  printf("%d ", counter);
  fflush(stdout);
  if ((pid = fork()) == 0) {
    while (1) {
    };
  }
  kill(pid, SIGUSR1);
  waitpid(pid, NULL, 0);
  counter--;
  printf("%d ", counter);
  fflush(stdout);
  return 0;
}