/* listing the names of all the files in a directory,
 * this program shows bare-bones implementation of the ls command
 *
 *
 * */
#include <apue.h>

/* dirent.h is the header that contains constructs that facilitate directory
 * traversing, this function is not part of the c standard but is considered
 * pseudo-standard and is usually portable between platforms
 *
 * */
#include <dirent.h>

int
main(int argc, char *argv[])
{
/*  DIR structure representing directory stream */
    DIR           *directory_stream;
/*  structure with the following members
 *  used to return information about directory entries        */
    struct dirent *following_members;
    
    if (argc != 2)
        err_quit("usage: ls directory_name");

    if ((directory_stream = opendir(argv[1])) == NULL)
        err_sys("usage: unavailable %s", argv[1]);

/*  d_name is of unspecified size, contains filename at most {NAME_MAX]
 *  bytes followed by a terminating NULL
 *  filenames are names inside a directory*/
    while ((following_members = readdir(directory_stream)) != NULL)
        printf("directory_stream members: %s\n", following_members->d_name);

    closedir(directory_stream);
    exit(0);
}
