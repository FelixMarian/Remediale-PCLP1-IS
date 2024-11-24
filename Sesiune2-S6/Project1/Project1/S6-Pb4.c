/*5. Să se afișeze valoarea bitului de pe o anumită poziție precizată de utilizator a unui
număr citit de la tastatură.*/


#include <stdio.h>

int main() {
	int nr, poz;
	scanf("%d", &nr);
	scanf("%d", &poz);
	if ((nr >> poz) == 1)
		printf("Bitul de pe pozitia %d al numarului %d este 1", poz, nr);
	else 
		printf("Bitul de pe pozitia %d al numarului %d este 0", poz, nr);
	
	return 0;
}