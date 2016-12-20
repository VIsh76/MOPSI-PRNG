//
// Created by victor on 07/12/16.
//

#include "LCG.h"


int jsw_lcg(int seed)
{
    return  (2 * seed + 3) % 10;
}

int LCG::run(int seed){
    seed= coeff * (seed % Q) - R * (seed / Q);
    if (seed < 0)
    {
        seed += mod;
    }
    return seed;
}

vector<int> LCG::run_n(int seed, int n) {
    vector<int> output(n);
    for(int i=0; i<n;i++){
        output[i]=run(seed);
    }
    return output;
};

//float LCG::test_uniforme(int nb_test, int seed=0){
//    vector<int> output = run_n(seed,nb_test);
//}