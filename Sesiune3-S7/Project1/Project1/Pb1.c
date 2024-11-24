/*Sa se verifice daca numarul este putere a lui 2*/

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main() {
	int n, i;
	int k=0;
	scanf("%d", &n);

	for (i = 31; i >= 0; i--) {
		if ((1 & (n >> i)) == 1) k++;
	}

	if (k == 1) printf("%d este putere a lui 2", n);
	else printf("%d NU este putere a lui 2", n);
	return 0;

}