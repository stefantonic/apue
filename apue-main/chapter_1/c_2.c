/*  default behaviour of the standard "cat" command,
 *  consult "man" page for cat to see the "options" that would need to be
 *  added to achieve a total "cat" emulation
 *
 *  read from the standard input and write to the standard output
 *  copies any regular file on a unix system 
 *
 *  ./c_2 > infile.txt
 *  than write your message
 *  or
 *  ./c_2 < infile.txt
 *  reads your message from the text file
 *  or
 *  ./c_2 > infile.txt < outfile.txt
 *  copies text from file to file */
#include <apue.h>
#define BUFFSIZE    4096

int
main(void)
{
    int     n;
    char    buf[BUFFSIZE]; 
    /* file descriptors or file handles are integer identifiers that specify
     * data structures, the linux kernel refers to these structures as file
     * structs since they can describe open files
     * index of a file struct is the file handle, each process has it's own
     * set of open file
     * example:
     * 0 -> reads, 1 -> writes, 2 -> reads and so on
     * */
/*  stdin_fileno is default standard input file descriptor number which is 0
 *  n contains the number of bytes that are read, and this value is used
 *  as the number of bytes to write*/
    while ((n = read(STDIN_FILENO, buf, BUFFSIZE)) > 0)
        if (write(STDOUT_FILENO, buf, n) != n)
            err_sys("STDOUT_FILENO: error\n"); 
    if (n < 0)
        err_sys("STDIN_FILENO: error\n"); 
    
    exit(0);
}
