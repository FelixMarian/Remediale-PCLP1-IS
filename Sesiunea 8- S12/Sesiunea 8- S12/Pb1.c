#include <stdio.h>
#include <stdlib.h>

struct Nod {
	int value;
	struct Nod* next;
};

struct Nod* creareNod(int valoare) {
	struct Nod* nod_nou = (struct Nod*)malloc(sizeof(struct Nod));
	nod_nou->value = valoare;
	nod_nou->next = NULL;
	return nod_nou;
}

void adaugare_final(struct Nod** head, int valoare) {
	struct Nod* nod = creareNod(valoare);
	if (*head == NULL) {
		*head = nod;
		return;
	}
	struct Nod* nod_curent = *head;
	while (nod_curent->next != NULL) {
		nod_curent = nod_curent->next;
	}
	nod_curent->next = nod;
}

void adaugare_inceput(struct Nod** head, int valoare) {
	struct Nod* nod = creareNod(valoare);
	nod->next = *head;
	*head = nod;
}

void adaugare_ordonat(struct Nod** head, int valoare) {
	struct Nod* nod = creareNod(valoare);
	if (*head == NULL || (*head)->value >= valoare) {
		nod->next = *head;
		*head = nod;
		return;
	}
	struct Nod* nod_curent = *head;
	while (nod_curent->next != NULL && nod_curent->next->value < valoare) {
		nod_curent = nod_curent->next;
	}
	nod->next = nod_curent->next;
	nod_curent->next = nod;
}


void afisare(struct Nod* head) {
	struct Nod* nod_curent = head;
	while (nod_curent != NULL) {
		printf("%d \n", nod_curent->value);
		nod_curent = nod_curent->next;
	}
}

void stergere(struct Nod** head, int valoare) {
	//Caz lista goala
	if (*head == NULL) {
		printf("Lista e goala");
		return 0;
	}

	//Cazul in care nodul de sters e primul
	if ((*head)->value == valoare) {
		struct Nod* nod = *head;
		*head = (*head)->next;
		free(nod);
		return 0;
	}

	//Cazul in care nodul de sters e la mijloc sau la final

	//Parcurgem lista si cautam nodul cu valoarea dorita
	struct Nod* nod_current = *head;
	while (nod_current != NULL && nod_current->next->value != valoare) {
		nod_current = nod_current->next;
	}
	//Cazul in care nu se gaseste nodul cu valoarea dorita
	if (nod_current->next == NULL) {
		printf("Nod cu valorea %d nu exista", valoare);
		return 0;
	}

	//Stergerea nodului daca l-am gasit
	struct Nod* nod = nod_current->next;
	nod_current->next = nod_current->next->next;
	free(nod);
}


int main() {
	struct Nod* lista = NULL;

	adaugare_inceput(&lista, 15);
	adaugare_final(&lista, 20);
	adaugare_final(&lista, 35);
	adaugare_ordonat(&lista, 26);
	stergere(&lista, 20);

	afisare(lista);

	return 0;
}