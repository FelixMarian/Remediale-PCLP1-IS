#include <stdio.h>
#include <stdlib.h>

int main() {
	int* v;
	int n; //Dimensiune
	scanf("%d", &n);
	v = (int*)malloc(n * sizeof(int));
	for (int i = 0; i < n; i++)
	{
		scanf("%d", (v+i));
	}
	for (int i = 0; i < n; i++) {
		printf("%d ", *(v+i));
	}
}