# Guidelines

The programs are the original, while I have underscore "_fixed" the updated versions.


## `hello.c`

Show error
```
make hello
./hello Michael
```

Gives a seg fault. Debug:
```
gdb hello -x hello.gdb
```

Now it works in `hello_fixed.c`
```
make hello
./helloF Michael
```

## `capitalized.c`
Show error
```
make capitalize
./capitalize Michael
```

Does not capitalize my name. Debug:
```
gdb capitalize -x capitalize.gdb
```

Now it works in `capitalize_fixed.c`
```
make capitalizeF
./capitalizeF Michael
```

## `table.c`

Show error
```
make table
./table
```

Gives a seg fault. Debug:
```
gdb table -x table1.gdb
```

Fixed in `table_fixed1.c`
```
make tableF1
./tableF1
```

Still a problem...
```
gdb tableF1 -x table2.gdb
```

This is to show conditional breakpoints

Fixed in `table_fixed2.c`

## `array.c`

Show error
```
make array
./array
```

Gives a seg fault. Interesting that it is after printing... Debug:
```
gdb table
(gdb) run
```

So the segmentation fault is just before returning...
```
gdb array -x array.gdb
```

It does not make sense to fix it. However we can examine further.

First we extend the program to investigate the largest written address. I made sure not the change the original semantics; just added some.

```
make arrayAddr
./arrayAddr
```

We still get the segmentation fault. Now debug
```
gdb arrayAddr -x arrayAddr.gdb
```
