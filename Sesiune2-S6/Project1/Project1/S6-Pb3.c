/*4. Să se verifice dacă un număr întreg citit de la tastatură este par sau impar.*/

#include <stdio.h>

int main() {
	int nr;
	scanf("%d", &nr);
	//Testam paritatea, comparam CEL MAI DIN DREAPTA BIT (poz 0) cu 1 prin operatorul &
	if (nr & 1 == 1)
		printf("%d este impar", nr);
	else printf("%d este par", nr);
	return 0;
}