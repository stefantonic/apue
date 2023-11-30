/* test whether standard input is capable of seeking 
 * ./c_1 < /etc/passwd to test */

#include "apue.h"

int
main(int argc, char *argv[])
{
    /*STDIN_FILENO is POSIX.1 for 1 (output)
     *SEEK_CUR file's offset set to it's current value plus the offset */
    if(lseek(STDIN_FILENO, 0, SEEK_CUR) == -1)
        printf("cannot seek\n");
    else
        printf("seek OK\n");
    exit(0);
}
