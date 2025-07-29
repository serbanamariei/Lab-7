#ifndef FUNCTII_H_
#define FUNCTII_H_

double *citireVector(int n);
void afisare(double *a, int n);
double normaInfinit(double *a, int n);
double norma1(double *a, int n);
double norma2(double *a, int n);

int intersectie(double *inters, double *a, double *b, int ca, int cb);
int diferentaSim(double *difSim, double *a, double *b, int ca, int cb);
int reuniune(double *reuniune, double *a, double *b, int ca, int cb);
int exista(double *v, int n, double element);
char *transformareToAscii(long int numar);


#endif
