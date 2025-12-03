#include <stdio.h>
#define MAX 250

int main()
{
    int n, proizvod[MAX] = {1}, temp, prenos, brojac;

    do
    {
        printf("n=");
        scanf("%d", &n);
    } while (n < 0 || n > 100);

    for (int i = 1; i <= n; i++)
    {
        prenos = 0;

        for (int j = 0; j <= MAX - 1; j++)
        {
            proizvod[j] = proizvod[j] * i + prenos;
            prenos = proizvod[j] / 10;
            proizvod[j] %= 10;
        }
    }
    
    brojac = MAX - 1;

    while (!proizvod[brojac])
        brojac--;

    for (int k = brojac; k >= 0; k--)
        printf("%d", proizvod[k]);

    printf("\n");

    return 0;
}