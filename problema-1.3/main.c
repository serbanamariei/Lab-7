#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"functii.h"

int main()
{
	int n;
	printf("n = ");
	scanf("%d",&n);

	int *A=citireVectorInt(n);
	printf("A = ");
	afisVectorInt(A,n);
	
	printf("\nw = ");
	int *w=wvector(A,n);
	afisVectorInt(w,n);
	printf("\n");

	printf("Nr cu cea mai mare suma a cifrelor sale: %d\n",*(A+maximVector(w,n)));

	memset(A,0,n*sizeof(int));
	free(A);
	A=0;

	memset(w,0,n*sizeof(int));
	free(w);
	w=0;

	return 0;
}
