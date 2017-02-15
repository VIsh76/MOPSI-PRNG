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
    return exp(-x * x/2);
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

    for(int i=0; i< C+1; i++) {
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
    double V = f(R) * R + (1-0.99977)*sqrt(2*pi);
    volume = V;
    double x = R;
    double z = f(x);
    C = 0;
    while( x > 0 ){
        C = C + 1;
        table_x.push_back(x);
        z = (V / table_x[C - 1] + f(table_x[C - 1]));
//        cout << x << "|" << z << endl;
        if (z > 1) {
            //table_x.push_back(z);
            x=0;
        } else {
            x = sqrt(-2*log(z));
        }
//        cout << "X = "<< x <<endl;
    }
    table_x.push_back(0); //rectangle nul, pour le cas "tout en haut"
}

int convert_LCG_Zigg(int resultat_lcg, int nb_rec, int mod){
    return int(double(resultat_lcg)/mod*nb_rec);
};

// dR la limite basse de f
// mieux vaut prendre M de lcg un multiple de C;
double F_genere_Z(Ziggurat Z,int nb_generation,double (*f)(double), LCG X, LCG U,int& seed1,int& seed2,int& seed3){
    int C=Z.getC();
    int i = 0;
    double x;
    double y;
    for(int _res=0; _res < nb_generation;_res++){
        while(true){
//            cout << X.run(seed1) <<endl;
            i = convert_LCG_Zigg(X.run(seed1), C, X.get_mod());
            if(i>0){
                x = Z.getX(i-1)*U.run(seed2)/U.get_mod();
                if(x<=Z.getX(i))
                return x;
                else{
                    y=f(Z.getX(i-1)) + (U.run(seed3)/U.get_mod())*(f(Z.getX(i))-f(Z.getX(i-1)));
                    if (y<f(x))
                        return x;
                }
            }
            else{
                cout<< i <<endl;
                while (true){
                    x=-log(U.run_float(seed2))/Z.getX(0);
                    y=-log(U.run_float(seed3));
                    if (2*y>x*x)
                        return x+Z.getX(0);
                }
            }
        }
    }
}

//TESTER
vector<double> generation_polaire(int N, LCG A, LCG B) {
    int seed1 = 1;
    int seed2 = 1;
    double r,z,x,y;
    int n = 0;
    int nb_essaie =0;
    vector<double> v;
    while(n < N){
        nb_essaie +=1;
        x=A.segment_centre(seed1,2);
        y=B.segment_centre(seed2,2);
        cout << x << "-"<< y << endl;
        r = x*x+y*y;
        if(r<=1){
            z = (sqrt(-2*log(r))/log(r));
            v.push_back(x*z);
            v.push_back(y*z);
            n+=2;
        }
    }
    return v;
}

vector <double> genere_box(int N, LCG A, LCG B){
    int seed1=1;
    int seed2=1;
    double u1 = A.run(seed1);
    double u2 = B.run(seed2);
    vector<double> v;
    for(int i=0; i<N/2;i++){
        u1 = (A.run_float(seed1));
        u2 = (B.run_float(seed2));
        v.push_back(sqrt(-2 * log(u1)) * cos(2 * pi * u2));
        v.push_back(sqrt(-2 * log(u2)) * cos(2 * pi * u1));
    }

    return v;
}



