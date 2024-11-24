/*6. Să se interschimbe valorile a două variabile întregi citite de la tastatură.*/

#include <stdio.h>

int main() {
	int nr1, nr2;
	scanf("%d", &nr1);
	scanf("%d", &nr2);

	nr1 = nr1 ^ nr2;
	nr2 = nr1 ^ nr2;
	nr1 = nr1 ^ nr2;

	printf("nr1 = %d\n", nr1);
	printf("nr2 = %d", nr2);
	return 0;
}