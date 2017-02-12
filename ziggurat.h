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
    double (*loi)(double);
public:
    Ziggurat(double R, double (*f)(double));
    int getC(){
        return C;
    }
    double getX(int a){
        return table_x[a];
    }
    double getY(int b){
        return table_y[b];
    }
    void affiche();
    double calcul(double x){
        return loi(x);
    }
};

// Pour le calcul de la ziggurat :
double F_integrale(double (*f)(double), double x,int n);


double f_1_gauss(double y);
double f_gauss(double x);
vector<int> ziggurat(LCG l, int(*pointeur)(int[dimension]));
int funtest(int a[dimension]);
double F_genere_Z(Ziggurat Z,int nb_generation,double (*f)(double), LCG X, LCG U,int& seed1,int& seed2,int& seed3);


// GENERATION POLAIREE
vector<double> generation_polaire(int N, LCG A, LCG B);
void box_muller(LCG A, LCG B, int &seed1, int &seed2, double &norm1, double &norm2);
vector<double> generation_polaire(int N, LCG A, LCG B);
vector <double> genere_box(int N, LCG A, LCG B);
#endif //PROJET_MOPSI_ZIGGURAT_H

