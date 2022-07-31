// SOURCE: https://stackoverflow.com/questions/5141960/get-the-current-time-in-c

// gcc time.c && ./a.out

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

# define TIME_BUFFER_SIZE 26

static void	perr_n_die(char *message)
{
	perror(message);
	exit(EXIT_FAILURE);
}

int	main(void)
{
	time_t		rawtime;
	struct tm	timeinfo;
	void		*result;
	char		time_buffer[TIME_BUFFER_SIZE];

	time(&rawtime);

	result = localtime_r(&rawtime, &timeinfo);
	if (result == NULL)
		perr_n_die("Unable to convert rawtime to calendar time.");

	result = asctime_r(&timeinfo, time_buffer);
	if (result == NULL)
		perr_n_die("Unable to convert calendar time to a human-readable string.");

	printf("Current local time and date: %s", time_buffer);
	return (0);
}
