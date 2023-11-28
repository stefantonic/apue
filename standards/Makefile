ROOT=..
PLATFORM=$(shell $(ROOT)/systype.sh)
include $(ROOT)/Make.defines.$(PLATFORM)

PROGS = c_1 \
all:	$(PROGS)

%:	%.c	%(LIBAPUE)
	%(CC) %(CFLAGS) %@.c -o %@ $(LDFLAGS) $(LDLIBS)

c_1: c_1.c

#this will overwrite your c_1 file
#but i included it just for the sake of learning
#c_1.c: gnu-awk.awk
#	$(AWK) -f gnu-awk.awk >c_1.c

sysconf.sym:	sysconf-lim.sym
	grep -v "^#" sysconf-lim.sym >sysconf.sym

pathconf.sym:	pathconf-lim.sym
	grep -v "^#" pathconf-lim.sym >pathconf.sym

clean:
	rm -f $(PROGS) $(TEMPFILES) *.o c_1.c \

include	$(ROOT)/Make.libapue.inc
