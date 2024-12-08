/*
Probleme cu șiruri de șiruri de caractere
Fie n cuvinte date de utilizator de la tastatură. Variabila n este considerată citită corect dacă este cuprinsă în intervalul [2, 10].
Cuvintele sunt considerate citite corect dacă sunt formate strict din litere mici și au minim 3 caractere. Primul cuvânt este dat
automat fiind “premiant”. Dimensiunea fiecărui cuvânt este de maxim 10 caractere. 1. – 2.5 puncte.
Realizați un meniu interactiv cu următoarele opțiuni:
1. Afișarea cuvintelor în ordine alfabetica
2. Să se copieze într-un vector penultima literă din fiecare cuvânt, apoi să se afișeze vectorul în ordine invers alfabetică
folosind algoritmul bubble sort. – 2 puncte.
3. Să se pună pe diagonala secundară a unei matrice de ordin dat de numărul de cuvinte, numărul de biți pe 1 din
lungimea fiecărui cuvânt, iar pe restul elementelor să se pună 0. Pentru aflarea numărului de biți pe 1 se vor utiliza
operații pe biți. Matricea formată va fi salvată într-un fișier text. 2 - puncte.
4. Ieșire
Observații:
• Se va lucra cu alocarea dinamică de memorie.
• La final se va elibera memoria alocată. – 0.5 puncte
• Se va utiliza cel puțin o constantă. – 0.5 puncte
• Pentru fiecare funcționalitate se va crea o funcție.
Din oficiu se acordă 1 punct
*/

/*
Pt char-uri : fputch(scriere caracter in fisier) si fgetch(citire caracter din fisier)
Pt date formatate: fscanf(citire din fisier) si fprintf(screire in fisier)
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int verificareInterval(int n) {
	return (n>=2 && n<=10);
	return 0;
}

//Functie ajutatoare comparare
int compara(const void* cuv1, const void* cuv2) {
	const char* sir1 = *(const char**)cuv1;
	const char* sir2 = *(const char**)cuv2;
	return strcmp(sir1, sir2);
}

void afisare(char** sir, int n) {
	for (int i = 0; i < n; i++) {
		printf("%s\n", sir[i]);
	}
}

/*
sir[dim1[dim2]
dim1 - nr de cuvinte
dim2 - lungimea maxima a fiecarui cuvant

sir[i][strlen(sir[i])-1] - ULTIMUL CARACTER

*/
void introducereVector(char** sir, char* litere, int n) {
	int k,i;
	char aux;
	for (i = 0; i < n; i++) {
		litere[i] = sir[i][strlen(sir[i]) - 1];
	}

	do {
		k = 1;
		for(i=1; i<n;i++)
			if (litere[i - 1] > litere[i]) {
				litere[i - 1] = litere[i - 1] ^ litere[i];
				litere[i] = litere[i - 1] ^ litere[i];
				litere[i - 1] = litere[i - 1] ^ litere[i];
				k = 0;
			}
	} while (!k);

	for (i = 0; i < n; i++) {
		printf("%c", litere[i]);
	}
}

int nrBiti(int lungime) {
	int i, k=0;
	for (i = 31; i >= 0; i--) {
		if ((lungime >> i) & 1)
			k++;
	}
	return k;
}




void introducereMatrice(int **mat, int n, char **sir){
	FILE *fisier = fopen("matrice.txt", "w+t");
	int i, j;
	for(i=0;i<n;i++)
		for (j = 0; j < n; j++) {
			if (i == j)
				*(mat + i * n + j) = nrBiti(strlen(sir[i]));
			else
				*(mat + i * n + j) = 0;
		}


	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			fprintf(fisier, "%d ", *(mat + i * n + j));
		}
		fprintf(fisier, "\n", "");
	}

	fclose(fisier);

}



int main() {
	char** sir;
	char cuvant[50];
	int opt,n, i;
	const char primCuv[10] = "Premiant";
	char *litere = (char *)malloc(10);
	int** mat;

	do {
		printf("Cate cuvinte avem de citit: ");
		scanf("%d", &n);
	} while (!verificareInterval(n));

	sir = (char**)malloc(n * sizeof(char*));
	mat = (int**)malloc(n * n * sizeof(int*));
	if (sir == NULL) {
		printf("EROARE");
	}

	sir[0] = (char*)malloc((strlen(primCuv) + 1));
	strcpy(sir[0], primCuv);

	for (i = 1; i < n;i++) {
		
		printf("Cuvant: ");
		scanf("%s", cuvant);

		sir[i] = (char*)malloc(sizeof(char) * (strlen(cuvant) + 1));
		strcpy(sir[i], cuvant);
	}


	while (1) {
		printf("1. Afisare cuvinte alfabetic\n");
		printf("2. Copiere in vector\n");
		printf("3. Matirce\n");
		printf("4. Iesire\n");
		printf("Optiune: ");
		scanf("%d", &opt);

		switch (opt)
		{
		case 1:
			qsort(sir, n, sizeof(char*), compara);
			afisare(sir, n);
			break;
		case 2:
			introducereVector(sir, litere, n);
			break;
		case 3:
			introducereMatrice(&mat, n, sir);
			break;
		case 4:
			free(mat);
			free(litere);
			for (int i = 0; i < n; i++)
				free(sir[i]);
			free(sir);
			exit(0);
			break;
		default:
			break;
		}
	}

	return 0;
}
