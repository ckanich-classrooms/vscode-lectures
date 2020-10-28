#include <stdio.h>
#include <strings.h>
#include <unistd.h>

int main() {
  int num_returned;
  char* retval;
  char buf[16];
  bzero(buf, 16);
  fputs("send me some bytes!\n", stdout);
  while(1) {
      usleep(250000);
    num_returned = read(STDIN_FILENO, buf, sizeof(buf)-1);
    // fgets(buf, 1024,stdin);
    fprintf(stdout,
            "I asekd for %ld bytes, you gave me %d bytes, you said:\n%s\n",
            sizeof(buf), num_returned, buf);
  } 

  return 0;
}

//  ssize_t read(char * filename, void *buf, size_t count, size_t offset);