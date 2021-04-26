#include <stdio.h>
#include <pthread.h>

unsigned next_seed = 1;

/* rand - return pseudorandom integer in the range 0..32767 */
unsigned rand(void)
{
    next_seed = next_seed * 1103515245 + 12543;
    return (unsigned)(next_seed >> 16) % 32768;
}

/* srand - set the initial seed for rand() */
void srand(unsigned new_seed)
{
    next_seed = new_seed;
}

void *call_rand(void *dontcare)
{
    rand();
    rand();
    rand();
    return NULL;
}

int main()
{
    pthread_t placeholder;
    srand(0);
    pthread_create(&placeholder, NULL, call_rand, NULL);
    pthread_join(placeholder, NULL);
    printf("%u\n", rand());
    printf("%u\n", rand());
    printf("%u\n", rand());
}
