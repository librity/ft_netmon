// SOURCE: https://stackoverflow.com/questions/7411301/how-to-introduce-date-and-time-in-log-file

// gcc strftime.c  && ./a.out

#include <stdio.h>
#define __STDC_WANT_LIB_EXT1__ 1
#include <time.h>

int	main(void)
{
	char		buff[20];
	struct tm	sTm;
	time_t		now;

	now = time(0);
	gmtime_r(&now, &sTm);
	strftime(buff, sizeof(buff), "%Y-%m-%d %H:%M:%S", &sTm);
	printf("%s %s\n", buff, "Event occurred now");
	return (0);
}
