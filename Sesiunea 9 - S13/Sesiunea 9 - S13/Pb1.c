#include <stdio.h>
#include <stdlib.h>

/*
sizeof(data) in octeti
int - 4
char - 1
long - 4
float - 4
double - 8
*/

/*
Sa se scrie un program in C, cu matrice de nr intregi, folositi meniu interactiv cu urmatoarele optiuni:
1. Scriere matrice
2. Afisare matrice
3. Suma elem de pe coloana principala
4. Suma elemen pare de pe coloana secundara

Elementele de pe prima coloana vor fi automat 0

*/

void adaugareMatrice(int* mat, int n) {
	int i, j;
	for (i = 0; i < n; i++) {
		for (j = 1; j < n; j++)
		{

			printf("mat[%d][%d]= ", i, j);
			scanf("%d", (mat + i * n + j));

		}
		*(mat + i * n) = 0;
	}
}

void afisareMatrice(int* mat, int n) {
	int i, j;
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++)
			printf("%d ", *(mat + i * n + j));
		printf("\n");
	}
}

/*
Diag Principala => i==j
Diag sec => i+j==n-1
*/

void sumaDP(int* mat, int n) {
	int i, j, S=0;
	for(i=0;i<n;i++)
		for (j = 0; j < n; j++) {
			if (i == j)
				S += *(mat + i * n + j);
		}

	printf("Suma de pe diag principala este: %d\n", S);
}

void sumaPare(int* mat, int n) {
	int i, j, S = 0;
	for(i=0; i<n;i++)
		for (j = 0; j < n; j++) {
			if ((i + j == n - 1) && (*(mat + i * n + j) % 2 == 0))
					S += *(mat + i * n + j);
		}
}

int main() {
	int optiune;
	int n;

	printf("Introduceti dimensiune matrice: ");
	scanf("%d", &n);
	int** mat = (int**)malloc(sizeof(int) * n*n);

	while (1) {
		printf("1. Adaugare matrice\n");
		printf("2. Afisare matrice\n");
		printf("3. Suma diag princ\n");
		printf("4. Suma elem pare dp diag sec\n");
		printf("0. Iesire\n");
		printf("Optiunea dvs: ");
		scanf("%d", &optiune);
		switch (optiune)
		{
		case 0:
			free(mat);
			exit(1);
			break;
		case 1:
			adaugareMatrice(mat, n);
			break;
		case 2:
			afisareMatrice(mat, n);
			break;
		case 3:
			sumaDP(mat, n);
			break;
		case 4:
			sumaPare(mat, n);
			break;
		default:
			break;
		}
	}



	return 0;
}