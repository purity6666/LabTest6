#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Student
{
    char ime[50];
    char prezime[50];
    int indeks;
} STUDENT;

typedef struct Cvor
{
    STUDENT s;
    struct cvor *next;
} CVOR;

CVOR* dodaj_na_pocetak(CVOR *glava, STUDENT s);
void ispisi_listu(CVOR *glava);
void upisi_u_fajl(CVOR *glava, const char *ime_fajla);

int main() 
{
    CVOR *glava = NULL;

    STUDENT s1 = {"Marko", "Markovic", 12345};
    STUDENT s2 = {"Jovan", "Jovanovic", 23456};
    STUDENT s3 = {"Ana", "Anic", 34567};

    glava = dodaj_na_pocetak(glava, s1);
    glava = dodaj_na_pocetak(glava, s2);
    glava = dodaj_na_pocetak(glava, s3);

    ispisi_listu(glava);

    upisi_u_fajl(glava, "studenti.txt");

    return 0;
}

CVOR* dodaj_na_pocetak(CVOR *glava, STUDENT s) 
{
    CVOR *novi = malloc(sizeof(CVOR));
    
    if (novi == NULL)
        return NULL;

    novi->s = s;
    novi->next = glava;

    return novi;
}

void ispisi_listu(CVOR *glava) 
{
    CVOR *trenutni = glava;
    while (trenutni != NULL) 
    {
        printf("%s %s %d\n", 
            trenutni->s.ime, 
            trenutni->s.prezime, 
            trenutni->s.indeks);

        trenutni = trenutni->next;
    }
}

void upisi_u_fajl(CVOR *glava, const char *ime_fajla) 
{
    FILE *fp = fopen(ime_fajla, "w");
    if (fp == NULL) return;

    CVOR *trenutni = glava;
    while (trenutni != NULL) 
    {
        fprintf(fp, "%-15s %-15s %d\n", 
            trenutni->s.ime, 
            trenutni->s.prezime, 
            trenutni->s.indeks);

        trenutni = trenutni->next;
    }

    fclose(fp);
}