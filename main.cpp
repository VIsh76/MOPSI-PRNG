#include <iostream>
#include "ziggurat.h"

int main(void)
{
    int seed = 2;
    int i;
    LCG lcg1(3,0,19);
    int a[dimension]={1,1,1};
    cout<< (ziggurat(lcg1,funtest))[0]<<endl;
    printf("...\n");

    return 0;
}