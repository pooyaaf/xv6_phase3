#include "types.h"
#include "user.h"

int main(int argc, char *argv[])
{
    int pid;
    for(int i = 0; i < 5; i++){
        if((pid = fork()) == 0){
            for(;;){
                sleep(i);
            }
        }
    }
    wait();
    exit();
}