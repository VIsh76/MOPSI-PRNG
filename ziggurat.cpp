//
// Created by victor on 08/01/17.
//


#include "ziggurat.h"

int funtest(int a[dimension]){
    return a[0];
}

int(*pointeur)(int[dimension]) = funtest;

vector<int> ziggurat(LCG l, int(*pointeur)(int[dimension])){
    return vector<int>(3);
}
