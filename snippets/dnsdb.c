// SOURCE: https://www.farsightsecurity.com/blog/txt-record/dnsdb-libcurl-20161104/

// gcc dnsdb.c -I /home/lgeniole/.local/include -L /home/lgeniole/.local/lib -lcurl  && ./a.out

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

int main (int argc, char **argv)
{
        CURL *curl;
        CURLcode res;
        char mydomain[1024], tempstring[1024], fullcommand[1024];

        /* initialize curl. must be called once and only once. */
        if (curl_global_init(CURL_GLOBAL_ALL) != 0)
        {
                fprintf(stderr, "curl_global_init() failed\n");
                return (EXIT_FAILURE);
        }

        /* get base domain from stdin */
        while (scanf("%s", mydomain) == 1)
        {
                /* build the command we want to pass to curl */
                /* all our commands use the same basic RESTFUL API endpoint... */
                strcpy(fullcommand, "https://api.dnsdb.info/lookup/rrset/name/");

                /* now tack on the domain */
                strcpy(tempstring, mydomain);
                strcat(fullcommand, tempstring);

                /* just give me a token dozen results */
                strcpy(tempstring, "?limit=12");
                strcat(fullcommand, tempstring);

                /* get curl ready for action */
                curl = curl_easy_init();

                /* pass the API key */
                struct curl_slist *chunk = NULL;
                chunk = curl_slist_append(chunk, "X-API-Key: [elided]");
                res = curl_easy_setopt(curl, CURLOPT_HTTPHEADER, chunk);

                /* do the actual curl command */
                curl_easy_setopt(curl, CURLOPT_URL, fullcommand);
                res = curl_easy_perform(curl);
                if (res != CURLE_OK)
                {
                        return (EXIT_FAILURE);
                }
                curl_easy_cleanup(curl);
        }

        curl_global_cleanup();
        return (EXIT_SUCCESS);
}
