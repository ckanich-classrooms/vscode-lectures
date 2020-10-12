#include <fcntl.h>
#include <spawn.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <unistd.h>

extern char** environ;
int main(void) {
  int fd, result, child_status;
  char *args[2] = {"ls", 0};
  posix_spawn_file_actions_t actions;
  char* const param[] = {"/bin/ls", NULL};

  posix_spawn_file_actions_init(&actions);
  posix_spawn_file_actions_addopen(&actions, STDOUT_FILENO, "outfile",
                                   O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR);

  if (0 != posix_spawnp(&result, args[0], &actions, NULL, args, environ)) {
    perror("spawn failed");
    exit(1);
  }
  wait(&child_status);
}