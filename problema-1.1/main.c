#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"functii.h"

int main()
{
	int n;
	printf("nr zile = ");
	scanf("%d",&n);
	printf("Introduceti temperaturile masurate la ora 5:\n");
	int *tempMIN=pcitireVector(n);
	printf("\nIntroduceti temperaturile masurate la ora 17:\n");
	int *tempMAX=pcitireVector(n);

	double *tempMED=vectorMedie(tempMIN,tempMAX,n);	
	printf("Vectorul cu temperaturi minime:\n");
	pafisareVectorIntregi(tempMIN,n);
	printf("\nVectorul cu temperaturi maxime:\n");
	pafisareVectorIntregi(tempMAX,n);
	printf("\nVectorul cu temperaturile medii:\n");
	pafisareVectorReali(tempMED,n);
	printf("\nTemperatura medie a temperaturilor medii: %.2lf\n",medieAritmeticaVector(tempMED,n));

	memset(tempMIN,0,n*sizeof(int));
	free(tempMIN);
	tempMIN=0;

	memset(tempMAX,0,n*sizeof(int));
	free(tempMAX);
	tempMAX=0;

	memset(tempMED,0,n*sizeof(int));
	free(tempMED);
	tempMED=0;

	return 0;
}
