/* Sa se afiseze cate elemente palindroame are o matrice */

#include <stdio.h>

int main() {
	int mat[3][3];
	int i, j, k = 0, a;
	int aux, pal = 0;

	//Citire matrice
	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
		{
			printf("Mat[%d][%d] = ", i, j);
			scanf("%d", &mat[i][j]);

		}

	//Afisare matrice (pentru verificarea citirii)
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			printf("%d ", mat[i][j]);
		}
		printf("\n");
	}
	
	//Parcurgere pentru a verifica fiecare element daca este palindrom(oglindit)
	for (i=0;i<3;i++)
		for (j = 0; j < 3; j++) {
			pal = 0;
			aux = mat[i][j];
			while (aux != 0) {
				a = aux % 10;
				pal = pal * 10 + a;
				aux = aux / 10;
			}
			if (mat[i][j] == pal) k++;

		}

	printf("Numarul de palindroame este %d", k);

	
	return 0;
}