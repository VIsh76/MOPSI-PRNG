
//u à initialiser à N zéros
for (int i=0;i<=N;i++)
{
    if (i<N)
        u[i]=LCG.run_n(seed,)*x[i]/LCG.mod;
    else
        u[i]LCG.run_n(seed,)*V/(f(x[N]*LCG.mod);
    if (u[i]<=x[i-1]) // Rajouter x[-1]=0
        //Ne rien faire
    else
    {
        if (i==N)
        {
        //Marsaglia’s method
        float X=0;
        float Y=0;
        float U1,U2;
        while (X*X>=-2*Y)
        {
            U1 = LCG.run_n(seed,)/LCG.mod;
            U2 = LCG.run_n(seed,)/LCG.mod;
            X=log(U1)/a;
            Y=log(U2)/a;
        }
            // Et là si j’ai bien compris : si X^2 < -2Y, on renvoie a-X, et sinon on recommence ???
            /*Dernier truc : on a la densité de X dans la diapo EN HAUT ; pourtant en bas on nous dit de la calculer. Différence ???*/
