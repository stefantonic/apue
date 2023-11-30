#include "apue.h"
#include <fcntl.h>

char    buf1[] = "abcdefgh";
char    buf2[] = "ABCDEFGH";

int
main(int argc, char *argv[])
{
    int     fd;

    if ((fd = creat("file.hole", FILE_MODE)) < 0)
        err_sys("creat error");

    if (write(fd, buf1, 8) != 8)
        err_sys("buf1 write error");

    if (lseek(fd, 16384, SEEK_SET) == -1)
        err_sys("lseek error");

    if (write(fd, buf2, 8) != 8)
        err_sys("buf2 write error");

    exit(0);
}
