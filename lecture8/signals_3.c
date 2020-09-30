// adapted from https://stackoverflow.com/a/54267342/12887845

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MESSAGE "you can't stop me!\n"
#define MSGLEN 19

static void sig_handler(int this_signal) {
  if (this_signal == SIGINT) write(STDOUT_FILENO, MESSAGE, MSGLEN);
}

int main(void) {
  unsigned long counter = 0;

  signal(SIGINT, sig_handler);
  while (1) {
    printf("look I can count to %ld\n", counter);
    counter++;
    usleep(250000);  // 250 ms
  }

  return EXIT_SUCCESS;
}
