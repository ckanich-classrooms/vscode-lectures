#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sched.h>
#include <sys/types.h>
#include <sys/wait.h>


int counter = 0;

void myHandler2(int sig) {
  counter++;
  printf("%d ", counter);
  fflush(stdout);
  if (counter == 2) exit(0);
}

int main() {
  int pid;
  signal(SIGUSR1, myHandler2);
  printf("%d ", counter);
  fflush(stdout);
  if ((pid = fork()) == 0) {
    while (1) {
    };
  }
  kill(pid, SIGUSR1);
  sched_yield();
  kill(pid, SIGUSR1);
  waitpid(pid, NULL, 0);
  return 0;
}