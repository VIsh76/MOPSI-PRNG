//
// Created by victor on 08/01/17.
//

#ifndef PROJET_MOPSI_ZIGGURAT_H
#define PROJET_MOPSI_ZIGGURAT_H

#include "LCG.h"
#include <cmath>

double const pi = 3.14;
int const dimension=3;

#include <vector>
#include <iostream>
using namespace std;
class Ziggurat{
private:
    int C;
    int dim;
    int precision;
    double intervale;
    double volume;
    vector<double> table_x;
    vector<double> table_y;
public:
    Ziggurat(int C, double R, double V, double (*f)(double));
    int getC(){
        return C;
    }
    double getX(int a){
        return table_x[a];
    }
    double getY(int b){
        return table_y[b];
    }
};



vector<int> ziggurat(LCG l, int(*pointeur)(int[dimension]));
int funtest(int a[dimension]);
#endif //PROJET_MOPSI_ZIGGURAT_H
