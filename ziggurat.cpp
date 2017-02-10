//
// Created by victor on 08/01/17.
//



#include <assert.h>
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
    cout <<"Les valeurs de y sont :"<<endl;
    for(int i=0; i< C; i++) {
        cout << table_y[i] << "|";
    }
    cout << endl;
}


vector<int> ziggurat(LCG l, int(*pointeur)(int[dimension])){
    return vector<int>(3);
}


Ziggurat::Ziggurat(double R, double (*f)(double)) {
    dim = 1;
    loi = f;
    intervale = R;
    double V = f(R) * R + F_integrale(f, R, 1000);
    volume = V;
    double x = R;
    C = 0;
    double f_0 = f(0);
    while (x > 0) {
        C = C + 1;
        table_x.push_back(x);
        table_y.push_back(f(x));
        x = (V / table_x[C - 1] + f(table_x[C - 1]));
        if (x > f_0) {
// le dernier x est la hauteur en fait.
            table_y.push_back(x);
            table_x.push_back(0);
            x=0;
        } else {
            //Prend l'inverse
            x = sqrt(-log(2 * pi * x));
        }
    }
}

int convert_LCG_Zigg(int resultat_lcg, int nb_rec, int mod){
// Renvoie un entier entre 1 et C;
    cout << "Convert :" << 1+int(resultat_lcg*nb_rec/mod) << "C : "<< nb_rec<<endl;
    return 1+int(resultat_lcg*nb_rec/mod);
};

// dR la limite basse de f
// mieux vaut prendre M de lcg un multiple de C;
double F_genere_Z(Ziggurat Z, LCG X, LCG U) {
    int M = X.get_mod();
    int C = Z.getC();
    double R = Z.getX(C-1);
    int seed1 = 1;
    int seed2 = 1;
    int indice = M / C;
    double x_rec = -50;
    double y_rec = -50;
    double u;
    indice = convert_LCG_Zigg(U.run(seed1), C, U.get_mod());
    // Génération de x_i uniforme dans le rectangle de gauche
    if (indice < C) {
        x_rec = X.run(seed2) / X.get_mod() * Z.getX(indice);
    } else {
        assert(indice == C);
//       x_rec = X.run(seed2)/X.get_mod()*Z.getX(indice);
    }
// Vérification de la condition
    if (x_rec <= Z.getX(indice - 1)) {
        return x_rec;
    } else {// Regarde la hauteur avec rejection
        if (indice == C) {
            cout << "Cas indice=C" << endl;
            return 0;
        } else {
            // On génère un y et on applique la méthode du rejet
            y_rec = (X.run(seed2) / X.get_mod()) * (Z.getY(indice) - Z.getY(indice + 1)) + Z.getY(indice);
            cout << "y_rec = " << y_rec << endl;
            if (y_rec < Z.calcul(x_rec)) {
                cout << "Aceptation par Y" << endl;
                return x_rec;
            }
        }
    }
    if (indice == C){
        //Marsaglia’s method
        double X0 = 0;
        double Y0 = 0;
        double U1, U2;
        while (X0 * X0 >= -2 * Y0) {
            U1 = X.run(seed1) / X.get_mod();
            U2 = X.run(seed1) / X.get_mod();
            X0 = log(U1) / R;
            Y0 = log(U2);
        }
        return X0+R;
    }
}
//TESTER
vector<double> generation_polaire(int N, LCG A, LCG B) {
    int seed1 =  0;
    int seed2 = 0;
    double r,z,x,y;
    int n = 0;
    int nb_essaie =0;
    vector<double> v;
    while(n < N){
        nb_essaie +=1;
        x=A.segment_centre(seed1,2);
        y=B.segment_centre(seed2,2);
        r = x*x+y*y;
        if(r<=1){
            z = (sqrt(-4*log(r))/log(r));
            v.push_back(x*z);
            v.push_back(y*z);
            n+=2;
        }
    }
    return v;
}

vector<double > box_muller(int N, LCG A, LCG B){
    int seed1 =  0;
    int seed2 = 0;
    double r,z,u1,u2;
    int n = 0;
    int nb_essaie = 0;
    vector<double> v;
    while(n < N){
        u1=A.run(seed1);
        u2=B.run(seed2);
        v.push_back(sqrt(-2*log(u1))*cos(2*pi*u2));
        v.push_back(sqrt(-2*log(u2))*cos(2*pi*u1));
        n+=2;
    }
    return v;
}

