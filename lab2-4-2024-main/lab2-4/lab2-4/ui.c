#pragma once
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#include <stdio.h>
#include "utils.h"
#include "service.h"

void test_all() {
	test_creeaza_distruge_cheltuiala();
	test_valideaza();
	test_copiaza();
	test_creeaza_distruge_lista();
	test_adauga_sterge_elem();
	test_copiaza_lista();
	test_service_adauga_sterge();
	test_service_cauta();
	test_service_modifica();
	test_service_filtreaza();
	test_service_sorteaza();
	test();
}

void afiseaza_toate_cheltuielile(Lista* v) {
	if (v->lungime == 0) {
		printf("Nu exista cheltuieli inregistrate!\n");
	}
	else {
		printf("Cheltuielie sunt:\n");
		for (int i = 0; i < v->lungime; i++) {
			Cheltuiala* c = get(v, i);
			printf("Data: %d; Suma: %d; Tipul: %s;\n", c->zi, c->suma, c->tip);
		}
	}
}

void afiseaza_toate_cheltuielile_invers(Lista* v) {
	if (v->lungime == 0) {
		printf("Nu exista cheltuieli inregistrate!\n");
	}
	else {
		printf("Cheltuielie sunt:\n");
		for (int i = v->lungime - 1; i >= 0; i--) {
			Cheltuiala* c = get(v, i);
			printf("Data: %d; Suma: %d; Tipul: %s;\n", c->zi, c->suma, c->tip);
		}
	}
}

void afiseaza_meniu() {
	printf("1. Adauga cheltuiala\n");
	printf("2. Modifica cheltuiala\n");
	printf("3. Sterge cheltuiala\n");
	printf("4. Filtrare cheltuieli\n");
	printf("5. Sortare cheltuieli\n");
	printf("6. Afisare cheltuieli\n");
	printf("7. Iesire\n");
}

void ui_adauga_cheltuiala(Lista* v) {
	int zi, suma;
	char tip[30], aux;
	printf("Introduceti data:\n");
	scanf_s("%d", &zi);
	printf("Introduceti suma cheltuita:\n");
	scanf_s("%d", &suma);
	scanf_s("%c", &aux, 1);
	printf("Introduceti tipul cheltuielii:\n");
	fgets(tip, 30, stdin);
	trimTrailing(tip);

	int succes = adauga_cheltuiala(v, zi, suma, tip);
	if (succes)
		printf("Cheltuiala a fost adaugata cu succes!\n");
	else
		printf("Cheltuiala este invalida!\n");
}

void ui_sterge_cheltuiala(Lista* v) {
	int zi;
	char tip[30], aux;
	printf("Introduceti data:\n");
	scanf_s("%d", &zi);
	scanf_s("%c", &aux, 1);
	printf("Introduceti tipul cheltuitelii:\n");
	fgets(tip, 30, stdin);
	trimTrailing(tip);

	int succes = sterge_cheltuiala(v, zi, tip);
	if (succes)
		printf("Cheltuiala a fost stearsa cu succes!\n");
	else
		printf("Cheltuiala nu exista!\n");
}

void ui_modifica_cheltuiala(Lista* v) {
	int zi, suma_noua;
	char tip[30], aux;
	printf("Introduceti data:\n");
	scanf_s("%d", &zi);
	printf("Introduceti suma noua:\n");
	scanf_s("%d", &suma_noua);
	scanf_s("%c", &aux, 1);
	printf("Introduceti tipul cheltuielii:\n");
	fgets(tip, 30, stdin);
	trimTrailing(tip);

	int succes = modifica_cheltuiala(v, zi, suma_noua, tip);
	if (succes)
		printf("Cheltuiala a fost modificata cu succes!\n");
	else
		printf("Cheltuiala nu exista!\n");
}

void ui_filtreaza_cheltuieli(Lista* v) {
	printf("1. Filtrare dupa zi\n");
	printf("2. Filtrare dupa suma\n");
	printf("3. Filtrare dupa tip\n");
	printf("Optiunea dvs pt filtare este:\n");
	int optiune, suma_sau_zi;
	char tip[30], aux;
	Lista lista_filtrata;
	scanf_s("%d", &optiune);
	if (optiune == 1 || optiune == 2) {
		if (optiune == 1) printf("Introduceti ziua pt filtru:\n");
		if (optiune == 2) printf("Introduceti suma pt filtru:\n");
		scanf_s("%d", &suma_sau_zi);
		strcpy_s(tip, sizeof(tip), "");
		lista_filtrata = filtreaza_cheltuieli(v, optiune, suma_sau_zi, tip);
	}
	if (optiune == 3) {
		scanf_s("%c", &aux, 1);
		printf("Introduceti tipul pt filtru:\n");
		fgets(tip, 30, stdin);
		trimTrailing(tip);
		suma_sau_zi = -1;
		lista_filtrata = filtreaza_cheltuieli(v, optiune, suma_sau_zi, tip);
	}
	afiseaza_toate_cheltuielile(&lista_filtrata);
	distruge_lista(&lista_filtrata);
}

void ui_sorteaza_cheltuieli(Lista* v) {
	printf("1. Sortare dupa suma\n");
	printf("2. Sortare dupa tip\n");
	printf("Optiunea dvs pt sortare este:\n");
	int optiune, sens;
	scanf_s("%d", &optiune);
	Lista lista_sortata = sorteaza_cheltuieli(v, optiune);
	printf("1. Sortare in ordine crescatoare\n");
	printf("2. Sortare in ordine descrescatoare\n");
	printf("Optiunea dvs pt sortare este:\n");
	scanf_s("%d", &sens);
	if (sens == 1)
		afiseaza_toate_cheltuielile(&lista_sortata);
	else
		afiseaza_toate_cheltuielile_invers(&lista_sortata);
	distruge_lista(&lista_sortata);
}

void run() {
	Lista lista_cheltuieli = creeaza_lista_goala();
	int gata = 0;

	adauga_cheltuiala(&lista_cheltuieli, 16, 1200, "altele");
	adauga_cheltuiala(&lista_cheltuieli, 28, 263, "mancare");
	adauga_cheltuiala(&lista_cheltuieli, 5, 55, "imbracaminte");
	adauga_cheltuiala(&lista_cheltuieli, 15, 90, "telefon&internet");
	adauga_cheltuiala(&lista_cheltuieli, 28, 72, "transport");
	adauga_cheltuiala(&lista_cheltuieli, 30, 90, "imbracaminte");
	adauga_cheltuiala(&lista_cheltuieli, 23, 150, "mancare");

	while (!gata) {
		afiseaza_meniu();
		int comanda;
		printf("Comanda dvs este: ");
		scanf_s("%d", &comanda);
		switch (comanda) {
		case 1:
			ui_adauga_cheltuiala(&lista_cheltuieli);
			printf("\n");
			break;
		case 2:
			ui_modifica_cheltuiala(&lista_cheltuieli);
			printf("\n");
			break;
		case 3:
			ui_sterge_cheltuiala(&lista_cheltuieli);
			printf("\n");
			break;
		case 4:
			ui_filtreaza_cheltuieli(&lista_cheltuieli);
			printf("\n");
			break;
		case 5:
			ui_sorteaza_cheltuieli(&lista_cheltuieli);
			printf("\n");
			break;
		case 6:
			afiseaza_toate_cheltuielile(&lista_cheltuieli);
			printf("\n");
			break;
		case 7:
			gata = 1;
			distruge_lista(&lista_cheltuieli);
			break;
		default:
			printf("Comanda e invalida!\n");
			printf("\n");
		}
	}
}
int main() {
	test_all();
	//run();
	_CrtDumpMemoryLeaks();
}
