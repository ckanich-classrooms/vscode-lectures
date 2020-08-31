#include <stdio.h>

int not_defined_here;
char message[] = "hello world";
static int invocations = 0;

void hello_world(int increment)
{
    int i;
    static int first_time = 0;
    for (i = 0; i < increment; i++)
    {
        puts(message);
        invocations++;
    }
    fprintf(stderr, "I have printed to the screen %d times.\n", invocations);
    if (first_time == 0)
    {
        first_time++;
        hello_world(1);
    }
    else
        first_time++;
}

int main()
{
    hello_world(2);
}