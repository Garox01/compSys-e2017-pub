CC=gcc
CFLAGS=-std=c11 -Wall -Werror -Wextra -pedantic -g -Og
ASFLAGS=--warn --fatal-warnings -g

ASM=$(patsubst %.c,%.s,$(wildcard src/*.c))
OBJ=$(patsubst %.c,%.o,$(wildcard src/*.c))

all: $(ASM) $(OBJ)

%.o: %.s Makefile
	as $(ASFLAGS) -c $< -o $@

%.s: %.c Makefile
	$(CC) $(CFLAGS) -S $< -o $@

show-%.s: src/%.s Makefile
	cat $< | sed -E '/\s*\./d'

dump-%.o: src/%.o Makefile
	objdump -M no-aliases -d $<

clean:
	rm -f src/*.s
	rm -f src/*.o

.PHONY: all clean
