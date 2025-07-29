#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"functii.h"

int main()
{
	int n;
	printf("nr elemente = ");
	scanf("%d",&n);

	double *v=citireVector(n);
	printf("v = ");
	afisare(v,n);

	printf("norma infinit = %.2lf\n",normaInfinit(v,n));
	printf("norma 1 = %.2lf\n",norma1(v,n));
	printf("norma 2 = %.2lf\n",norma2(v,n));
	
	memset(v,0,n*sizeof(double));
	free(v);
	v=0;

	return 0;
}
