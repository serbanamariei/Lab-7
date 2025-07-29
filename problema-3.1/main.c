#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"functii.h"

int main()
{
	long int numar;
    printf("Introduceti un numar intreg: ");
    scanf("%ld", &numar);
    
    char *sir = transformareToAscii(numar);
    
    printf("Numarul %ld transformat in sir de caractere: %s\n", numar, sir);
    
    // Eliberarea memoriei
    free(sir);
    sir = NULL;
    
    return 0;
}
