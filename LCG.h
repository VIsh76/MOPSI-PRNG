//
// Created by victor on 07/12/16.
//

#ifndef PROJET_MOPSI_LCG_H
#define PROJET_MOPSI_LCG_H

#include <stdio.h>
#include <iostream>
#include <vector>
#include <fstream>


using namespace std;

int jsw_lcg(int seed);
class LCG {
private:
    int mod ;
    int coeff;
    int reste;
    int R;
    int Q;
public:
    LCG(int a,int b, int m){
        coeff=a;
        reste=b;
        mod=m;
        Q = m/a;
        R = m%a;
    }
    int run(int& seed);
    vector<int> run_n(int seed, int n, bool print);
    float test_uniforme(int nb_test, int seed=0);
};

//
//    if (myfile.is_open())
//    {
//        cout << "heloo"<<endl;
//        myfile << "This is a line.\n";
//        myfile << "This is another line.\n";
//        myfile.close();
//    }
//    else cout << "Unable to open file";
//    return 0;


int puis(int a,int b);
void ecrire(vector<int> output, string name);
#endif //PROJET_MOPSI_LCG_H
