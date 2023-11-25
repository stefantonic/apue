/*  bare-bones implementation of shell-like program 
 *  ./c_5 test with date, who, pwd and ls, ^D terminates */
#include "apue.h"
#include <sys/wait.h>

int
main(void)
{
    char    buf[MAXLINE];
    pid_t   pid;
    int     status;

    printf("%%  ");
    /*  reads a line from specified stream(input in this case),
     *  and stores it into the string pointed by buf*/
    while (fgets(buf, MAXLINE, stdin) != NULL) {
        if (buf[strlen(buf) - 1] == '\n')
            buf[strlen(buf) - 1] = 0;
        /* process can create new process using fork() sys-call,
         * makes the duplicate of parent process and chil inherits copies
         * of parent's data, stack, heap segment*/
        if ((pid = fork()) < 0) {
            err_sys("fork(): error\n");
        } else if (pid == 0) {
            execlp(buf, buf, (char *) 0);
            err_ret("couldn't execute: %s", buf);
            exit(127);
        }
   /* waitpid suspends calling process until a child process ends or is stopped */ 
    if ((pid = waitpid(pid, &status, 0)) < 0)
        err_sys("waitpid error");
    printf("%% ");
    }

    exit(0);
}
