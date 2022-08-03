// SOURCE: https://www.theinsanetechie.in/2016/02/dns-lookup-implementation-in-c.html

// gcc dnsda.c  && ./a.out

/**dnsclient.c**/
#include "stdio.h"
#include "stdlib.h"
#include "sys/types.h"
#include "sys/socket.h"
#include "string.h"
#include "netinet/in.h"
#include "netdb.h"
#include "arpa/inet.h"

#define BUF_SIZE 512
#define SERVER "8.8.8.8"
#define PORT 53
#define WIDTH 16

int createSocket();
void createRequest(char *url);
void lookUp();

typedef struct s_query
{
	uint16_t length;
	char *url;
	unsigned char request[BUF_SIZE];
	uint16_t reqType;
} t_query;

t_query dnsQuery = {
	.length = 12,
	.url = "",
	.reqType = 0x01,
	.request = {0xDB, 0x42, 0x01, 0x00, 0x00, 0x01,
				0x00, 0x00, 0x00, 0x00, 0x00, 0x00}};

int main(int argc, char **argv)
{
	char *url;

	if (argc != 2)
	{
		fprintf(stderr, "usage: %s hostnameToResolve\n", argv[0]);
		exit(1);
	}

	url = argv[1];

	createRequest(url);
	lookUp();
}

int createSocket()
{
	int sockfd;

	sockfd = socket(AF_INET, SOCK_DGRAM, 0);
	if (sockfd < 0)
	{
		printf("Error creating socket!\n");
		exit(1);
	}
	// printf("Socket created...\n");

	return sockfd;
}

void createRequest(char *url)
{
	char *word;
	int i;
	printf("Asking DNS server %s about %s\n", SERVER, url);
	dnsQuery.url = strdup(url);
	dnsQuery.reqType = 0x01;

	word = strtok(url, ".");
	while (word)
	{
		printf("parsing hostname: \"%s\" is %d characters\n", word,
			   strlen(word));
		dnsQuery.request[dnsQuery.length++] = strlen(word);
		for (i = 0; i < strlen(word); i++)
		{
			dnsQuery.request[dnsQuery.length++] = word[i];
		}
		word = strtok(NULL, ".");
	}

	dnsQuery.request[dnsQuery.length++] = 0x00; // End of the host name
	dnsQuery.request[dnsQuery.length++] = 0x00; // 0x0001 - Query is a Type A
	// query (host address)
	dnsQuery.request[dnsQuery.length++] = dnsQuery.reqType;
	dnsQuery.request[dnsQuery.length++] = 0x00; // 0x0001 - Query is class IN
												// (Internet address)
	dnsQuery.request[dnsQuery.length++] = 0x01;
}

void lookUp()
{
	struct sockaddr_in addr;
	int socket;
	int ret, rcode, size, i;
	int ip = 0, dom = 0;
	int length;
	unsigned char buffer[BUF_SIZE];
	unsigned char tempBuf[3];

	socket = createSocket();

	memset(&addr, 0, sizeof(addr));
	addr.sin_family = AF_INET;
	addr.sin_addr.s_addr = inet_addr(SERVER);
	addr.sin_port = htons(PORT);
	size = sizeof(addr);

	ret = sendto(socket, dnsQuery.request, dnsQuery.length, 0,
				 (struct sockaddr *)&addr, size);
	if (ret < 0)
	{
		printf("Error Sending Request");
		exit(1);
	}
	// printf("Sent\n");

	memset(&buffer, 0, BUF_SIZE);
	ret = recvfrom(socket, buffer, BUF_SIZE, 0, (struct sockaddr *)&addr,
				   &size);
	if (ret < 0)
	{
		printf("Error Receiving Response");
		exit(1);
	}


	close(socket);

	rcode = (buffer[3] & 0x0F);


	if (rcode == 2)
	{
		printf("nameserver %s returned SERVFAIL:\n", SERVER);
		printf("  the name server was unable to process this query due to a\n\
 problem with the name server.\n");
		exit(1);
	}
	else if (rcode == 3)
	{
		printf("nameserver %s returned NXDOMAIN for %s:\n", SERVER,
			   dnsQuery.url);
		printf("  the domain name referenced in the query does not exist\n");
		exit(1);
	}

	/* search for and print IPv4 addresses */
	if (dnsQuery.reqType == 0x01)
	{
		printf("ADDRESS:");

		for (i = 0; i < ret; i++)
		{
			if (buffer[i] == 0xC0 && buffer[i + 3] == 0x01)
			{
				ip++;
				i += 12; /* ! += buf[i+1]; */
				printf(" %u.%u.%u.%u\n", buffer[i], buffer[i + 1],
					   buffer[i + 2], buffer[i + 3]);
			}
		}

		if (!ip)
		{
			printf("  No IPv4 address found in the DNS response!\n");
			exit(1);
		}
	}
}
