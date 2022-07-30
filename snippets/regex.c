// SOURCE: https://stackoverflow.com/questions/1085083/regular-expressions-in-c-examples

// gcc regex.c && ./a.out

#include <regex.h>
#include <stdio.h>
#include <stdlib.h>

regex_t regex;
int reti;
char msgbuf[100];

int main(void)
{
	/* Compile regular expression */
	reti = regcomp(&regex, "^a[[:alnum:]]", 0);
	if (reti)
	{
		fprintf(stderr, "Could not compile regex\n");
		exit(1);
	}

	/* Execute regular expression */
	reti = regexec(&regex, "__", 0, NULL, 0);
	if (!reti)
	{
		puts("Match");
	}
	else if (reti == REG_NOMATCH)
	{
		puts("No match");
	}
	else
	{
		regerror(reti, &regex, msgbuf, sizeof(msgbuf));
		fprintf(stderr, "Regex match failed: %s\n", msgbuf);
		exit(1);
	}

	/* Free memory allocated to the pattern buffer by regcomp() */
	regfree(&regex);
	return (0);
}
