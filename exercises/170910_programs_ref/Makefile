# OS X users should use additionally gcc-6, gcc will invoke the Clang compiler
CC=gcc-6
CFLAGS=-std=c11 -Wall -Werror -Wextra -pedantic -g
PROGRAMS=hello helloF capitalize capitalizeF table tableF1 tableF2 array arrayAddr

.PHONY: clean all

all:
	make $(PROGRAMS)

hello: hello.c
	$(CC) $(CFLAGS) -o $@ $<

helloF: hello_fixed.c
	$(CC) $(CFLAGS) -o $@ $<

capitalize: capitalize.c
	$(CC) $(CFLAGS) -o $@ $<

capitalizeF: capitalize_fixed.c
	$(CC) $(CFLAGS) -o $@ $<

table: table.c
	$(CC) $(CFLAGS) -o $@ $<

tableF1: table_fixed1.c
	$(CC) $(CFLAGS) -o $@ $<

tableF2: table_fixed2.c
	$(CC) $(CFLAGS) -o $@ $<

array: array.c
	$(CC) $(CFLAGS) -o $@ $<

arrayAddr: array_addr.c
	$(CC) $(CFLAGS) -o $@ $<

clean:
	rm -f $(PROGRAMS)
# Needed to clean OS X debug information}
	rm -fr $(foreach prg,$(PROGRAMS),$(prg).dSYM)
