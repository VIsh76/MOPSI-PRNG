//
// Created by victor on 08/01/17.
//

#ifndef PROJET_MOPSI_ZIGGURAT_H
#define PROJET_MOPSI_ZIGGURAT_H

#include "LCG.h"
int const dimension=3;

#include <vector>
#include <iostream>
using namespace std;
class Ziggurat{
private:
    int dim;
    int precision;
    float intervale;
    vector<float> table;
public:
    Ziggurat(int precision, float interval, float(*f)(float) );

};



vector<int> ziggurat(LCG l, int(*pointeur)(int[dimension]));
int funtest(int a[dimension]);
#endif //PROJET_MOPSI_ZIGGURAT_H
