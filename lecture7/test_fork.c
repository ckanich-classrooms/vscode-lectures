#include <spawn.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

// external symbol that always points to the list of enviornment variables
extern char **environ;

int main(int argc, char **argv) {
  char *args[2] = {"/bin/true", 0};
  int child_status;
  int result;
  int iterations = atoi(argv[1]);

  for (int i = 0; i < iterations; i++) {
    malloc(4096);
  }
  for (int j = 0; j < 100; j++) {
    result = fork();
    if(result < 0){
        perror("fork failed");
        exit(1);
    }
    if(result == 0){
        execv(args[0],args);
        // if we get to this line we know something went wrong...
        perror("execv failed");
        exit(1);
    }
    wait(&child_status);
  }
}