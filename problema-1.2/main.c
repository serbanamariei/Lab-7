#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"functii.h"

int main()
{
	int n;
	unsigned int c;
	printf("Valoarea initiala a numarului de celule din cultura: ");
	scanf("%u",&c);
	printf("Numarul de zile de observare a culturii: ");
	scanf("%d",&n);
	
	printf("Numarul de celule:\n");
	unsigned int *cel=(unsigned int *)malloc(n*sizeof(unsigned int));
	if(cel==0)
	{
		fprintf(stderr,"Memorie insuficienta\n");
		exit(EXIT_FAILURE);
	}
	pcitireVectorInt(cel,n);
	
	double *vr=vectorRata(cel,c,n);
	double mg=medieGeo(vr,n);

	printf("Valoarea initiala a numarului de celule din cultura: %d\n",c);
	printf("Numarul de zile de observare a culturii: %d\n",n);
	printf("Numarul de celule: ");
	pafisareVectorInt(cel,n);
	printf("\n\n");
	printf("Rata zilnica de modificare: ");
	pafisareVectorDouble(vr,n);
	printf("\nMedia geometrica: %.3lf\n",mg);
	printf("Rata medie de modificare: %.3lf\n",rataMedie(vr,n));

	memset(cel,0,n*sizeof(unsigned int));
	free(cel);
	cel=0;
	memset(vr,0,n*sizeof(double));
	free(vr);
	vr=0;

	return 0;
}
