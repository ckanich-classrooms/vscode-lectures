#include <stdio.h>

int not_defined_here;
int everyone_can_touch_this = 42;
static int only_i_can_touch_this = 43;

void hello_world(int increment){
    int i;
    static int invocations = 0;
    char message [] = "hello, world\n";
    for(i = 0; i < increment; i++){
        puts(message);
        invocations++;
    }
    fprintf(stderr,"hello_world has now printed its message %d times.\n",invocations);
}

int main(){
    hello_world(1);
    hello_world(4);
}