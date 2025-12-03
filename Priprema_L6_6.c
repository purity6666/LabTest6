#include <stdio.h>
#define MAX_STRING 16
#define MAX 50

struct artikal
{
    int identifikator;
    char naziv[MAX_STRING];
    double kolicina, cijena;
} artikli[MAX] = {0}, temp;


int main()
{
    int n, min_indeks, i;

    do
    {
        printf("Unesi broj artikala ");
        scanf("%d", &n);
    } while (n < 1 || n > MAX);

    for (int i = 0; i < n; i++)
    {
        printf("Unesi redom ID, NAZIV, CIJENU, KOL.: ");
        scanf("%d %s %lf %lf", &artikli[i].identifikator, artikli[i].naziv, &artikli[i].cijena, &artikli[i].kolicina);
    }
    
    printf("===== ==================== ====== ====== =========\n");
    printf("ID    NAZIV                CIJENA   KOL.    UKUPNO\n");
    printf("===== ==================== ====== ====== =========\n");
    
    for (i = 0; i < n; i++)
    {
        min_indeks = i;
        temp = artikli[i];

        for (int j = i; j < n; j++)
            if (artikli[j].identifikator < artikli[min_indeks].identifikator)
                min_indeks = j;
            
        artikli[i] = artikli[min_indeks];  
        artikli[min_indeks] = temp;
    }

    for (i = 0; i < n; i++)
        printf("%05d %-20s %6.2lf %6.2lf %9.2lf\n", artikli[i].identifikator, artikli[i].naziv, artikli[i].cijena, artikli[i].kolicina, artikli[i].cijena * artikli[i].kolicina);
    
    
    return 0;
}