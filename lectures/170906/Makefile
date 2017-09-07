# OS X users should use additionally gcc-6, gcc will invoke the Clang compiler
CC=gcc-6
CFLAGS=-std=c11 -Wall -Werror -Wextra -pedantic -g
PROGRAMS =limits giveme fib basicio
LIBS =myio.c

.PHONY: clean all

all:
	make $(PROGRAMS)

basicio: basicio.c
	$(CC) $(CFLAGS) -o $@ $<

limits: limits.c
	$(CC) $(CFLAGS) -o $@ $<

giveme: give_me_the_string.c $(LIBS)
	$(CC) $(CFLAGS) -o $@ $< $(LIBS)

fib: fib.c
	$(CC) $(CFLAGS) -o $@ $<

clean:
	rm -f $(PROGRAMS)
	rm -fr $(foreach prg,$(PROGRAMS),$(prg).dSYM)
