# loading into memory

`readelf -lW helloworld.out` will show the Program headers, which are the instructions to the loader to bring the entire program into memory.

to print a pointer in gdb, the value must be cast to something that gdb can interpret as a pointer, e.g.:

`p/x *(void**)0x601018`


The only thing in .init of our hello world is a test call to see whether we should be using the gprof profiler - if we are, the .init function needs to do whatever the profiler needs to do before your program starts. Usually it won't do anything.

To see the `_start` function in action, run the "Launch lecture 5" command from the debugging menu, set a breakpoint at _start (manually in the lower left hand corner), and run a "step into" command (to get out of the hand-written assembly and into the compiled-from-c `__libc_start_main`).