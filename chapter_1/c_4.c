/*  executing instance of a program is called a process, some os-s use the
 *  term task to refer to a program that is being executed
 *  unix system guarantees that every process has a unique numeric identifier
 *  called t he process ID, process ID is always non-negative integer i
 *  
 *  from kernel perspective the pid(which is shered by all of the threads
 *  in multithreaded process) is sometimes also known as thread group id(TPID)
 *  which is unique for each thread*/
#include "apue.h"

int
main(void)
{
/*  getpid() returns the process id of the calling process
 *  generally used by routines that generate unique temporary filenames*/
    printf("process id: %ld\n", (long)getpid());
    exit(0);
}
