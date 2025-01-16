#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Legume{
	char nume[20];
	char tara[20];
	int pret;
}leg;

int numeLeguma(char nume[]) {
	int i,k=0;
	if (strlen(nume) >= 2)
	{
		for (i = 0; i < strlen(nume); i++) {
			if (nume[i] < 'a' || nume[i]>'z')
				k++;
		}
		if (k == 0) return 1;
	}
	return 0;
}


void adaugareLeguma(leg *vec, int* n) {
	(*n)++;
	do {
		printf("Nume: ");
		scanf("%s", (vec + *n)->nume);
	} while (!numeLeguma((vec + *n)->nume));

	printf("Tara de provenienta: ");
	scanf("%s", (vec + *n)->tara);
	(vec + *n)->pret = strlen((vec + *n)->nume) + strlen((vec + *n)->tara);
}

void afisare(leg* vec, int n) {
	int i;

	for (i = 0; i <= n; i++) {
		printf("%s %s %d\n", (vec + i)->nume, (vec + i)->tara, (vec + i)->pret);
	}
}

void afisareDescresc(leg* vec, int* n) {
	int k,i, nr1, nr2;
	leg aux;


	do {
		k = 1;
		for (i = 1; i <= (*n); i++) {
			if ((vec + i - 1)->pret < (vec + i)->pret) {
				aux = *(vec + i);
				*(vec + i) = *(vec + i - 1);
				*(vec + i - 1) = aux;
				k = 0;
			}
		}

	} while (!k);

	afisare(vec, *n);
}

void stergereSiAfisare(leg *vec, int *n) {
	FILE* fisier;
	char numeFisier[20];
	leg aux;
	int i;



	printf("Nume fisier: ");
	scanf("%s", numeFisier);
	strcat(numeFisier, ".txt");
	fisier = fopen(numeFisier, "w+t");

	int lastElem = *(n)-1;
	for (i = 1; i < lastElem; i++) {
		*(vec + i) = *(vec + i + 1);
	}
	(*n)--;
	 
	for (i = 0; i <= *n; i++) {
		fprintf(fisier,"%s %s %d\n", (vec + i)->nume, (vec + i)->tara, (vec + i)->pret);
	}
}


int compara(const void* a, const void* b) {
	int val_a = *(int*)a;
	int val_b = *(int*)b;

	return val_b - val_a;
}

void sortareQSort(leg* vec, int* n) {
	int* v = (int*)malloc((*n) * sizeof(int));
	int i;



	for (i = 0; i <= (*n); i++) {
		*(v + i) = strlen((vec + i)->tara);
	}

	printf("\nNESORTAT\n");
	for (i = 0; i <= (*n); i++) {
		printf("%d ", *(v + i));
	}

	qsort(v, *n, sizeof(int), compara);


	printf("\nSORTAT\n");

	for (i = 0; i <= (*n); i++) {
		printf("%d ", *(v + i));
	}
	
}

int main() {
	int opt;
	int* n=-1;
	leg vec[100];
	while (1) {
		printf("0. Iesire\n");
		printf("1. Adaugare\n");
		printf("2. Afisare ordine descrescatoare\n");
		printf("3. Stergere leguma\n");
		printf("4. Copiere in vector\n");
		printf("Optiunea dvs: ");
		scanf("%d", &opt);

		switch (opt)
		{
		 case 1:
			 adaugareLeguma(vec, &n);
			 break;
		 case 2:
			 afisareDescresc(vec, &n);
			 break;
		 case 3:
			 stergereSiAfisare(vec, &n);
			 break;
		 case 4:
			 sortareQSort(vec, &n);
			 break;
		 case 0:
			 exit(0);
			 break;
		default:
			break;
		}
	}


	return 0;
}