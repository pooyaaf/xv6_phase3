#include "types.h"
#include "stat.h"
#include "user.h"

int main(int argc, char* argv[])
{
    int pid[5];
    printf(1, "foo is runnig\n");
    for(int i = 0; i < 5; i++)
    {
        pid[i] = fork();
        if(pid[i] == 0)
        {
            for(long long int j = 0; j < 922337203685477580; j++)
            {
                long long int temp = 0;
                temp++;
            }
            exit();
        }
    }
    while(wait());
    printf(1, "foo terminated\n");
    exit();
}