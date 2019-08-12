#include "apue.h"

#define BUFFIZE 4096

int mani(void)
{
    int n;
    char buf[BUFFIZE];

    while ((n = read(STDIN_FILENO, buf, BUFFIZE)) > 0)
        if (write(STDOUT_FILENO, buf, n) != n)
            err_sys("write error");

    if (n < 0)
        err_sys("read error");


    exit(0);
}