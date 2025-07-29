#include<stdio.h>
#include<stdlib.h>
#include"functii.h"

int *pcitireVector(int n)
{
	int *p=0;
	p=(int *)malloc(n*sizeof(int));
	if(0==p)
	{
		fprintf(stderr,"Memorie insuficienta\n");
		exit(EXIT_FAILURE);
	}

	for(int i=0;i<n;++i)
	{
		printf("v[%d] = ",i);
		scanf("%d",p+i);
	}

	return p;
}

void pafisareVectorIntregi(int *a, int n)
{
	printf("[");
	for(int i=0;i<n;++i)
	{
		printf(" %d",*(a+i));
	}
	printf(" ]");
}

void pafisareVectorReali(double *a, int n)
{
	printf("[");
	for(int i=0;i<n;++i)
	{
		printf(" %.2lf",*(a+i));
	}
	printf(" ]");
}

double sumaVectorReali(double *a, int n)
{
	double s=0;
	for(int i=0;i<n;++i) s+=*(a+i);
	return s;
}

double *vectorMedie(int *a, int *b, int n)
{
	double *vm=0;
	vm=(double *)malloc(n*sizeof(double));
	if(0==vm)
	{
		fprintf(stderr,"Memorie insuficienta\n");
		exit(EXIT_FAILURE);
	}
	for(int i=0;i<n;++i)
	{
		*(vm+i)=(*(a+i)+*(b+i))/2;
	}

	return vm;
}

double medieAritmeticaVector(double *a, int n)
{
	double ma=0;
	for(int i=0;i<n;++i)
	{
		ma+=*(a+i);
	}
	ma/=n;
	return ma;
}

double mediaAritmeticaIntregi(int a, int b)
{
	return (a+b)/2;
}
