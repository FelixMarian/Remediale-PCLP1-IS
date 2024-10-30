/* Fie un vector format din n caractere date de util de la tastatura si afisati
caracterele de pe pozitia para*/

#include <stdio.h>

int main() {
	int v[8];
	int i;

	//Citire elemente vector
	for (i = 0; i < 8; i++) {
		printf("V[%d]= ", i);
		scanf("%d", &v[i]);
	}

	//Afisare vector pt verificare
	for (i = 0; i < 8; i++) {
		printf("%d ", v[i]);
	}
	
	printf("\n");

	//Verificam pozitiile si afisam daca sunt pare
	for (i = 0; i < 8; i++) {
		if (i % 2 == 0) //Nr par
			printf("%d ", v[i]);
	}

	return 0;
}