// adapted from https://stackoverflow.com/a/54267342/12887845

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void) {
  unsigned long counter = 0;
  
  signal(SIGINT, SIG_IGN);
  while (1) {
    printf("look I can count to %ld\n", counter);
    counter++;
    usleep(250000);  // 250 ms
  }

  return EXIT_SUCCESS;
}
