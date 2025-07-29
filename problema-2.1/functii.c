#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include"functii.h"

double *citireVector(int n)
{
	double *v=0;
	v=(double *)malloc(n*sizeof(double));
	if(v==0)
	{
		fprintf(stderr,"Memorie insuficienta\n");
		exit(EXIT_FAILURE);
	}
	for(int i=0;i<n;++i)
	{
		printf("v[%d] = ",i);
		scanf("%lf",v+i);
	}

	return v;
}

void afisare(double *a, int n)
{
	printf("{");
	for(int i=0;i<n-1;++i)
	{
		printf("%.2lf, ",*(a+i));
	}
	printf("%.2lf}\n",*(a+n-1));
}

double normaInfinit(double *a, int n)
{
	double ni=fabs(*a);
	for(int i=1;i<n;++i)
	{
		if(fabs(*(a+i))>ni) ni=fabs(*(a+i));
	}

	return ni;
}

double norma1(double *a, int n)
{
	double n1=0;
	for(int i=0;i<n;++i) n1+=fabs(*(a+i));
	return n1;
}

double norma2(double *a, int n)
{
	double n2=0;
	for(int i=0;i<n;++i) n2+=fabs(*(a+i))*fabs(*(a+i));
	return sqrt(n2);
}
