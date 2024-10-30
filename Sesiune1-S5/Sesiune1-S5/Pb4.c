/*1. Să se scrie un program în C care să citească de la tastatură două matrice pătratice de
numere întregi, de dimensiune specificată de utilizator şi să afişeze suma celor două
matrice.*/

#include <stdio.h>

int main() {
	int m1[5][5], m2[5][5], m3[5][5];
	int n,i,j;
	printf("Care doriti sa fie dimensiunea matricilor: ");
	scanf("%d", &n);


	//Citire matrice 1
	for(i=0;i<n;i++)
		for (j = 0; j < n; j++) {
			printf("M1[%d][%d]= ", i, j);
			scanf("%d", &m1[i][j]);
		}

	//Citire matrice 2
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++) {
			printf("M1[%d][%d]= ", i, j);
			scanf("%d", &m2[i][j]);
		}

	//Suma
	for(i=0;i<n;i++)
		for (j = 0; j < n; j++) {
			m3[i][j] = m1[i][j] + m2[i][j];
		}


	//Afisare matrice 3
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++)
			printf("%d ", m3[i][j]);
		printf("\n");
	}

	return 0;
}