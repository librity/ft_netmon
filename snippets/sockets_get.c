// SOURCE: https://www.youtube.com/watch?v=bdIiTxtMaKA&list=PL9IEJIKnBJjH_zM5LnovnoaKlXML5qh17&index=2

// ping -4 example.com
// gcc sockets_get.c  && ./a.out 93.184.216.34

#include <sys/socket.h>
#include <sys/types.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <stdarg.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/time.h>
#include <sys/ioctl.h>
#include <netdb.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <locale.h>

#define SERVER_PORT 80

#define MAXLINE 4096
#define SA struct sockaddr

static void	newline_flush(void)
{
	fprintf(stdout, "\n");
	fflush(stdout);
}

static void	err_n_die(const char *fmt, ...)
{
	int errno_save;
	va_list	ap;

	errno_save = errno;
	va_start(ap, fmt);
	vfprintf(stdout, fmt, ap);
	newline_flush();
	va_end(ap);

	if (errno_save != 0)
	{
		fprintf(stdout, "(errno = %d) = %s\n", errno_save, strerror(errno_save));
		newline_flush();
	}

	exit(EXIT_FAILURE);
}

int main(int argc, char *argv[])
{
	int sockfd;
	int sendbytes;
	int pton_result;
	int connect_result;
	int write_result;
	int read_result;
	int close_result;
	struct sockaddr_in servaddr;
	char sendline[MAXLINE];
	char recvline[MAXLINE];
	char *cursor;

	if (argc != 2)
		err_n_die("USAGE: %s <server_ipv4>", argv[0]);

	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (sockfd < 0)
		err_n_die("Unable to create required socket.");

	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(SERVER_PORT);

	pton_result = inet_pton(AF_INET, argv[1], &servaddr.sin_addr);
	if (pton_result <= 0)
		err_n_die("inet_pton error for %s.", argv[1]);

	connect_result = connect(sockfd, (SA *) &servaddr, sizeof(servaddr));
	if (connect_result < 0)
		err_n_die("Unable to connect to required socket.");

	sprintf(sendline, "GET / HTTP/1.1\r\n\r\n");
	sendbytes = strlen(sendline);

	write_result = write(sockfd, sendline, sendbytes);
	if (write_result != sendbytes)
		err_n_die("Unable to write HTTP request to connected socket.");

	memset(recvline, 0 ,MAXLINE);
	while((read_result = read(sockfd, recvline, MAXLINE-1)) > 0)
	{
		printf("%s", recvline);
		if (strstr(recvline, "\r\n\r\n") != NULL)
			break;
	}
	if (read_result < 0)
		err_n_die("Unable to read HTTP response from connected socket.");

	close_result = close(sockfd);
	if (close_result < 0)
		err_n_die("Unable to close socket.");

	exit(EXIT_SUCCESS);
}
