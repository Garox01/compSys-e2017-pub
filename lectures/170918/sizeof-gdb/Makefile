CC=gcc
CFLAGS=-std=c11 -Wall -Werror -Wextra -pedantic -g

all: gdb_test

gdb_test: main test.gdb Makefile
	gdb -q -x test.gdb $<

main: main.c Makefile
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f main

.PHONY: all gdb_test clean
