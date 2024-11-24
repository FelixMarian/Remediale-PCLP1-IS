/*1. Să se verifice dacă un numar întreg citit de la tastatura este egal cu o putere a lui*/


#include <stdio.h>

int main() {
	int nr, i, k=0;
	scanf("%d", &nr);
	for (i = 31; i >= 0; i--) {
		if ((nr >> i) & 1 == 1) k++;
	}
	if (k == 1)
		printf("%d este o putere a lui 2", nr);
	else
		printf("%d NU este o putere a lui 2", nr);
	return 0;
}