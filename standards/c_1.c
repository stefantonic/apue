#include "apue.h"
#include <errno.h>
#include <limits.h>

static void	print_sysconf(char *, int);
static void	print_pathconf(char *, char *, int);

int
main(int argc, char *argv[])
{
	if (argc != 2)
		err_quit("usage: a.out <dirname>");
    /*
    #ifdef ARG_MAX
	    printf("ARG_MAX defined to be %ld\n", (long)ARG_MAX);
    #else
	    printf("no symbol for ARG_MAX\n");
    #endif
    */
    #ifdef _SC_ARG_MAX
	    print_sysconf("_SC_ARG_MAX =", _SC_ARG_MAX);
    #else
	    printf("no symbol for _SC_ARG_MAX\n");
    #endif
    /*
    #ifdef MAX_CANON
        printf("MAX CANON defined to be %ld\n", (long)MAX_CANON+0);
    #else
        printf("no symbol for MAX_CANON\n");
    #endif
    */
    #ifdef _PC_MAX_CANON
        print_pathconf("_PC_MAX_CANON =", argv[1], _PC_MAX_CANON);
    #else
        printf("no symbol for _PC_MAX_CANON\n");
    #endif
    #ifdef _PC_PATH_MAX
        print_pathconf("_PC_PATH_MAX =", argv[1], _PC_PATH_MAX);
    #else
        printf("no symbol for _PC_PATH_MAX\n");
    #endif

    /* ADD MORE IF NEEDED */
	exit(0);
}

static void
print_sysconf(char *message, int name)
{
	long	value;

	fputs(message, stdout);
	errno = 0;
	if ((value = sysconf(name)) < 0) {
		if (errno != 0) {
			if (errno == EINVAL)
				fputs(" (not supported)\n", stdout);
			else
				err_sys("sysconf error");
		} else {
			fputs(" (no limit)\n", stdout);
		}
	} else {
		printf(" %ld\n", value);
	}
}

static void
print_pathconf(char *message, char *path, int name)
{
	long	value;

	fputs(message, stdout);
	errno = 0;
	if ((value = pathconf(path, name)) < 0) {
		if (errno != 0) {
			if (errno == EINVAL)
				fputs(" (not supported)\n", stdout);
			else
				err_sys("pathconf error, path = %s", path);
		} else {
			fputs(" (no limit)\n", stdout);
		}
	} else {
		printf(" %ld\n", value);
	}
}
