#include <spawn.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
  char *args[4] = {"/bin/echo", "hello","world", 0};
  int child_status, result;
  result = fork();
  if (result < 0) {
    perror("fork failed");
    exit(1);
  }
  if (result == 0) {
    execv(args[0], args);
    // if we get to this line we know something went wrong...
    perror("execv failed");
    exit(1);
  }
  else{
    wait(&child_status);
  }
}