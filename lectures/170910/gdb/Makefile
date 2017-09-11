# OS X users should use additionally gcc-6, gcc will invoke the Clang compiler
CC=gcc-6
CFLAGS=-std=c11 -Wall -Werror -Wextra -pedantic -g
PROGRAMS=macro lastchar segfault
# LIBS=myio.c

.PHONY: clean all

all:
	make $(PROGRAMS)

macro: macro.c
	$(CC) $(CFLAGS) -o $@ $<

lastchar: lastchar.c
	$(CC) $(CFLAGS) -o $@ $<

segfault: segfault.c
	$(CC) $(CFLAGS) -o $@ $<

clean:
	rm -f $(PROGRAMS)
# Needed to clean OS X debug information}
	rm -fr $(foreach prg,$(PROGRAMS),$(prg).dSYM)
