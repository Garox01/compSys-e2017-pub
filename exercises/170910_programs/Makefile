# OS X users should use additionally gcc-6, gcc will invoke the Clang compiler
CC=gcc-6
CFLAGS=-std=c11 -Wall -Werror -Wextra -pedantic -g
PROGRAMS=hello capitalize table array

.PHONY: clean all

all:
	make $(PROGRAMS)

hello: hello.c
	$(CC) $(CFLAGS) -o $@ $<

table: table.c
	$(CC) $(CFLAGS) -o $@ $<

capitalize: capitalize.c
	$(CC) $(CFLAGS) -o $@ $<

array: array.c
	$(CC) $(CFLAGS) -o $@ $<

clean:
	rm -f $(PROGRAMS)
# Needed to clean OS X debug information}
	rm -fr $(foreach prg,$(PROGRAMS),$(prg).dSYM)
