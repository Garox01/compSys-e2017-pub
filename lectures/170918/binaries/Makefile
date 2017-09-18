CC=gcc
CFLAGS=-std=c11 -Wall -Werror -Wextra -pedantic -g -Og
LDFLAGS=

OBJ=$(patsubst %.c,%.o,$(wildcard src/*.c))
BIN=$(patsubst %.c,%.bin,$(wildcard src/*.c))

all: $(OBJ) $(BIN)

%.bin: %.o Makefile
	$(CC) $(LDFLAGS) $< -o $@

%.o: %.c Makefile
	$(CC) $(CFLAGS) -c $< -o $@

dump-%.o: src/%.o Makefile
	objdump -M no-aliases -d $<

dump-%.bin: src/%.bin Makefile
	objdump -M no-aliases -d $<

gdb-%.bin: src/%.bin src/%.gdb Makefile
	gdb -q -x src/$*.gdb $<

clean:
	rm -f src/*.o
	rm -f src/*.bin

.PHONY: all clean
