#include <stdio.h>
#define MAX 2

struct razlomak
{
    int imenilac;
    int brojilac;
};

int main()
{
    struct razlomak niz[MAX];
    int n_imenilac = 1, n_brojilac = 0, i, min;
    
    for (i = 0; i < MAX; i++)
    {
        do
        {
            printf("Unesi brojilac i imenilac %d. razlomka: ", i+1);
            scanf("%d %d", &niz[i].brojilac, &niz[i].imenilac);
        } while (!niz[i].imenilac);
    }
    
    for (i = 0; i < MAX; i++)
        n_imenilac *= niz[i].imenilac;

    for (i = 0; i < MAX; i++)
        n_brojilac += n_imenilac / niz[i].imenilac * niz[i].brojilac;


    min = (n_brojilac < n_imenilac) ? n_brojilac : n_imenilac;

    for (i = min; i >= 2; i--)
    {
        if (n_brojilac % i == 0 && n_imenilac % i == 0)
        {
            n_brojilac /= i;
            n_imenilac /= i;
        }
    }
    
    printf("Sabrani razlomak: \n");

    if (n_brojilac)
    {
        printf("%d\n", n_brojilac);
        printf("-\n");
        printf("%d\n", n_imenilac);
    } else printf("0\n");

    return 0;
}