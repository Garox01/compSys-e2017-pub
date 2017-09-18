CC=gcc
CFLAGS=-std=c11 -Wall -Werror -Wextra -pedantic -g -Og -nostdlib

BIN=$(patsubst %.c,%.bin,$(wildcard src/*.c))

all: $(BIN)

%.bin: %.c _start.s Makefile
	$(CC) $(CFLAGS) _start.s $< -o $@

dump-%.bin: src/%.bin Makefile
	objdump -M no-aliases -d $<

gdb-%.bin: src/%.bin src/%.gdb Makefile
	gdb -q -x src/$*.gdb $<

clean:
	rm -f src/*.o
	rm -f src/*.bin

.PHONY: all clean
