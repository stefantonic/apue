ROOT=..
PLATFORM=$(shell $(ROOT)/systype.sh)
include $(ROOT)/Make.defines.$(PLATFORM)

PROGS = c_1 c_2 c_3 \

all:	$(PROGS)

%:	%.c	%(LIBAPUE)
	%(CC) %(CFLAGS) %@.c -o %@ $(LDFLAGS) $(LDLIBS)

#c_: c_.c

#c_.c: gnu-awk.awk
#	$(AWK) -f gnu-awk.awk >c_2.c

sysconf.sym:	sysconf-lim.sym
	grep -v "^#" sysconf-lim.sym >sysconf.sym

pathconf.sym:	pathconf-lim.sym
	grep -v "^#" pathconf-lim.sym >pathconf.sym

clean:
	rm -f $(PROGS) $(TEMPFILES) *.o 

include	$(ROOT)/Make.libapue.inc
