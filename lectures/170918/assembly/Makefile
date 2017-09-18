ASFLAGS=--warn --fatal-warnings -g
LDFLAGS=

OBJ=$(patsubst %.s,%.o,$(wildcard src/*.s))
BIN=$(patsubst %.s,%.bin,$(wildcard src/*.s))

all: $(OBJ) $(BIN)

%.bin: %.o Makefile
	ld $(LDFLAGS) $< -o $@

%.o: %.s _start.s Makefile
	as $(ASFLAGS) _start.s $< -o $@

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
