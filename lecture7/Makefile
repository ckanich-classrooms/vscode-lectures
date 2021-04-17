all: test_fork test_spawn fork spawn execv

test_fork: test_fork.c
	gcc -Wall -o test_fork test_fork.c

test_spawn: test_spawn.c
	gcc -Wall -o test_spawn test_spawn.c

execv: execv.c
	gcc -Wall -o execv execv.c

fork: fork.c
	gcc -Wall -o fork fork.c

spawn: spawn.c
	gcc -Wall -o spawn spawn.c

clean:
	rm fork spawn test_fork test_spawn execv