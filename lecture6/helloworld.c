#include <unistd.h>
#include <string.h>
#include <sys/syscall.h>

    const char greeting [] = "hello world!\n";
int main(){
    // write(1,greeting,13);
    syscall(SYS_write,1,greeting,13);
}