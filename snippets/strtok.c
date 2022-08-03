// SOURCES: https://man7.org/linux/man-pages/man3/strtok.3.html

// gcc strtok.c  && ./a.out "a/bbb///cc;xxx:yyy:" ":;" "/"

      #include <stdio.h>
       #include <stdlib.h>
       #include <string.h>

int main()
{
    char str[] = "Geeks-for-Geeks";

    // Returns first token
    char* token = strtok(str, " - ");

    // Keep printing tokens while one of the
    // delimiters present in str[].
    while (token != NULL) {
        printf("%s\n", token);
        token = strtok(NULL, " - ");
    }
    printf("original: %s\n", str);

    return 0;
}
