#include <iostream>
#include "ziggurat.h"

// writing on a text file
using namespace std;


double modulo(double x, int a){
    double x2=x;
    while(x2>a){
        x2-=a;
    }
    return x2;
}


void begin() {
    ofstream myfile("example.txt");
    if (myfile.is_open())
    {
        cout << "heloo"<<endl;
        myfile << "This is a line.\n";
        myfile << "This is another line.\n";
        myfile.close();
    }
    else cout << "Unable to open file";
}

void ziggu()
{
    int n = 10000;
    int M = puis(2,32);
    int m = 21;
    LCG good_lcg(m,0,M);
    double (*f)(double x) = f_gauss;
    Ziggurat(100,*f).affiche();
    printf("...\n");
};

void polaire(int N){
    cout << 1 <<endl;
    int M = puis(2,28);
    int m = 21;
    LCG good_lcg(m,0,M);
    int M2 = puis(2,28);
    int m2 = 5;
    LCG other_good_lcg(m2,0,M2);
    cout << 1 <<endl;
    vector<double> v = generation_polaire(N, good_lcg, other_good_lcg);
    cout << 1 <<endl;
    ecrire(v,"polaire.txt");
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
    vector<double> v;
    for (int i = 0; i < N; i++) {
        cout<<i <<endl;
        v.push_back(F_genere_Z(z, N, f_gauss, good_lcg, other_good_lcg, seed1, seed2, seed3));
        //ecrire(v, "ziggurat.txt");
    }
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
    ecrire(coord1, "low_dis_1.txt");
    ecrire(coord2, "low_dis_2.txt");
}



int main(void){
    lowdiscrepancy(1000);
    return 0;
}

