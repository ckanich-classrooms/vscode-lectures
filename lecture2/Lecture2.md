# Lecture 2

## run the preprocessor

`gcc -E main.c -o main.i`

## run the compiler

Generate text-based assembly code:

`gcc main.c -S -o main.S`

Generate ELF object files:

`gcc -c main.c`

## inspect the ELF object file

`hexdump -C main.o`

## dump the ELF object file to screen

`objdump -d main.o`

## compile and link the final executable

`gcc -o lecture2 sum.c main.c`



### Debug within libc?

Would you like to see what libc is doing when debugging? You'll need the glibc source. As of this writing, the correct way to add it is:

* extract the glibc source files (provided in the container) -
  `tar xf /usr/src/glibc/glibc-2.23.tar.xz`
* add this stanza to `setupCommands` in `launch.json` so that gdb can find the source files:
```json

                {
                    "description": "Fix location of glibc source",
                    "text": "set substitute-path /build/glibc-LK5gWL /usr/src/glibc",
                    "ignoreFailures": false
                }
```