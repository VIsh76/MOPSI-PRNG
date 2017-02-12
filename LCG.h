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
    double run_float(int&seed);
    vector<int> run_n(int seed, int n, bool print);
    float test_uniforme(int nb_test, int seed=0);
    int get_mod();
    int get_coeff();
    double segment_centre(int &seed,double longueur);
};

class LDS{
private:
    int dim;
    vector<double> alpha;

public:
    double get_alpha(int i){return alpha[i];}
    LDS(vector<double> a) {
        dim = a.size();
        for (int i = 0; i < dim; i++) {
            alpha.push_back(a[i]);
        }
    }
    void run_dim_1(double &seed, int i){
        seed+=alpha[i];
        if(seed >= 1){
            seed-=1;
        }
    }
    void run_dim_n(vector<double> &seedvect){
        for(int i =0; i<seedvect.size(); i++){
            cout << seedvect[i];
            run_dim_1(seedvect[i], i);
            cout << seedvect[i];
        }
    }
};


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
void ecrire(vector<double> output, string name);
#endif //PROJET_MOPSI_LCG_H