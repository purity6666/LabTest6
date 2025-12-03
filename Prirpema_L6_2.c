#include <stdio.h>
#define MAX 10

int main()
{
    int n1, m1, n2, m2;

    do
    {
        printf("n1, m1 = ");
        scanf("%d %d", &n1, &m1);
        printf("n2, m2 = ");
        scanf("%d %d", &n2, &m2);
    } while (n1 < 1 || n1 > 10 || m1 < 1 || m1 > 10 || n2 < 1 || n2 > 10 || m2 < 1 || m2 > 10);
    
    double matrica1[n1][m1], matrica2[n2][m2], matrica_p[MAX][MAX] = {0}, matrica_z[MAX][MAX] = {0};

    printf("Prva matrica: \n");
    for (int i = 0; i < n1; i++)
    {
        for (int j = 0; j < m1; j++)
        {
            printf("A[%d][%d]=", i+1, j+1);
            scanf("%lf", &matrica1[i][j]);
        }
    }

    printf("Druga matrica: \n");
    for (int i = 0; i < n2; i++)
    {
        for (int j = 0; j < m2; j++)
        {
            printf("B[%d][%d]=", i+1, j+1);
            scanf("%lf", &matrica2[i][j]);
        }
    }

    if (m1 == n2)
    {
        printf("Pomnozena matrica\n");

        for (int i = 0; i < n1; i++)
        {
            printf("|  ");
            for (int j = 0; j < m2; j++)
            {
                for (int k = 0; k < m1; k++)
                    matrica_p[i][j] += matrica1[i][k] * matrica2[k][j];

                printf("%5.1lf  ", matrica_p[i][j]);
            }

            printf(" |");
            printf("\n");
        } 

    } else printf("Matrica se ne moze pomnoziti\n");

    if (n1 == n2 && m1 == m2)
    {
        printf("Sabrana matrica\n");
        for (int i = 0; i < n1; i++)
        {
            printf("|  ");
            for (int j = 0; j < m1; j++)
            {
                matrica_z[i][j] = matrica1[i][j] + matrica2[i][j];
                printf("%5.1lf ", matrica_z[i][j]);
            }
            printf(" |\n");
        }
        
    } else printf("Matrice se ne mogu sabrati\n");



    return 0;
}