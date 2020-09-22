#include <spawn.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

// external symbol that always points to the list of enviornment variables
extern char **environ;

int main(int argc, char **argv) {
  char *args[4] = {"/bin/echo", "hello","world", 0};
  int child_status;
  int result;

  if (0 != posix_spawn(&result, args[0], NULL, NULL, args, environ)) {
    perror("spawn failed");
    exit(1);
  }
  wait(&child_status);
}