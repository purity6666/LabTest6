#include <stdio.h>
#include <math.h>

struct trougao
{
    double a, b, c;
} t1;


int main()
{

    double obim, s, povrsina;
    
    do
    {
        printf("Unesi stranice trougla: ");
        scanf("%lf %lf %lf", &t1.a, &t1.b, &t1.c);
    } while (t1.a + t1.b < t1.c || t1.b + t1.c < t1.a || t1.a + t1.c < t1.b);
    
    obim = t1.a + t1.b + t1.c;
    s = obim / 2;
    povrsina = sqrt(s*(s-t1.a)*(s-t1.b)*(s-t1.c));

    printf("Povrsina: %lf, Obim: %lf\n", povrsina, obim);

    return 0;
}