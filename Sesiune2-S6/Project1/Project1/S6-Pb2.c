/*Sa se reprezinte un numar din baza 10 in baza 2*/

#include <stdio.h>

int main() {
	int nr, i;
	scanf("%d", &nr);

	for (i = 31; i >= 0; i--) {
		if ((nr >> i) & 1 == 1)
			printf("1");
		else
			printf("0");
	}
	return 0;
}