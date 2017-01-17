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

double f_gauss(double x) {
    return exp(-x * x)/(sqrt(2)*pi);
}

double f_1_gauss(double y) {
    return sqrt(-log(sqrt(2*pi)*y));
}
double (*pointeur2)(double a) = f_gauss;
///////////////////////////////

double F_integrale(double (*f)(double), double x,int n) {
    // intègre une fonction entre 0 et x selon la méthode des carrés inférieurs
    double value = 0;
    double pas =0;
    int j=0;
    for(int i=0; i<n; i++){
        j=j+1;
        value = value + f(pas)/n;
        pas = x*i/n;
    }
    return value;
}
void Ziggurat::affiche() {
        cout <<"C vaut : "<< C <<endl;
        cout <<"R vaut : "<< intervale  <<endl;
        cout <<"V vaut : "<< volume <<endl;
        cout <<" taille vaut : "<< table_x.size() << endl;
        cout <<"Les valeurs de x sont :"<<endl;

        for(int i=0; i< C; i++) {
            cout << table_x[i] << "|";
        }
    cout << endl;
}


vector<int> ziggurat(LCG l, int(*pointeur)(int[dimension])){
    return vector<int>(3);
}

Ziggurat::Ziggurat(double R, double (*f)(double)) {
    dim = 1;
    intervale = R;
    double V = f(R) * R + F_integrale(f, R, 1000);
    volume = V;
    double x = R;
    C = 0;
    while (x > 0) {
        C = C + 1;
        table_x.push_back(x);
        cout << x << "|" << C << endl;
        x = (V / table_x[C - 1] + f(table_x[C - 1]));
        if (x > 1/(2 * pi)) {
// le dernier x est la hauteur en fait.
            table_x.push_back(x);
            x=0;
        } else {
            x = sqrt(-log(2 * pi * x));
        }
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
    double u;
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



