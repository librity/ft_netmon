// SOURCE: https://www.geeksforgeeks.org/ping-in-c/

// C program to Implement Ping

// gcc simple_ping.c && sudo ./a.out google.com

#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <netinet/ip_icmp.h>
#include <time.h>
#include <fcntl.h>
#include <signal.h>
#include <time.h>
#include <stdbool.h>

// Define the Packet Constants
// ping packet size
#define PING_PACKET_SIZE 64

// Automatic port number
#define AUTOMATIC_PORT_NUMBER 0

// Gives the timeout delay for receiving packets
// in seconds
#define PING_RECEIVE_TIMEOUT 1
#define PING_TIME_TO_LIVE 64

#define IPV4_ADDRESS_STRING_SIZE 16

// ping packet structure
typedef struct s_ping_packet
{
	struct icmphdr hdr;
	char msg[PING_PACKET_SIZE - sizeof(struct icmphdr)];
} t_ping_packet;

typedef struct sockaddr_in t_inet_socket_addr;

// Calculating the Check Sum
unsigned short checksum(void *b, int len)
{
	unsigned short *buf = b;
	unsigned int sum = 0;
	unsigned short result;

	for (sum = 0; len > 1; len -= 2)
		sum += *buf++;
	if (len == 1)
		sum += *(unsigned char *)buf;
	sum = (sum >> 16) + (sum & 0xFFFF);
	sum += (sum >> 16);
	result = ~sum;
	return result;
}

char *get_host_ipv4(char *host)
{
	struct addrinfo hints;
	struct addrinfo *result;
	int errcode;
	char *ipv4_address;
	void *ptr;

	ipv4_address = malloc(IPV4_ADDRESS_STRING_SIZE);

	memset(&hints, 0, sizeof(hints));
	hints.ai_family = AF_INET;
	hints.ai_flags |= AI_CANONNAME;

	errcode = getaddrinfo(host, NULL, &hints, &result);
	if (errcode != 0)
	{
		perror("getaddrinfo");
		return NULL;
	}

	printf("Host: %s\n", host);

	inet_ntop(result->ai_family, result->ai_addr->sa_data, ipv4_address, 100);

	ptr = &((struct sockaddr_in *)result->ai_addr)->sin_addr;

	inet_ntop(result->ai_family, ptr, ipv4_address, 100);
	printf("IPv4 addresults: %s\n", ipv4_address);
	result = result->ai_next;

	freeaddrinfo(result);

	return (ipv4_address);
}

// Performs a DNS lookup
char *dns_lookup(char *name, struct sockaddr_in *addr_con)
{
	struct addrinfo hints;
	struct addrinfo *result;
	int errcode;
	char *ipv4_address;
	void *ptr;

	ipv4_address = malloc(IPV4_ADDRESS_STRING_SIZE);

	memset(&hints, 0, sizeof(hints));
	hints.ai_family = AF_INET;
	hints.ai_flags |= AI_CANONNAME;

	errcode = getaddrinfo(name, NULL, &hints, &result);
	if (errcode != 0)
	{
		perror("getaddrinfo");
		return NULL;
	}

	printf("Host: %s\n", name);

	(*addr_con).sin_family = AF_INET;
	(*addr_con).sin_port = htons(AUTOMATIC_PORT_NUMBER);
	(*addr_con).sin_addr = ((struct sockaddr_in *)result->ai_addr)->sin_addr;

	// Extract ipv4 from first result.
	inet_ntop(result->ai_family, result->ai_addr->sa_data, ipv4_address, 100);
	ptr = &((struct sockaddr_in *)result->ai_addr)->sin_addr;
	inet_ntop(result->ai_family, ptr, ipv4_address, 100);
	printf("IPv4 addresults: %s\n", ipv4_address);
	result = result->ai_next;

	freeaddrinfo(result);


	printf("\nResolving DNS..\n");
	printf("\n%s:%s\n", name, ipv4_address);



	return ipv4_address;
}

// make a ping request
void send_ping(int ping_sockfd, t_inet_socket_addr *ping_addr)
{
	bool packet_was_sent;
	int time_to_live;
	int address_length;
	int i;

	t_ping_packet pckt;
	t_inet_socket_addr r_addr;
	struct timeval tv_out;
	tv_out.tv_sec = PING_RECEIVE_TIMEOUT;
	tv_out.tv_usec = 0;

	// set socket options at ip to TTL and value to 64,
	// change to what you want by setting PING_TIME_TO_LIVE
	time_to_live = PING_TIME_TO_LIVE;
	if (setsockopt(ping_sockfd, SOL_IP, IP_TTL, &time_to_live, sizeof(time_to_live)) != 0)
	{
		printf("\nSetting socket options to TTL failed!\n");
		return;
	}
	printf("\nSocket set to TTL..\n");

	// setting timeout of recv setting
	setsockopt(ping_sockfd, SOL_SOCKET, SO_RCVTIMEO, (const char *)&tv_out, sizeof tv_out);

	// send icmp packet

	// flag is whether packet was sent or not
	packet_was_sent = true;

	// filling packet
	bzero(&pckt, sizeof(pckt));

	pckt.hdr.type = ICMP_ECHO;
	pckt.hdr.un.echo.id = getpid();

	for (i = 0; i < sizeof(pckt.msg) - 1; i++)
		pckt.msg[i] = i + '0';

	pckt.msg[i] = 0;
	pckt.hdr.checksum = checksum(&pckt, sizeof(pckt));

	// send packet
	if (sendto(ping_sockfd, &pckt, sizeof(pckt), 0,
			   (struct sockaddr *)ping_addr,
			   sizeof(*ping_addr)) <= 0)
	{
		printf("\nPacket Sending Failed!\n");
		packet_was_sent = false;
	}

	// receive packet
	address_length = sizeof(r_addr);

	if (recvfrom(ping_sockfd, &pckt, sizeof(pckt), 0,
				 (struct sockaddr *)&r_addr, &address_length) <= 0)
	{
		printf("\nPacket receive failed!\n");
		return;
	}

	// if packet was not sent, don't receive
	if (!packet_was_sent)
	{
		printf("\nPacket wasn't sent!\n");
		return;
	}

	if (!(pckt.hdr.type == 69 && pckt.hdr.code == 0))
	{
		printf("Error..Packet received with ICMP type %d code %d\n",
			   pckt.hdr.type, pckt.hdr.code);
		return;
	}

	printf("SUCCESS: echo %d bytes from target.\n", PING_PACKET_SIZE);
}

// Driver Code
int main(int argc, char *argv[])
{
	int sockfd;
	char *ip_addr;
	t_inet_socket_addr addr_con;

	if (argc != 2)
	{
		printf("\nFormat %s <address>\n", argv[0]);
		return 0;
	}

	ip_addr = dns_lookup(argv[1], &addr_con);
	if (ip_addr == NULL)
	{
		printf("\nDNS lookup failed! Could not resolve hostname!\n");
		return 0;
	}

	// socket()
	sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
	if (sockfd < 0)
	{
		printf("\nSocket file descriptor not received!!\n");
		return 0;
	}
	else
		printf("\nSocket file descriptor %d received\n", sockfd);

	// send pings continuously
	send_ping(sockfd, &addr_con);

	return 0;
}
