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
  char* args[2] = {"ls", 0};
  posix_spawn_file_actions_t actions, actions_2;
  char* const param[] = {"/bin/ls", NULL};
  char* const second[] = {"wc", NULL};
  int pipefds[2];
  int pid_1, pid_2;

  posix_spawn_file_actions_init(&actions);
  posix_spawn_file_actions_init(&actions_2);

  pipe(pipefds);
  posix_spawn_file_actions_adddup2(&actions, pipefds[1], STDOUT_FILENO);
  posix_spawn_file_actions_addclose(&actions, pipefds[0]);
  posix_spawn_file_actions_adddup2(&actions_2, pipefds[0], STDIN_FILENO);
  posix_spawn_file_actions_addclose(&actions_2, pipefds[1]);

  if (0 != posix_spawnp(&pid_1, param[0], &actions, NULL, param, environ)) {
    perror("spawn failed");
    exit(1);
  }
  if (0 != posix_spawnp(&pid_2, second[0], &actions_2, NULL, second, environ)) {
    perror("spawn failed");
    exit(1);
  }
  close(pipefds[0]);
  close(pipefds[1]);
  waitpid(pid_1, &child_status, 0);
  waitpid(pid_2, &child_status, 0);
}