#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>
#include <errno.h>

int main() {
  char *args[4] = {"/bin/echo", "hello","world", 0};
  execv(args[0], args);
  // if we get to this line we know something went wrong...
  perror("execv failed");
  exit(1);
}