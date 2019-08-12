#include "apue.h"
#include <fcntl.h>


int main(int argc, char *argv[]){

    int val;
    printf("%s \n", argv[0]);
        printf("%s \n", argv[1]);
        printf("%s \n", argv[2]);

    if (argc != 2)
        err_quit("usage: a.out <descriptor#>");

    if((val = fcntl(atoi(argv[1]), F_GETFL, 0)) < 0)
        err_quit("fcntl error for fd %d", atoi(argv[1]));

    switch (val & O_ACCMODE)
    {
        case O_RDONLY:
            printf("redad only");
            break;

        case O_WRONLY:
            printf("write only");
            break;

        case O_RDWR:
            printf("read write");
            break;

        default:
            err_dump("unkown access mode");
    }

    if (val & O_APPEND)
        printf(", append");
    if(val & O_NONBLOCK)
        printf(", nonblocking");
    if(val & O_SYNC)
        printf(", synchronous writed");

    #if !defined(_POSIX_C_SOURCE) && defined(O_FSYNC) && (O_FSYNC != O_SYNC)

        if(val & O_FSYNC)
            printf(", synchronous writed");
    #endif

    putchar('\n');
    exit(0);
}