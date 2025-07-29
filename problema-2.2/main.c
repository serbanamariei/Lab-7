#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include"functii.h"

int main()
{
	int cA,cB;
	printf("cardinalul multimii A = ");
	scanf("%d",&cA);
	printf("cardinalul multimii B = ");
	scanf("%d",&cB);

	printf("Introduceti multimea A:\n");
	double *A=citireVector(cA);
	printf("Introduceti multimea B:\n");
	double *B=citireVector(cB);
	printf("A = ");
	afisare(A,cA);
	printf("B = ");
	afisare(B,cB);

	int ok=1;
	while(ok)
	{
		int alegere;
		printf("\nAlegeti ce doriti sa faceti:\n");
		printf("1) Multimea de intersectie a lui A si B, respectiv cardinalul multimii.\n");
		printf("2) Multimea diferenta simetrica a lui A si B, respectiv cardinalul multimii.\n");
		printf("3) Multimea reuniune a multimii A si B, respectiv cardinalul multimii.\n");
		printf("alegeti --> ");
		scanf("%d",&alegere);

		switch(alegere)
		{
			case 1:
			{
				int max=cA;
				if(cB>cA) max=cB;
				double *inters=0;
				inters=(double *)malloc(max*sizeof(double));
				if(inters==0)
				{
					fprintf(stderr,"Memorie insuficienta\n");
					exit(EXIT_FAILURE);
				}
				int cInt=intersectie(inters,A,B,cA,cB);
				printf("Intersectia multimilor A si B: ");
				afisare(inters,cInt);
				printf("Cardinalul intersectiei: %d\n",cInt);

				memset(inters,0,max*sizeof(double));
				free(inters);
				inters=0;
			}
			break;
			case 2:
			{
				double *difSim=0;
				int max=cA;
				if(cB>max) max=cB;
				difSim=(double *)malloc(max*sizeof(double));
				if(difSim==0)
				{
					fprintf(stderr,"Memorie insuficienta\n");
					exit(EXIT_FAILURE);
				}

				int cDS=diferentaSim(difSim,A,B,cA,cB);
				printf("Diferenta simetrica a multimilor A si B: ");
				afisare(difSim,cDS);
				printf("Cardinalul diferentei simetrice: %d\n",cDS);

				memset(difSim,0,max*sizeof(double));
				free(difSim);
				difSim=0;
			}
			break;
			case 3:
			{
				double *reun=0;
				int cR=cA+cB;
				reun=(double *)malloc(cR*sizeof(double));
				if(reun==0)
				{
					fprintf(stderr,"Memorie insuficienta\n");
					exit(EXIT_FAILURE);
				}

				cR=reuniune(reun,A,B,cA,cB);

				printf("Reuniunea multimilor A si B: ");
				afisare(reun,cR);
				printf("Cardinalul reuniunii: %d\n",cR);

				memset(reun,0,cR*sizeof(double));
				free(reun);
				reun=0;
			}
			break;
			default: printf("Alegere invalida\n");
			break;
		}
		
		printf("Doriti sa faceti altceva ? 1-DA 0-NU --> ");
		scanf("%d",&ok);
	}

	memset(A,0,cA*sizeof(double));
	free(A);
	A=0;
	memset(B,0,cB*sizeof(double));
	free(B);
	B=0;

	return 0;
}
