#include "types.h"
#include "user.h"

int main(int argc, char *argv[])
{
    if (argc < 3)
    {
        printf(1, "not enough arguments!");
        return -1;
    }
    changeQueue(atoi(argv[1]), atoi(argv[2]));

    printf(1, "changed queue of pid:%d  to queue level:%d\n", atoi(argv[1]), atoi(argv[2]));
    exit();
}