#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include"functii.h"

void pcitireVectorInt(unsigned int *a, int n)
{
	for(int i=0;i<n;++i)
	{
		printf("v[%d] = ",i);
		scanf("%u",a+i);
	}
}

void pafisareVectorInt(unsigned int *a, int n)
{
	printf("(");
	for(int i=0;i<n;++i)
	{
		printf(" %u",*(a+i));
	}
	printf(" )\n");
}

double *vectorRata(unsigned int *a, unsigned int c, int n)
{
	double *vr=0;
	vr=(double *)malloc(n*sizeof(double));
	if(vr==0)
	{
		fprintf(stderr,"Memorie insuficienta\n");
		exit(EXIT_FAILURE);
	}
	*vr=(double)*a/(double)c;
	for(int i=1;i<n;++i)
	{
		*(vr+i)=(double)*(a+i);
		*(vr+i)/=(double)*(a+i-1);
	}

	return vr;
}

void pafisareVectorDouble(double *a, int n)
{
	printf("(");
	for(int i=0;i<n;++i)
	{
		printf(" %.3lf",*(a+i));
	}
	printf(" )");
}

double medieGeo(double *a, int n)
{
	double mg=1;
	for(int i=0;i<n;++i) mg*=*(a+i);
	return pow(mg,(double)1/(double)n);
}

double rataMedie(double *a, int n)
{
	double rm=0;
	for(int i=0;i<n;++i) rm+=*(a+i);
	return rm/(double)n;
}
