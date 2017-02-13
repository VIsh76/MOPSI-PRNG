
//i à choisir aléatoirement compris entre 1 et N : un des N rectangles
//u contiendra le résultat
//f est la fonction de répartition de la loi (normale)

float f(float x)
{
	return exp(-x*x*0.5)/sqrt(2*pi);
}

float u;
    while (true)
    {
        if (i<N)
            u=LCG.run_n(seed,)*x[i]/LCG.mod;   //u=Uniforme(0,1) * x[i]
        else
            u=LCG.run_n(seed,)*V/(f(x[N])*LCG.mod);
        if (i<N && u<=x[i-1] || i==N&&u<=x[N]) // Rajouter x[-1]=0
            return u;
            //le résultat retourné est bien u tel que défini plus haut
        else
        {
        	if (i<N)
        	{
            float y1=f(x[i]) + (LCG.run_n(seed,)*x[i]/LCG.mod)*(f(x[i+1])-f(x[i]));
            if (y1<f(u))
                return u;
        	}
        	else
        	    while (true)
        	    {
        	        float U1 = LCG.run_n(seed,)/LCG.mod;
                    float U2 = LCG.run_n(seed,)/LCG.mod;
                    float X=-log(U1)/x[N];
                    float Y=-log(U2);
                    if (2*Y>X*X)
                        return X + x[N];
        	    }

        }
    }






/*
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


*/
