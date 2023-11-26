#include "apue.h"
#include <errno.h>

int
main(int argc, char *argv[])
{
/*  fpritf() format and write output to stream
 *  convert each entry in the argument list if any and write to the stream
 *  according to the corresponding format specification in format*/

/*  strerror() maps the error number in errnum to a locale-dependent error
 *  message string and returns pointer */

/*  EACESS: permission denied */    
    fprintf(stderr, "EACCES: %s\n", strerror(EACCES));
    errno = ENOENT; /* no such file or directory */
    perror(argv[0]);
    exit(0);
}
