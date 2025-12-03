#include <stdio.h>
#include <math.h>
#define kvadrat(x) (x)*(x)
#define MAX 50

struct kompleks
{
    double realni;
    double imaginarni;
};

int main()
{
    struct kompleks niz[MAX] = {0}, temp;
    int n, max_indeks;

    do
    {
        printf("n=");
        scanf("%d", &n);
    } while (n < 1 || n > MAX);
    
    for (int i = 0; i < n; i++)
    {
        printf("Kompleks[%d]: ", i);
        scanf("%lf %lf", &niz[i].realni, &niz[i].imaginarni);
    }

    for (int i = 0; i < n; i++)
    {
        max_indeks = i;
        temp = niz[i];

        for (int j = i; j < n; j++)
            if (sqrt(kvadrat(niz[j].realni) + kvadrat(niz[j].imaginarni)) > sqrt(kvadrat(niz[max_indeks].realni) + kvadrat(niz[max_indeks].imaginarni)))
                max_indeks = j;

        niz[i] = niz[max_indeks];
        niz[max_indeks] = temp;
    }
    
    for (int i = 0; i < n; i++)
        printf("%.5lf %.5lfi\n", niz[i].realni, niz[i].imaginarni);

    return 0;
}