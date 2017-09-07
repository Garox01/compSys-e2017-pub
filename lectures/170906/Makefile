# OS X users should use additionally gcc-6, gcc will invoke the Clang compiler
CC=gcc-6
CFLAGS=-std=c11 -Wall -Werror -Wextra -pedantic -g
PROGRAMS =limits giveme fib qsort logic basicio
LIBS =myio.c myprint.c

.PHONY: clean all

all:
	make $(PROGRAMS)

basicio: basicio.c
	$(CC) $(CFLAGS) -o $@ $<

logic: logic.c
	$(CC) $(CFLAGS) -o $@ $<

limits: limits.c
	$(CC) $(CFLAGS) -o $@ $<

giveme: give_me_the_string.c $(LIBS)
	$(CC) $(CFLAGS) -o $@ $< $(LIBS)

fib: fib.c
	$(CC) $(CFLAGS) -o $@ $<

qsort: qsort.c $(LIBS)
	$(CC) $(CFLAGS) -o $@ $< $(LIBS)

clean:
	rm -f $(PROGRAMS)
	rm -fr $(foreach prg,$(PROGRAMS),$(prg).dSYM)
