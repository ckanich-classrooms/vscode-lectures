# Position Independent Executables are now the default on most
# modern linux distributions, we need to disable this to show off
# absolute references
# https://stackoverflow.com/questions/43367427/32-bit-absolute-addresses-no-longer-allowed-in-x86-64-linux?noredirect=1&lq=1

CCOPTS = gcc -g -fno-pie -no-pie

example: *.c *.h
	$(CCOPTS) -O0 -g memlib.c mm.c example.c -o example
