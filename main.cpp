#include <iostream>
#include <climits>

#include "utils.h"
#include "ziggurat.h"
#include "twister.h"
// writing on a text file
using namespace std;


double modulo(double x, int a){
    double x2=x;
    while(x2>a){
        x2-=a;
    }
    return x2;
}

void corner_lcg(int N){
    int M = puis(2,28);
    int m = 21;
    LCG corner(m,0,M);
    int seed = 1;
    vector<double> x;
    vector<double> y;
    x.push_back(seed);
    for(int i=0; i< N; i++){
        x.push_back(corner.run_float(seed));
        y.push_back(x[x.size()-2]);
    }
    y.push_back(1);
    ecrire_r(x,"lcg_corner_x.txt");
    ecrire_r(y,"lcg_corner_y.txt");
}

void polaire(int N){
    cout << 1 <<endl;
    int M = puis(2,28);
    int m = 21;
    LCG good_lcg(m,0,M);
    int M2 = puis(2,28);
    int m2 = 5;
    LCG other_good_lcg(m2,0,M2);
    cout << 1 <<endl;
    vector<double> v = genere_box(N, good_lcg, other_good_lcg);
    cout << 1 <<endl;
    ecrire_r(v,"box.csv");
}

void zigutest(int N) {
    cout << 1 << endl;
    int M = puis(2, 28);
    int m = 21;
    LCG good_lcg(m, 0, M);
    int M2 = puis(2, 28);
    int m2 = 5;
    LCG other_good_lcg(m2, 0, M2);
    cout << F_integrale(f_gauss, 3.5, 1000) << endl;
    Ziggurat z(3.5, f_gauss);
    z.affiche();
    int seed1 = 1;
    int seed2 = 1;
    int seed3 = 1;
    double coef = 1/sqrt(2*pi);
    vector<double> v;
    for (int i = 0; i < N/2; i++) {
        v.push_back(F_genere_Z(z, N, f_gauss, good_lcg, other_good_lcg, seed1, seed2, seed3));
    }
    for (int i = 0; i < N/2; i++) {
        v.push_back(-F_genere_Z(z, N, f_gauss, good_lcg, other_good_lcg, seed1, seed2, seed3));
    }
    ecrire_r(v, "ziggurat.csv");
}

void lowdiscrepancy(int N){
    int dim =2;
    vector<double> nb_premier;
    nb_premier.push_back( modulo(sqrt(2),1));
    nb_premier.push_back( modulo(sqrt(3),1));
    LDS ad_rec(nb_premier);
    vector<double> coord1(1);
    vector<double> coord2(1);
    vector<double> point_actuel(2);
    for(int j=0;j<point_actuel.size();j++){
        cout << point_actuel[j]<<endl;
    }
    for(int k=0;k<N;k++){
        ad_rec.run_dim_n(point_actuel);
        coord1.push_back(point_actuel[0]);
        coord2.push_back(point_actuel[1]);
    }
    ecrire_r(coord1, "low_dis_1.txt");
    ecrire_r(coord2, "low_dis_2.txt");
}


void twisterM(int N){
    Initialize(1);
    vector<double> ordonne;
    vector<double> abscisse;
    abscisse.push_back(0);
    for(int i=0;i<N; i++){
        abscisse.push_back( double_t(ExtractU32())/(INT_MAX)/2);
        ordonne.push_back(abscisse[abscisse.size()-1]);
    }
    ordonne.push_back(abscisse[0]);
    ecrire_r(abscisse, "tw_x.csv");
    ecrire_r(ordonne, "tw_y.csv");
}


int main(void){
    lowdiscrepancy(1000);
    return 0;
}
