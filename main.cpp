#include <iostream>
#include "LCG.h"

int main(void)
{
    int seed = 3;
    int i;
    LCG lcg1(5,2,12);
    for (i = 0; i < 10; i++)
    {
        printf("%d ", seed);
        seed = lcg1.run(seed);
    }

    printf("...\n");

    return 0;
}