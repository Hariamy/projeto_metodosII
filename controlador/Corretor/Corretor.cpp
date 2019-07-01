#include "Corretor.h"

double Corretor(double x0, double y0, double xf, int particoes, estado::estado){ 
    //x0 = 0
    //y0 = 2
    //xf = 1
    //n = 11

    double deltax = (xf-x0)/(particoes);

    double x[particoes];

    double acumulador = x0

    //x = np.linspace(x0,xf,n)

    for(int i=0; i<particoes; i++){
        x[i] = acumulador;
        acumulador = acumulador + deltax;
    }

    //def f(x,y):
    //    return y-x

    //y = np.zeros([n])
    double y[particoes];

    y[0] = y0;

    
    //for i in range(0,4):
    //    py[i] = None

    //for i in range(1,4):
    for(int i = 1; i<4 ; i++){
        double k1 = deltax*f(x[i-1], y[i-1]);
        double k2 = deltax*f(x[i-1] + deltax/2, y[i-1]+k1/2);
        double k3 = deltax*f(x[i-1] + deltax/2, y[i-1]+k2/2);
        double k4 = deltax*f(x[i-1] + deltax, y[i-1]+k3);
        y[i] =  y[i-1] + (k1 + 2*k2 + 2*k3 + k4)/6;
    }

    //py = np.zeros([n])
    //double py[particoes];
    double py;

    //for i in range(4,n):
    for(int i = 4; i<particoes; i++){
        py[i] = deltax/24*(55*f(x[i-1],y[i-1]) - 59*f(x[i-2],y[i-2]) + 37*f(x[i-3],y[i-3]) - 9*f(x[i-4],y[i-4]) )  + y[i-1] 
        y[i] = deltax/24*( 9*f(x[i],py) + 19*f(x[i-1],y[i-1]) - 5*f(x[i-2],y[i-2]) + f(x[i-3],y[i-3]) ) + y[i-1]
    }
    
    return y[particoes - 1];
}
