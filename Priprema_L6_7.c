#include <stdio.h>
#define MAX_STRING 15
#define MAX 50

struct datum
{
    int dan, mjesec, godina;
};

struct student
{
    int broj_indeksa;
    char ime[MAX_STRING], prezime[MAX_STRING];
    struct datum rodjen;
    double prosjek;
} studenti[MAX], temp;

int main()
{
    int n, max_indeks;

    do
    {
        printf("n=");
        scanf("%d", &n);
    } while (n < 1 || n > MAX);
    

    for (int i = 0; i < n; i++)
    {
        printf("Unesi studenta(Prezime, ime, datum rodjenja, prosjek, broj indeksa): ");
        scanf("%s %s %d.%d.%d. %lf %d", studenti[i].ime, studenti[i].prezime, &studenti[i].rodjen.dan, &studenti[i].rodjen.mjesec, &studenti[i].rodjen.godina, &studenti[i].prosjek, &studenti[i].broj_indeksa);
    }

    for (int i = 0; i < n; i++)
    {
        max_indeks = i;
        temp = studenti[i];

        for (int j = i; j < n; j++)
            if (studenti[j].rodjen.godina < studenti[max_indeks].rodjen.godina || studenti[j].rodjen.godina == studenti[max_indeks].rodjen.godina && studenti[j].rodjen.mjesec < studenti[max_indeks].rodjen.mjesec || studenti[j].rodjen.godina == studenti[max_indeks].rodjen.godina && studenti[j].rodjen.mjesec == studenti[max_indeks].rodjen.mjesec && studenti[j].rodjen.dan < studenti[max_indeks].rodjen.dan)
                max_indeks = j;
            
        studenti[i] = studenti[max_indeks];
        studenti[max_indeks] = temp;
    }
    
    printf("BI.  PREZIME         IME             DATUM RODJ. PROSJEK\n");
    printf("==== =============== =============== =========== =======\n");
    

    for (int i = 0; i < n; i++)
        printf("%04d %-15s %-15s %02d.%02d.%04d. %7.2lf\n", studenti[i].broj_indeksa, studenti[i].ime, studenti[i].prezime, studenti[i].rodjen.dan, studenti[i].rodjen.mjesec, studenti[i].rodjen.godina, studenti[i].prosjek);
    
    printf("==== =============== =============== =========== =======\n");

    return 0;
}