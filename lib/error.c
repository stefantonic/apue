/* defines macros for reporting and retrieving error conditions using symbol errno */
#include "apue.h"
/* errno, short for error number defines macroes for reporting and retrieving
 * error conditions using the symbol errno
 * errno shall define the following macros which shall expand to integer 
 * constant expressions with type int*/
#include <errno.h>

/* contain a set of macros which allows portable functions that accept variable
 * argument lists to be written
 * defines va_list type for variables used to traverse the list 
 * it is suitable for holding information needed by macros va_start, copy and end */
#include <stdarg.h>

static void
err_doit(int errnoFlag, int error, const char *format, va_list argument_pointer); 

/*  non-fatal error related to a system call
 *  err_ret prints a message and return */
void
err_ret(const char *format, ...)
/* three dots indicate that the function has a variable number of arguments */
{
/*  type for variables used to traverse the list */
    va_list     argument_pointer;
/*  va_start is invoked to initialize ap to the beginning of the list before
 *  va_arg() */
    va_start(argument_pointer, format);
    err_doit(1, errno, format, argument_pointer);
    va_end(argument_pointer);
}

/*  fatal error related to a system call
 *  err_sys prints a message and terminate */
void
err_sys(const char *format, ...)
{
    va_list     argument_pointer;

    va_start(argument_pointer, format);
    err_doit(1, errno, format, argument_pointer);
    va_end(argument_pointer);
    exit(1);
}

/*  non-fatal error unrelated to a system call 
 *  error code passed as explicit parameter,
 *  print a message and return */
void
err_cont(int error, const char *format, ...)
{
    va_list     argument_pointer;

    va_start(argument_pointer, format);
    err_doit(1, error, format, argument_pointer);
    va_end(argument_pointer);
}

/*  fatal error unrelated to a system call
 *  error code passed as explicit parameter,
 *  print a message and terminate */
void
err_exit(int error, const char* format, ...)
{
    va_list     argument_pointer;

    va_start(argument_pointer, format);
    err_doit(1, error, format, argument_pointer);
    va_end(argument_pointer);
    exit(1);
}

void
err_dump(const char *format, ...);

void
err_msg(const char *format, ...);

/*
 * fatal error unrelated to a system call
 * print message and terminate */
void
err_quit(const char *format, ...)
{
    va_list     argument_pointer;

    va_start(argument_pointer, format);
    err_doit(0, 0, format, argument_pointer);
    va_end(argument_pointer);
    exit(1);
}

/* print message and return to caller
 * caller specifies "errnoFlag" */
static void
err_doit(int errnoFlag, int error, const char *format, va_list argument_pointer)
{
    char    buf[MAXLINE];
/*  vsnprintf() function formats and stores a series of characters and values
 *  in buffer target-string, argument_pointer points to a list of arguments
 *  whose number can vary from call to call in the program 
 *
 *  return number of bytes that are written in the array not counting ending null ch*/
    vsnprintf(buf, MAXLINE-1, format, argument_pointer);
    if (errnoFlag)
/*  snprintf() formats and stores series of chars and values in array buffer
 *  any argument-lit is converted and put out according to the corrseponding
 *  format specification in the format-string*/
        snprintf(buf+strlen(buf), MAXLINE-strlen(buf)-1, ": %s\n",
/*              strerror() points to the string and prints runntime error 
 *              message if an error occurs  */
                strerror(error));
/*  strcat() concatenates string2 to string1 and ends resulting string with NULL */ 
    strcat(buf, "\n");
    fflush(stdout);
    fputs(buf, stderr);
    fflush(NULL);
/*  ADD NOTES */
}
