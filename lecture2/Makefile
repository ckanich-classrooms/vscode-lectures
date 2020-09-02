# Position Independent Executables are now the default on most
# modern linux distributions, we need to disable this to show off
# absolute references
# https://stackoverflow.com/questions/43367427/32-bit-absolute-addresses-no-longer-allowed-in-x86-64-linux?noredirect=1&lq=1

CCOPTS = gcc  -fno-pie -no-pie

main: main.c sum.o
	$(CCOPTS) -c main.c
	$(CCOPTS) -o main main.o sum.o

sum.o: sum.c sum.h
	$(CCOPTS) -c sum.c

libsum.a: sum.o
	ar r libsum.a sum.o
	ranlib libsum.a

main_broken: libsum.a main.c
	$(CCOPTS) -L. -lsum -o main_broken main.c

main_fixed: libsum.a main.c
	$(CCOPTS) main.c -L. -o main_fixed -lsum

clean:
	rm -f *.a *.o a.out weaksymbols main_broken main_fixed libsum.a

weaksymbols: weakmain.c weaklibrary.c
	$(CCOPTS) -c weakmain.c
	$(CCOPTS) -c weaklibrary.c
	$(CCOPTS) -o weaksymbols weakmain.o weaklibrary.o