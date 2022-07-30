// SOURCE: https://man7.org/linux/man-pages/man3/inet_pton.3.html

// gcc inet_pton.c && ./a.out i4 172.217.28.238
// gcc inet_pton.c && ./a.out i6 0:0:0:0:0:FFFF:204.152.189.116

#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
	unsigned char buf[sizeof(struct in6_addr)];
	unsigned char *buffer_printer;
	int domain, s;
	int i;
	char str[INET6_ADDRSTRLEN];

	if (argc != 3)
	{
		fprintf(stderr, "Usage: %s {i4|i6|<num>} string\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	domain = (strcmp(argv[1], "i4") == 0) ? AF_INET : (strcmp(argv[1], "i6") == 0) ? AF_INET6
																				   : atoi(argv[1]);

	s = inet_pton(domain, argv[2], buf);
	if (s <= 0)
	{
		if (s == 0)
			fprintf(stderr, "Not in presentation format");
		else
			perror("inet_pton");
		exit(EXIT_FAILURE);
	}


	printf("NETWORK: ");
	i = 0;
	while (i < sizeof(struct in6_addr))
	{
		printf("%d ", *(buf + i));
		i++;
	}
	printf("\n");

	if (inet_ntop(domain, buf, str, INET6_ADDRSTRLEN) == NULL)
	{
		perror("inet_ntop");
		exit(EXIT_FAILURE);
	}

	printf("%s\n", str);

	exit(EXIT_SUCCESS);
}
