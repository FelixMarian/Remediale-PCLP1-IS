/* Realizati un program in c in care se citesc de la tastatura n instr muzicale,
ultimul instrument muzical este initializat automat si este NAI. Instrumentele muzicale sunt
considerate citite corect daca sunt formate doar din litere mici. Fiecare instrument are dim maxima
egala cu 10 caractere. Realizati meniu interactiv cu urm optiuni:

1. Afisarea instrumentelor citite
2. Calcularea sumei lungimii instrumentelor muzicale si repr. in baza 2
3. Afisarea nr de biti pe 1 pt fiecare lungime de instrument muzical
4. Sa se puna pe diag principala a unei mat. patrat de ordinul dat de nr de instr. muzicale lungimea
minima din vectorul de instrumente pe restul elem matricii se va pune 0.*/

//int *p;
//int a,b;
//p = &a; Lui p ii dau adresa de memorie a lui a 
//b = *p; Lui b ii dau valoarea de pe adresa de memorie a lui p


/*
	exemplu pointer

	a = 23;
	p = &a;
	printf(p); - 23
	a=65;
	printf(p); - 65
*/

/*
		 if(!conditie) - Conditia sa fie 0 / false
		 if(conditie) - Conditia sa fie 1 / true
		 if(conditie == val) - Conditia sa aiba o valoare
		 
	Parcurgere vector - *(v+i) / v[i] daca este sir de siruri (pb asta)
	Parcurgere matrice i - linii, j-coloane, *(mat+i*n+j), n - ordinul matricii
0*/


/* MINIM si MAXIM

MINIM:
	int MIN = 10001;
	for(parcurgere vector)
		if(vect[i]<MIN)
			MIN = vect[i]

	int MAX = -10001;
	for(parcurgere vecotr)
		if(vect[i]>MAX) 
			MAX = vect[i]
*/



#include <stdio.h>
#include <stdlib.h>

int main() {
	int opt,i,j;
	int S = 0;
	int MIN = 10001;
	int k = 0;
	int biti = 0;
	int** mat;
	char** instrumente;
	char numeInstrument[10];
	int n;
	printf("Nr de instrumente care vor fi citite: ");
	scanf("%d", &n);
	instrumente = (char**)malloc(n * sizeof(char));
	mat = (int**)malloc(n * n * sizeof(int));
	if (instrumente == NULL) {
		printf("EROARE");
	}
	for (i = 0; i < n - 1; i++) {
		do {
			k = 0;
			scanf("%s", numeInstrument);

			for (j = 0; j < strlen(numeInstrument); j++) {
				if (numeInstrument[j] < 'a' || numeInstrument[j]>'z')
					k++;
			}
			if (k != 0) printf("Doar litere mici\n");
		} while (k!=0);
		instrumente[i] = (char*)malloc(sizeof(char) * (strlen(numeInstrument) + 1));
		strcpy(instrumente[i], numeInstrument);
	}
	instrumente[n - 1] = (char*)malloc(sizeof(char) * (strlen("nai")+1));
	strcpy(instrumente[n - 1], "nai");

	while (1) {
	 printf("1. Afisarea instrumentelor citite\n");
	 printf("2. Calcularea sumei lung si repr\n");
	 printf("3. Nr de biti pe 1\n");
	 printf("4. Diag principala\n");
	 printf("optiunea dvs: ");
	 scanf("%d", &opt);
	 switch (opt)
	 {
	 case 0:
		 free(instrumente);
		 exit(0);
		 break;
	 case 1:
		 for (i = 0; i < n; i++) {
			 printf("%s\n", *(instrumente + i));
		 }
		 break;
	 case 2:
		 for (i = 0; i < n; i++) {
			 S = S + strlen(instrumente[i]);
		 }
		 printf("Suma lungimilor este %d\n", S);
		 //Algoritm reprezentare numar in baza 2
		 for (j = 31; j >= 0; j--) {
			 if (1 & (S >> j)) printf("1");
			 else printf("0");
		 }
		 printf("\n");
		 break;
	 case 3:
		 for (i = 0; i < n; i++) {
			 printf("%s ", instrumente[i]);
			 int lungime = strlen(instrumente[i]);
			 for (j = 31; j >= 0; j--) {
				 if (1 & (lungime >> j)) biti++;
			 }
			 printf("%d\n", biti);
			 biti = 0;
		 }
		 break;
	 case 4:
		 //Parcurgere sir de siruri sa vedem lungimea minima
		 for (i = 0; i < n; i++)
		 {
			 if (strlen(instrumente[i]) < MIN)
			 {
				 MIN = strlen(instrumente[i]);
			 }
		 }
		 
		 //Formare matrice
		 for(i=0;i<n;i++)
			 for (j = 0; j < n; j++) {
				 if (i == j)
					 *(mat + i * n + j) = MIN;
				 else *(mat + i * n + j) = 0;
			 }


		 //Afisare matrice
		 for (i = 0; i < n; i++) {
			 for (j = 0; j < n; j++)
				 printf("%d ", *(mat + i * n + j));
			 printf("\n");
		 }
		 break;
	 default:
		 printf("NU exista aceasta optiune");
		 break;
	 }
	}



	return 0;
}