#include <iostream>
#include "LCG.h"

int main(void)
{
    int seed = 2;
    int i;
    LCG lcg1(3,0,19);
    for (i = 0; i < 20; i++)
    {
       seed=lcg1.run(seed);
        cout << "bonne méthode : "<< seed <<endl;
    }

    printf("...\n");

    return 0;
}