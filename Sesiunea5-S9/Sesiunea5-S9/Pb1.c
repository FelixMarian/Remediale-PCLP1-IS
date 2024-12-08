/*// sa se scrie un program care tine evidenta
// jocurilor video dintr un magazin
//fiecare joc e descris de nume,pret,companie,an
//realizati un meniu interactiv cu urm optiuni
//1 citirea unui joc de la tastatura,
//obs numele jocului este considerat corect citit daca primul caracter e litera mare iar al doilea este o cifra;
//anul aparitiei este corect citit daca e mai mare de 1990, in caz contrar va fi recitit
//2 afisare tuturor jocurilor citite
//3 cautare joc dupa nume
//4 afisarea tuturor jocurile cu un pret mai mic dat de utilizator
//5 afisare jocurilor in ordine alfabetica dupa nume
//6 stergere dupa nume
//obs se va implementa o func pt fiecare cerinta lmao 
//atat momentan mai vedem daca avem timp*/


/*
Pt test la citire folosim do...while
do{
COD
}while(conditie);
*/


#include <stdio.h>
#include <string.h>

typedef struct {
	char nume[20];
	char companie[20];
	int an;
	int pret;
} joc;

int verificareNume(char nume[]) {
	if ((nume[0] >= 'A' && nume[0] <= 'Z') && (nume[1] >= '0' && nume[1] <= '9'))
		return 1;
	return 0;

}

int verificareAn(int an) {
	if (an >= 1990) return 1;
	return 0;
}

void citireJoc(joc* jc, int *n) {
	(*n)++;
	do {
		printf("Nume: ");
		scanf("%s", (jc + *n)->nume);
	} while (!verificareNume((jc+*n)->nume));
	printf("Companie: ");
	scanf("%s", (jc + *n)->companie);
	printf("Pret: ");
	scanf("%d", &(jc + *n)->pret);
	do {
		printf("An: ");
		scanf("%d", &(jc + *n)->an);
	} while (!verificareAn((jc+*n)->an));
}

void afisare(joc* jc, int* n) {
	int i;
	for (i = 0; i <= (*n); i++) {
		printf("Nume: %s\n Comp: %s\n Pret: %d\n An: %d\n",
			(jc + i)->nume, (jc + i)->companie, (jc + i)->pret, (jc + i)->an);
	}
}

void cautareDupaNume(joc* jc, int n, char nume[]) {
	int i;
	for (i = 0; i <= n; i++) {
		if (strcmp((jc + i)->nume, nume) == 0) {
			printf("Nume: %s\n Comp: %s\n Pret: %d\n An: %d\n",
				(jc + i)->nume, (jc + i)->companie, (jc + i)->pret, (jc + i)->an);
		}
	}
}

void afisarePretMaxim(joc* jc, int n, int pretMaxim) {
	int i;
	for (i = 0; i <= n; i++) {
		if((jc+i)->pret <= pretMaxim)
			printf("Nume: %s\n Comp: %s\n Pret: %d\n An: %d\n",
				(jc + i)->nume, (jc + i)->companie, (jc + i)->pret, (jc + i)->an);
	}
}

void afisareOrdineAlfabetica(joc* jc, int n) {
	int i, k;
	joc aux;
	do {
		k = 1;
		for (i = 0; i < n; i++) {
			if (strcmp((jc + i)->nume, (jc + i + 1)->nume) > 0) {
				aux = *(jc + i);
				*(jc + i) = *(jc + i + 1);
				*(jc + i + 1) = aux;
				k = 0;
			}
		}
	} while (!k);

	for (i = 0; i <= n; i++) {
		printf("Nume: %s\n Comp: %s\n Pret: %d\n An: %d\n",
			(jc + i)->nume, (jc + i)->companie, (jc + i)->pret, (jc + i)->an);
	}
}

void stergere(joc* jc, int *n, char numeCautat[]) {
	int k = 0;
	int i, j;
	for (i = 0; i < (*n-k); i++) {
		if (strcmp((jc + i)->nume, numeCautat) == 0) {
			k++;
			for (j = i; j < (*n - k); j++) {
				*(jc + i) = *(jc + i + 1);
			}
			i--;
		}
	}
	*n = *n - k;
}


int main() {
	int opt, n=-1, pretMaxim;
	joc jocuri[50];
	char numeJocCautat[20], numeCautat[20];
	while (1) {
	 printf("0. Iesire\n");
	 printf("1. Citire joc\n");
	 printf("2. Afisarea tuturor jocurilor\n");
	 printf("3. Cautare joc dupa nume\n");
	 printf("4. Afisarea tuturor jocurilor cu pret mai mic\n");
	 printf("5. Afisarea jocurilor alfabetic\n");
	 printf("6. Stergere dupa nume\n");
	 printf("Optiune: ");
	 scanf("%d", &opt);

	 switch (opt)
	 {
	 case 0:
		 exit(0);
		 break;
	 case 1:
		 citireJoc(&jocuri, &n);
		 break;
	 case 2:
		 afisare(&jocuri, &n);
		 break;
	 case 3:
		 printf("Nume joc: ");
		 scanf("%s", numeJocCautat);
		 cautareDupaNume(&jocuri, n, numeJocCautat);
		 break;
	 case 4:
		 printf("Pret maxim: ");
		 scanf("%d", &pretMaxim);
		 afisarePretMaxim(&jocuri, n, pretMaxim);
		 break;
	 case 5:
		 afisareOrdineAlfabetica(&jocuri, n);
		 break;
	 case 6:
		 printf("Nume: ");
		 scanf("%s", numeCautat);
		 stergere(&jocuri, &n, numeCautat);
		 break;
	 default:
		 printf("Optiunea nu exista\n");
		 break;
	 }
	}

	return 0;
}