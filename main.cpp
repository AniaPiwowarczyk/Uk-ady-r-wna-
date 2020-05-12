#include <stdio.h>
#include <math.h>
#include "winbgi2.h"
#include "rk4.h"

void Euler( double x0, double y0[], double h, int n, void (*fun)(double, double*, double*), double y1[] );
void vrk4( double x0, double y0[], double h, int n, void (*fun)(double, double*, double*), double y1[] );
void rhs_fun( double t, double *X, double *Ywynik);


double k =1.4;
double g=9.81;
double l= 2;
double alfa=5;
double A=5;
double omega=1;

void main()
{	double fi0=alfa*3.14/180.;// kat w radianach
	double omega0=0.0;
	double X[2]={ fi0, omega0};
	double Ywynik[2];

	graphics(1200, 600);
	scale(0,-10, 10, 10);// do wykresu
	line(0,0,20,0);
	for( double t=0; t<10.5; t+=0.2)
	{
		vrk4(t, X, 0.04, 2, rhs_fun, Ywynik);
		printf(" %lf \t %lf\n", Ywynik[0]*180/3.14, Ywynik[1]);//kat i omega(metoda rk4)
		X[0]=Ywynik[0];
		X[1]=Ywynik[1];
		circle(t, Ywynik[0]*180/3.14, 1);
		circle(t, Ywynik[1], 2);

	}
	X[0]=fi0;
	X[1]=omega0;
	double Ywynik1[2];
	for( double t=0; t<10.5; t+=0.2)
	{
		Euler(t, X, 0.04, 2, rhs_fun, Ywynik1);
		X[0]=Ywynik1[0];
		X[1]=Ywynik1[1];
		printf("\t\t%lf\t%lf\n", Ywynik1[0]*180/3.14, Ywynik1[1]);// kat i omega (metoda Eulera)
		setcolor(0.99);
		circle(t, Ywynik1[0]*180/3.14, 1);
		circle(t, Ywynik1[1], 2);

	}
	wait();
}

void rhs_fun( double t, double *X, double *F)
{
	F[0]= X[1];
	F[1]=-k*X[1]-(g / l)*sin(X[0])+A*cos(omega*t);
	
	

}
