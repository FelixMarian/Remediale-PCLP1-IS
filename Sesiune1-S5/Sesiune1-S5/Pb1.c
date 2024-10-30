/*3. Să se scrie un program în C care citește de la tastatură un şir de numere încheiat cu
numărul 0 şi afișează suma numerelor introduse.*/


#include <stdio.h>

int main() {
	int n, S=0;
	scanf("%d", &n);
	S = S + n;
	while (n != 0) {
		scanf("%d", &n);
		S = S + n;
	}

	printf("Suma este %d", S);

	return 0;
}