# Lecture 5

0. expand the glibc-source file: `cd /usr/lib/glibc && tar xf glibc-2.27.tar.xz`
    This might take a while and will make your container bigger - don't load unless you're curious and/or have a fast machine and a not-almost-full hard drive.
1. set a breakpoint on `_start` using the + in the breakpoint tab
2. start debugging
3. see nothing
4. "step into" and you'll start seeing all the scaffolding.