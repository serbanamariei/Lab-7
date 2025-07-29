#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include"functii.h"

int exista(double *v, int n, double element)
{
    for(int i=0;i<n;i++)
    {
        if(*(v+i)==element)
            return 1;
    }
    return 0;
}

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

int intersectie(double *inters, double *a, double *b, int ca, int cb)
{
	int cInter=0;
	for(int i=0;i<ca;++i)
		for(int j=0;j<cb;++j)
		{
			if(*(a+i)==*(b+j)) 
			{
				if(!exista(inters,cInter,*(a+i)))
				{
					*(inters+cInter)=*(a+i);
					cInter++;
				}
				break;
			}
		}
	return cInter;
}

int diferentaSim(double *difSim, double *a, double *b, int ca, int cb)
{
	int cDS=0;
	for(int i=0;i<ca;++i)
	{
		int ok=1;
		for(int j=0;j<cb;++j)
		{
			if(*(a+i)==*(b+j)) ok=0;
		}
		if(ok==1)
		{
			*(difSim+cDS)=*(a+i);
			cDS++;
		}
	}

	for(int i=0;i<cb;++i)
	{
		int ok=1;
		for(int j=0;j<ca;++j)
		{
			if(*(b+i)==*(a+j))
			{
				ok=0;
				continue;
			}
		}
		if(ok==1)
		{
			*(difSim+cDS)=*(b+i);
			cDS++;
		}
	}
	cDS--;
	return cDS;
}

int reuniune(double *reuniune, double *a, double *b, int ca, int cb)
{
	int cR=0;
	for(int i=0;i<ca;++i) 
	{
		*(reuniune+cR)=*(a+i);
		cR++;
	}
	for(int i=0;i<cb;++i)
	{
		*(reuniune+cR)=*(b+i);
		cR++;
	}
	return cR;
}

char *transformareToAscii(long int numar)
{
    int nrCifre;
    int esteNegativ = 0;
    long int numarAbs = numar;

    // Verifică dacă numărul este negativ
    if (numar < 0) {
        esteNegativ = 1;
        numarAbs = -numar;
    }

    // Cazul special pentru 0
    if (numar == 0) {
        nrCifre = 1;
    } else {
        // Calculează numărul de cifre prin logaritmare
        nrCifre = (int)log10(numarAbs) + 1;
    }

    // Calculează dimensiunea necesară pentru șir
    int dimensiune = nrCifre + esteNegativ + 1; // +1 pentru '\0'

    // Alocă memorie pentru șirul de caractere
    char *sir = (char *)malloc(dimensiune * sizeof(char));
    if (sir == NULL) {
        fprintf(stderr, "Memorie insuficienta\n");
        exit(EXIT_FAILURE);
    }

    // Adaugă terminatorul de șir
    sir[dimensiune - 1] = '\0';

    // Cazul special pentru 0
    if (numar == 0) {
        sir[0] = '0';
        return sir;
    }

    // Completează șirul cu cifrele numărului (de la dreapta la stânga)
    int pozitie = dimensiune - 2; // poziția înainte de '\0'

    while (numarAbs > 0) {
        sir[pozitie] = (numarAbs % 10) + '0'; // Transformă cifra în caracter
        numarAbs /= 10;
        pozitie--;
    }

    // Adaugă semnul minus dacă numărul este negativ
    if (esteNegativ) {
        sir[0] = '-';
    }

    return sir;
}
