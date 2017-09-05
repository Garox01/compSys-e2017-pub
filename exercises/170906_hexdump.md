# Exercises for 6/9-2017

Author: Oleks Shturmov <oleks@oleks.info>

These exercises are intended to give you some practice with the sort of tasks
that you will be doing in this week's assignment.

For all of the below, you should use `make` to build your programs. To
parametrize `make` to build with all the necessary compiler flags, start by
writing down a `Makefile` containing the following:

```
CC=gcc
CFLAGS=-std=c11 -Wall -Werror -Wextra -pedantic -g
```

Now, to compile the programs below, just `make` them. For example:

```
$ make unary
```

## `./unary`

Write a C program `unary` that given a single command-line argument exits with
`EXIT_SUCCESS`. When given 0, 2, or more arguments, it should exit with
`EXIT_FAILURE`, and print a usage message to `stderr`. (Hint: `EXIT_SUCCESS`
and `EXIT_FAILURE` are defined in `stdlib.h`.)

Use `echo $?` to determine the exit code of the most recent shell command:

```
$ ./unary
$ echo $?
1
$ ./unary arg
$ echo $?
0
```

## `./hello argument`

Write a C program `hello` that handles command-line arguments as above. When
given an argument, it prints `"Hello, %s!\n"` to `stdout`, where `%s` is the
given argument. When the number of arguments is wrong, let it print a usage
message to `stderr`, with the format `"Usage: %s argument\n"`, where `%s` is
the name of the binary.

Sample interaction with `hello`:

```
$ ./hello
Usage: ./hello argument
$ echo $?
1
$ ./hello Eric
Hello, Eric!
$ echo $??

0
```

## `./readable path`

Write a C program `readable` that handles command-line arguments as above, but
calls the argument "`path`". When given a path argument, it attempts to open
the given path for reading using `fopen`. If successful, it prints the line
`Yes` to `stdout`. If unsuccessful, it prints the error reported by the
standard library and exits with `EXIT_FAILURE`.

`fopen` returns `NULL` in case of failure and sets the variable `errno` to a
numerical code representing the error. You can access `errno` if you import
`errno.h`. Furthermore, if you import `string.h`, you can use the function
`strerror` that will give a string representation of the error.

In the end, you can use the following `fprintf`-call in case of failure

```
fprintf(stderr, "%s\n", strerror(errno));
```

Sample interaction with `readable`:

```
$ ./readable
Usage: ./readable path
$ echo $?
1
$ ./readable /
Yes
$ ./readable readable
Yes
$ echo $?
0
$ ./readable vulapyk
No such file or directory
$ echo $?
1
```

## `./size path`

Write a C program `size` that handles command-line arguments as above. When
given a path argument, it attempts to determine the size of the file in bytes.
If the size can be determined, the number is printed as a line to `stdout`, and
`size` exits with `EXIT_SUCCESS`. In all other cases, it should exit with
`EXIT_FAILURE`. (Hint: Use `fseek` and `ftell`.)

Sample interaction with `size`:

```
$ ./size Makefile
58
$ ./size size.c
694
$ ./size size
14392
$ echo $?
0
$ ./size vulapyk
No such file or directory
$ echo $?
1
```

Challenge: Can you determine the size of a file without opening it?

## `./hexabyte path`

Write a C program `hexabyte` that handles command-line arguments as above. When
given a path argument, it opens the file and prints it byte-by-byte, using the
format `"%02x\n"` for each byte. (Hint: Use `fread` and `feof`.)

Sample interaction with `hexabyte`:

```
$ ./hexabyte Makefile
43
43
3d
67
...
20
2d
67
0a
```

## Play with integer number representations

At [Integral Number Representations](https://games.onlineta.org/integers.html)
you find a small game you can play by converting from different integer number
representations.

Get 10 correct answers or even beat Michael's longest streak from the lectures.

Next, answer all of the following:

* https://games.onlineta.org/integers.html#NjdfZmFsc2VfMV8yXzE=
* https://games.onlineta.org/integers.html#NjFfZmFsc2VfMV8yXzE=
* https://games.onlineta.org/integers.html#MTAzX2ZhbHNlXzFfMl8x
* https://games.onlineta.org/integers.html#OTBfZmFsc2VfMV8yXzE=
* https://games.onlineta.org/integers.html#MjU1X2ZhbHNlXzFfMF8y
* https://games.onlineta.org/integers.html#MTUzX2ZhbHNlXzFfMF8y
* https://games.onlineta.org/integers.html#MjE5X2ZhbHNlXzFfMF8x
* https://games.onlineta.org/integers.html#OTBfZmFsc2VfMV8wXzE=

## `./hexdump path`

The `hexabyte` utility above is a miniature variant of the standard
`hexdump(1)` utility, which we hope you will grow to know and love throughout
this course.

The utility uses a slightly more evolved output format. We will learn more
about the option-less format next week. This week we show only the "canonical"
format achieved with `hexdump -C`:

```
$ hexdump -C Makefile 
00000000  43 43 3d 67 63 63 0a 43  46 4c 41 47 53 3d 2d 73  |CC=gcc.CFLAGS=-s|
00000010  74 64 3d 63 31 31 20 2d  57 61 6c 6c 20 2d 57 65  |td=c11 -Wall -We|
00000020  72 72 6f 72 20 2d 57 65  78 74 72 61 20 2d 70 65  |rror -Wextra -pe|
00000030  64 61 6e 74 69 63 20 2d  67 0a                    |dantic -g.|
0000003a
```

A canonical hexdump shows 16 bytes per line, each byte printed as a 2-digit hex
number, padded with 0's.

Each line starts with the offset of the first byte printed on that line, from
the start of the file. The offset is printed as an 8-digit hex number, padded
with 0's. The very last line prints the size of the file, in the same format.
(What is the size of `Makefile` in decimal notation? In decimal notation, how
big a file can `hexdump -C` handle?)

Each line of bytes is followed by a character printout of the 16 bytes,
enclosed in pipe-characters.

There are two spaces between the offset and the first byte, between the 8th and
9th byte, and between the last byte and the character printout.

The next-to-last line may have fewer than 16 bytes, as not all files are
aligned to divide evenly by 16. The character printout in this case is padded
to vertically align with the character output above.

Write a C program `hexdump` to mimic the behaviour of `hexdump -C`.
