//
// Created by victor on 14/02/17.
//

#ifndef PROJET_MOPSI_UTILS_H
#define PROJET_MOPSI_UTILS_H

#include <stdint.h>
#include <stdio.h>
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

template<class Type> void ecrire_r(vector<Type> output,string name){
    ofstream myfile(name);
    myfile << "value";
    myfile << '\n';
    for(int i=0; i<output.size(); i++){
        myfile << output[i];
        myfile << '\n';
    }
    myfile.close();
}

template<class Type> void ecrire_python(vector<Type> output,string name){
    ofstream myfile(name);
    for(int i=0; i<output.size(); i++){
        myfile << output[i] <<","<<endl;
    }
    myfile << '\n';
    myfile.close();
}

#endif //PROJET_MOPSI_UTILS_H
