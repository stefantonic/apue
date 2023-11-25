#!/bin/bash
#dirs(filenames along with it's attributes), has to be updated as we add more
#for now, apue-master only has .c files followed by makefiles in intro and lib
DIRS = chapter_1 lib

#all includes all within directory and sub directories
#for i(iterate) through included dirs, for each file, display making: name + make
all:
	@for i in $(DIRS); do (cd $$i && echo "making: $$i" && $(MAKE)) || exit 1; done
#clean is optinal rile, it allows us to type make clean to get rid of
#objects and executable files
clean:
	@for i in $(DIRS); do (cd $$i && echo "making: $$i" && $(MAKE) clean) || exit 1; done
