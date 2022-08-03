// SOURCE: https://gist.github.com/jirihnidek/bf7a2363e480491da72301b228b35d5d

// gcc getaddrinfo.c  && ./a.out

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>

int lookup_host(const char *host)
{
  struct addrinfo hints;
  struct addrinfo *result;
  int errcode;
  char addrstr[16];
  void *ptr;

  memset(&hints, 0, sizeof(hints));
  hints.ai_family = AF_INET;
  hints.ai_flags |= AI_CANONNAME;

  errcode = getaddrinfo(host, NULL, &hints, &result);
  if (errcode != 0)
  {
    perror("getaddrinfo");
    return -1;
  }

  printf("Host: %s\n", host);

  inet_ntop(result->ai_family, result->ai_addr->sa_data, addrstr, 100);

  ptr = &((struct sockaddr_in *)result->ai_addr)->sin_addr;

  inet_ntop(result->ai_family, ptr, addrstr, 100);
  printf("IPv4 addresults: %s\n", addrstr);
  result = result->ai_next;

  freeaddrinfo(result);

  return 0;
}

int main(void)
{
  char inbuf[] = "google.com";

  if (strlen(inbuf) > 0)
    lookup_host(inbuf);

  return EXIT_SUCCESS;
}
