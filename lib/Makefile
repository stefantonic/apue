#library for misc(miscellaneous library)
#collection of functions and classes that are useful in the development
#modules in multiple libraries
ROOT=..
#based on the system we use
PLATFORM=$(shell $(ROOT)/systype.sh)
include $(ROOT)/Make.defines.$(PLATFORM)

#misc(miscellaneous library) contains assorted classes such as
#error handling, file i/o, containers, configuration file management etc
#provided by [http://www.apuebook.com/]
LIBMISC	= libapue.a

#needs to be updated as we write more programs
OBJS   = error.o \

#includes all within directory and sub directories of ../lib/libapue.a
all:	$(LIBMISC)

#
$(LIBMISC):	$(OBJS)
#archiver(unix utility) that maintains group of files as a single archive
#r replaces or adds files to the archives(OBJS included)
#v gives verbose output and displays the command letter and the member name
#affected before performing each operation
	$(AR) rv $(LIBMISC) $?

#creates an index of the archive content which speeds up speeding process
#with (objs included) && ../lib/libapue.a
	$(RANLIB) $(LIBMISC)


clean:
#delete temp files from each directory
	rm -f *.o a.out core temp.* $(LIBMISC)

#make.libapue.inc is path where libapue.a resides
include $(ROOT)/Make.libapue.inc
