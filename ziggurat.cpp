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

int convert_LCG_Zigg(int resultat_lcg, int nb_rec, int mod){
    return int(mod/nb_rec);
};

// dR la limite basse de f
// mieux vaut prendre M de lcg un multiple de C;
double F_genere_Z(Ziggurat Z, LCG X, LCG U, int nb_generation){
    int M = X.get_mod();
    int C=Z.getC();
    int seed1 = 1;
    int seed2 =1;
    int i = M/C;
    float u;
    for(int _res=0; _res < nb_generation;_res++){
        i = convert_LCG_Zigg(X.run(seed1), C, M);
        if(i<C){
            u = Z.getX(i)*U.run(seed2)/M;
        }
        if(Z.getX(i-1)>u) {
            cout << u << endl;
        }
    }
}



