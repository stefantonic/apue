/* standard i/o function provide a buffered interface to the
 * unbuffered i/o functions
 * using standard i/o relieves us from having to choose optimal buffer sizes,
 * such as BUFFSIZE constant in c_2.c, standard i/o functions also simplify
 * dealing with lines of input
 * */
#include <apue.h>

int
main(void)
{
    int     character;
/*  getc reads on character at a time, and this character is written by putc
 *  after the last byte of input has been read, getc returns the constant EOF */
    while ((character = getc(stdin)) != EOF)
        if ((putc(character, stdout)) == EOF)
            err_sys("output error\n");
    
    if (ferror(stdin))
        err_sys("input error\n");
   
    exit(0);
}
