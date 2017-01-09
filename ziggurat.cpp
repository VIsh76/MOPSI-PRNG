//
// Created by victor on 08/01/17.
//


#include "ziggurat.h"

Pointeurs de fonctions
/////////////////////////////
int funtest(int a[dimension]){
    return a[0];
}

int(*pointeur)(int[dimension]) = funtest;

//////////////////////


vector<int> ziggurat(LCG l, int(*pointeur)(int[dimension])){
    return vector<int>(3);
}

Ziggurat::Ziggurat(int precision, float interval, float (*f)(float)) {
    dim = 1;
    interval = interval;
    precision = precision;
    for(int i=0; i<precision; i++){
    }
}
