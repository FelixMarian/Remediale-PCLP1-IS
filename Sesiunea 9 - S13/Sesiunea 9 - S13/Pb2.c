#include <stdio.h>
#include <stdlib.h>

/*
MOD fisiere TEXT

rt - citire, daca nu exista fisierul avem eroare
wt - doar scriere, daca nu exista, va fi creat, si daca exista, va fi suprascris
at - doar scriere, daca nu exista, va fi creat, si daca exista, se va scrie in continuarea lui
r+t - citire si scriere, daca nu exista se semnaleaza eroare
w+t - scriere si citire, daca nu exista se creaza, daca exista suprascris
a+t - scriere si citire, daca nu exista se creaza, daca exista se scrie la sfarsitul sau
w - write
a - append
t - text
w+t - write text
a+t - append text
*/

int main() {
	FILE* fisier;
	
	fisier = fopen("abc.txt", "w+t");
	if (fisier == NULL) {
		printf("Eroare la crearea fisierului");
	}
	/*
	citire:
	fgets()
	fscanf()

	scriere:
	fputs()
	fprintf()

	Formatat:
	fscanf()
	fprintf()

	Neformatat:
	fgets()
	fputs()
	
	a=10;
	fprintf(fisier,"Alex inavata la C si are nota %d", a);
	fputs("abc", fisier);

	char text[20];
	fgets(text, 5, fisier);

	*/


	//fclose(fisier);

	return 0;
}