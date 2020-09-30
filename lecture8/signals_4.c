// adapted from https://stackoverflow.com/a/54267342/12887845

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MESSAGE "on second thought...\n"
#define MSGLEN 21

static volatile sig_atomic_t keep_running = 1;


static void sig_handler(int this_signal) {
  if (this_signal == SIGINT){
    write(STDOUT_FILENO, MESSAGE, MSGLEN);
    keep_running = 0;
  }
}

int main(void) {
  unsigned long counter = 0;
  int sleep_result;
  signal(SIGINT, sig_handler);
  while (keep_running) {
    printf("look I can count to %ld\n", counter);
    counter++;
    sleep_result = usleep(250000);  // 250 ms
    if(sleep_result != 0 ){
      perror("usleep failed:");
    }
  }

  return EXIT_SUCCESS;
}
