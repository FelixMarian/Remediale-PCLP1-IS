#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define x 1;

int validare_n(int q)//asta ne trebuie doar in main!!!!!!pt acl testam ordinu matricei 
{
    return(q >= 2 && q <= 5);
}

int validare_elem_mat(int q)
{
    return(q >= -100 && q <= 100);


}

void citire(int* m, int n)//citire mat cu pointeri
{
    int i, j;
    for (i = 0; i < n; i++) {//pana la n ptc ultimul element n este dat 1 automat
        for (j = 0; j < n; j++) {
            if (i == n - 1)//adk pe ultima linie
            {
                *(m + i * n + j) = x;// nu poti sa dai x= cu ceva ptc x e const ce nu isi schimba val
                //linia 13 umple ultimu rand cu 1
            }
            else {

                printf("m[%d][%d]= ", i, j);
                scanf("%d", m + i * n + j);//la citire nu se pune pointer ptc pregatim adresa

            }
        }


    }
}

void afisare(int* m, int n) {
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%d ", *(m + i * n + j));// la afisare se pune pointer ptc apelam aloarea dela adresa pe care am pregatit o

        }
        printf("\n");

    }
}
// o sa ma lase sa  introduc mai putin cu o linie ptc pe ultima am umplut o cu 1

void afisare_transpusa(int* m, int n) {//facem direct afisarea ptc nu mai avem neoie de transpusa dupa
    int i, j;
    for (j = 0; j < n; j++) {//la transpusa se iau coloanele primele si dupa liniile
        for (i = 0; i < n; i++) {
            printf("%d ", *(m + i * n + j));

        }
        printf("\n");
    }
}

void copiere_si_sortare_si_afiare(int* m, int n) {
    int* v;
    int i, j, k = 0, nr1, nr2, l=0;
    v = (int*)malloc((n + n) * sizeof(int));//numaru de coloane (n+n) prima si ultima 
    if (v == NULL) {
        printf("Memoria nu s a alocat ;-;");
        exit(0);
    }

    for(i=0;i<n;i++)
        for (j = 0; j < n; j++) {
            if (j == 0 || j == n - 1) {
                *(v + l) = *(m + i * n + j);
                l++;
            }
        }
    do {
        k = 1;
        for (i = 1; i < l; i++) {
            nr1 = *(v + i - 1);
            nr2 = *(v + i);
            if ( nr1 < nr2) {
                nr2 = nr1 ^ nr2;
                nr1 = nr1 ^ nr2;
                nr2 = nr1 ^ nr2;
                k = 0;
            }
        }
    } while (!k);
    
    
    for (i = 0; i < l; i++) {
        printf("%d \n", *(v + i));
    }

    free(v);

}

void salvareFisier(int* m, int n) {
    int i, j, S=0;
    FILE* fisier;
    char numeFisier[30];
    printf("NUme fisier: ");
    scanf("%s", numeFisier);
    strcat(numeFisier, ".txt"); //Pentru a nu obliga utilizatorul sa puna extensia
    fisier = fopen(numeFisier, "w+t");

    for(i=0; i<n;i++)
        for (j = 0; j < n; j++) {
            if (i + j == n) { //Elemente coloana secundara !!!
                S = S + *(m + i * n + j);
            }
        }

    for (i = 31; i >= 0; i--) {
        if ((S >> i) & 1) fprintf(fisier, "1");
        else fprintf(fisier, "0");
    }

    fclose(fisier);
}

int main() {

    int i, j, opt, k, n, * M;
    do {
        printf("ordinu mat este:");//la matrice mereu se citeste dimesnsiunea si dupa restul
        scanf("%d", &n);
    } while (!validare_n(n));// functia neg returneaza 0 functia normala ret 1
    M = (int*)malloc(n * n * sizeof(int));
    if (M == NULL) {
        printf("Nu s a alocat memorie ;-;");//alocare memorie matrce neaparat in int!
        exit(0);
    }
    citire(M, n);
    while (1)
    {
        printf("1.Afișarea matricei și a matricei transpuse\n");
        printf("2.Să se copieze într-un vector elementele de pe prima și ultima coloană, apoi să se afișeze vectorul în ordine crescătoare folosind algoritmul bubble sort\n");
        printf("3.Să se salveze într-un fișier text, cu numele dat de utilizator de la tastatură, reprezentarea binară a sumei elementelor matricei de pe diagonala secundară. Pentru reprezentarea binară se vor utiliza operații pe biți \n");
        printf("4.Ieșire\n");
        printf("Optiunea dumeavoastra este:");
        scanf("%d", &opt);
        switch (opt)
        {
        case 1:
            printf("\nMatricea este: \n");
            afisare(M, n);
            printf("\nMatricea transpusa este: \n");
            afisare_transpusa(M, n);
            break;
        case 2:
            copiere_si_sortare_si_afiare(M, n);
            break;
        case 3:
            afisare(M, n);
            salvareFisier(M, n);
            break;
        case 4:
            exit(0);
            break;

        default:
            printf("optiune gresita!");
            break;
        }
    }




    return 0;
}
