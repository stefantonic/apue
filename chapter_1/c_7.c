/*  print user id: and group id: */
#include <apue.h>

int
main(void)
{
    printf("user-id: %d\ngroup-id: %d\n", getuid(), getgid());
    exit(0);
}
