to compare sizes/layouts with a statically linked version:

`gcc -static -g -fno-pie -no-pie helloworld.c -o helloworld.out`

to build:

`gcc -g -fno-pie -no-pie helloworld.c -o helloworld.out` (or run the vscode build task)

to see addresses for got, plt, etc:

`readelf -SW helloworld.out`

after running gdb:
`gdb helloworld.out`

break on main to let the program load:
`b main'

then take a look at the assembly of main:

`disas main`

we can look at the plt entries for printf:

`disas printf@plt`

gdb helpfully does the instruction pointer math and tells us that this line is jumping to the address stored at the address 0x601020 (which is the fourth entry in the plt GOT)

we can then take a look at what that value is:

`p/x *(void**)*0x601000` (or whatever the value is when yours is compiled)

that sends us to the next instruction! Which just pushes the "todo" onto the stack and calls the dynamic linker.

The dynamic linker then does its linking job, which is very similar to what `ld` does at build time for a statically linked executable - it resolves the symbol in the shared library, and then the result is an address to jump to to enter the `printf` function. It then does TWO things: it stores that value into the Global Offset Table (for the next time `printf` gets called) **and** it jumps to the entry point of `printf` as if it was actually what got called.

Thus, the next time the program gets to the next line of main, it will do an indirect jump again, but this time rather than pushing an additional argument onto the stack and executing the dynamic linker, it just goes to `printf` right away.

Important things to remember:
* The PLT is executable, which means that it isn't writeable! It's read-only instructions, but it's used to dynamically call different locations depending on whether the library function has been linked yet or not.
