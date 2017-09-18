# `.c` → `.s` → `.o`

This directory showcases the workflow of a common compiler: GCC is used to
compile C files into assembly files. The assembly are then assembled into
objects. GCC does not usually emit assembly code and passes it directly on to
the assembler without. This directory showcases this process more explicitly.

`make src/42.c` will:

1. Use GCC compile the C file into an assembly file `src/42.s`.
2. Use AS (GNU Assembler) to assemble `src/42.s` into an object file
   `src/42.o`.

The generated assembly file (e.g., `src/42.s`) contains some assembler
directives, which can make it hard to see the forest for the trees.  The
[`Makefile`](Makefile) has a specialized, phony target for showing assembly
files with assembler directives stripped away. For instance, to see a clean
`src/42.s`, you can `make show-42.s`.

The generated object file (e.g., `src/42.o`) can be disassembled, and the
assembly compared to the originally generated assembly code. These should
correspond up to aliasing and some notational conventions. The
[`Makefile`](Makefile) has a specialized, phony target for dumping object
files. For instance, to dump `src/42.o`, you can `make dump-42.o`.
