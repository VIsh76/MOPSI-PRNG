//
// Created by victor on 08/01/17.
//



#include "ziggurat.h"



//////////Pointeurs de fonctions///////
int funtest(int a[dimension]){
    return a[0];
}

int(*pointeur)(int[dimension]) = funtest;

//////////////////////

///////////////////Loi Normale/////////////

double f_gaus(double x) {
    return exp(-x * x)/(sqrt(2)*pi);
}

double f_1_gaus(double y) {
    return sqrt(-log(sqrt(2*pi)*y));
}
///////////////////////////////


vector<int> ziggurat(LCG l, int(*pointeur)(int[dimension])){
    return vector<int>(3);
}

Ziggurat::Ziggurat(int C, double R, double V, double (*f)(double)) {
    dim = 1;
    intervale = R;
    volume = V;
    vector<double>table_x(C+1);
    vector<double>table_y(C+1);
    table_x[0]=V/f(R);
    table_x[1]=R;
    table_x[C]=0;
    for(int i =2; i< C; i++){
        table_x[i] = sqrt(-2 * log(V / table_x[i-1] + f(table_x[i-1])));
    }
    for(int i=0; i<precision; i++){
        table_y[i] = table_x[i + 1] / table_x[i];
    }
}

//int convert_LCG_in_1_N(k_sur_m);

// dR la limite basse de f
// mieux vaut prendre M de lcg un multiple de C;
double F_genere_Z(Ziggurat Z, LCG lcg){
    int C=Z.getC();
    A=lcg.run();
}