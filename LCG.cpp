//
// Created by victor on 07/12/16.
//

#include "LCG.h"


int LCG::run(int &seed){
    seed= coeff * (seed % Q) - R * (seed / Q);
    if (seed < 0)
    {
        seed += mod;
    }
    return seed;
}

vector<int> LCG::run_n(int seed, int n, bool print) {
    vector<int> output(n);
    for(int i=0; i<n;i++) {
        output[i] = run(seed);
    }
    if(print){
        ecrire(output, "exemple.txt");
        cout <<endl;
    }
    return output;
}

int LCG::get_coeff() {
    return coeff;
}

int LCG::get_mod() {
    return mod;
}

double LCG::segment_centre(int &seed, double longueur) {
    run(seed);
    return (seed*longueur)/mod - longueur/2;
}


//float LCG::test_uniforme(int nb_test, int seed=0){
//    vector<int> output = run_n(seed,nb_test);
//}

int puis(int a, int k){
    int res=1;
    for(int i=0; i<k; i++) {
        res = res * a;
    }
    return res;
}
// Ecrire dans un doc

void ecrire(vector<int> output, string name){
    ofstream myfile(name);
    for(int i; i<output.size(); i++){
        cout << output[i]<<endl;
        myfile << output[i] << ";";
    }
    myfile << '\n';
    myfile.close();
}
