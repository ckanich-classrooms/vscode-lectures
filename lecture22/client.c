#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>


#define BUFFER_SIZE 1024
#define on_error(...) { fprintf(stderr, __VA_ARGS__); fflush(stderr); exit(1); }

int main (int argc, char *argv[]) {
  if (argc < 2) on_error("Usage: %s [port]\n", argv[0]);

  int client_fd, err;
  struct sockaddr_in server, client;
  struct addrinfo hints, * result;

  char buf[BUFFER_SIZE];

  client_fd = socket(AF_INET, SOCK_STREAM, 0);
  if (client_fd < 0) on_error("Could not create socket\n");

  memset(&hints, 0, sizeof (struct addrinfo));
  hints.ai_family = AF_INET; /* IPv4 only */
  hints.ai_socktype = SOCK_STREAM; /* TCP */
  
  err = getaddrinfo("localhost",argv[1],&hints, &result);

  if (err) on_error("getaddrinfo failed\n");
      if (connect(client_fd, result->ai_addr, result->ai_addrlen) == -1) {
        perror("connect");
        exit(2);
    }

    char *buffer = "GET / HTTP/1.0\r\n\r\n";
    printf("SENDING: %s", buffer);
    printf("===\n");

    // For this trivial demo just assume write() sends all bytes in one go and is not interrupted

    write(client_fd, buffer, strlen(buffer));

    char resp[1000];
    int len = read(client_fd, resp, 999);
    resp[len] = '\0';
    printf("%s\n", resp);

    return 0;
}