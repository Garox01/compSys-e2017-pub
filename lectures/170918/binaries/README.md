# `.c` → `.o` → `.bin`

This directory showcases the workflow in the main stages of a compiler.

`make src/42.c` will:

1. Use GCC to compile the C file into an object file `src/42.o`.
2. Use the GNU Linker to link the object file into an executable `src/42.bin`.

(We use the unconventional extension `.bin` for executable to make them easier
to deal with en masse.)

There are some other specialized, phony targets in the [`Makefile`](Makefile)
which you might find useful:

* `make dump-42.o` uses `objdump` to dump the assembly of `src/42.o`.
* `make dump-42.bin` uses `objdump` to dump the assembly of `src/42.bin`.
* `make gdb-42.bin` fires up a GDB session with `src/42.bin`, assuming that
  there also exists a GDB script `src/42.gdb`.
