#include "apue.h"
#include <fcntl.h>

int 
main(int argc, char *argv[])
{
    if(argc != 2)
        err_quit("usage : a.out <pathname>");
    if(access(argv[1],F_OK) < 0)
        err_ret("access error fro %s",argv[1]);
    else 
        printf("");
}