#include<stdio.h>
#include<stdlib.h>
#include"functii.h"

int *citireVectorInt(int n)
{
	int *p=0;
	p=(int *)malloc(n*sizeof(int));
	if(p==0)
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

void afisVectorInt(int *a, int n)
{
	printf("(");
	for(int i=0;i<n;++i)
	{
		printf(" %d",*(a+i));
	}
	printf(" )");
}

int sumaCifre(int a)
{
	int s=0;
	while(a)
	{
		s+=a%10;
		a/=10;
	}
	return s;
}

int *wvector(int *v, int n)
{
	int *w=0;
	w=(int *)malloc(n*sizeof(int));
	if(w==0)
	{
		fprintf(stderr,"Memorie insuficienta\n");
		exit(EXIT_FAILURE);
	}
	for(int i=0;i<n;++i)
	{
		*(w+i)=sumaCifre(*(v+i));
	}

	return w;
}

int maximVector(int *v, int n)
{
	int max=0,i;
	for(i=1;i<n;++i)
	{
		if(*(v+i)>*(v+max)) max=i;
	}

	return max;
}
