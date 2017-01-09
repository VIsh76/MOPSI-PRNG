#include <iostream>
#include "ziggurat.h"



// writing on a text file
using namespace std;

//int main () {
//    ofstream myfile("example.txt");
//    if (myfile.is_open())
//    {
//        cout << "heloo"<<endl;
//        myfile << "This is a line.\n";
//        myfile << "This is another line.\n";
//        myfile.close();
//    }
//    else cout << "Unable to open file";
//    return 0;
//}

int main(void)
{
    int n = 10000;
    int M = puis(2,30);
    int m = 21;
    LCG good_lcg(m,0,M);
    printf("...\n");
    return 0;
};