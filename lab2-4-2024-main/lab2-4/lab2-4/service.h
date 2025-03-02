#pragma once
#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#include <stdlib.h>
#include "lista.h"

/*
* adauga o cheltuiala care nu exista in lista, sau adauga noua suma la cheltuiala deja existenta
*
* param v: lista in care se adauga (Lista)
* param zi: data in care e efectuata cheltuiala (int)
* param suma: suma cheltuielii (int)
* param tip: tipul chestuielii (string)
*
* returns: 1 daca cheltuiala a fost adaugata cu succes, 0 altfel
*/
int adauga_cheltuiala(Lista* v, int zi, int suma, char* tip);

/*
* cauta o cheltuiala din lista daca ea exista
*
* param v: lista in care se cauta (Lista)
* param zi: data in care e efectuata cheltuiala (int)
* param tip: tipul chestuielii (string)
*
* returns: -1 daca cheltuiala nu exista in lista, altfel returneaza pozitia pe care se afla
*/
int cauta_cheltuiala(Lista* v, int zi, char* tip);

/*
* sterge o cheltuiala din lista daca ea exista
*
* param v: lista din care se sterge (Lista)
* param zi: data in care e efectuata cheltuiala (int)
* param tip: tipul chestuielii (string)
*
* returns: 1 daca cheltuiala a fost stearsa cu succes, 0 altfel
*/
int sterge_cheltuiala(Lista* v, int zi, char* tip);

/*
* modifica o cheltuiala care exista in lista, actualizand suma
*
* param v: lista in care se adauga (Lista)
* param zi: data in care e efectuata cheltuiala (int)
* param suma: suma noua a cheltuielii (int)
* param tip: tipul chestuielii (string)
*
* returns: 1 daca cheltuiala a fost modificata cu succes, 0 altfel
*/
int modifica_cheltuiala(Lista* v, int zi, int suma_noua, char* tip);

/*
* filtreaza cheltuielile afisand doar cele care indeplinesc conditia data, in functie de zi, suma sau tip
*
* param v: lista in care se aplica filtrul (Lista)
* param optiune: indica tipul filtrului prin valoarea sa: 1 pt zi, 2 pt suma, 3 pt tip (int)
* param zi_sau_suma: retine ziua sau suma dupa care se filtreaza, in functie de optiune (int)
* param tip: tipul dupa care se filtreaza (string)
*
* returns: lista filtrata, sau lista intiala daca filtrele sunt vide (Lista)
*/
Lista filtreaza_cheltuieli(Lista* v, int optiune, int zi_sau_suma, char* tip);

/*
* sorteaza crescator lista de cheltuieli
*
* param v: lista in care se sorteaza (Lista)
* param optiune: indica tipul filtrului prin valoarea sa: 1 pt suma, 2 pt tip (int)
*
* returns: lista sortata
*/
Lista sorteaza_cheltuieli(Lista* v, int optiune);

void test_service_adauga_sterge();
void test_service_cauta();
void test_service_modifica();
void test_service_filtreaza();
void test_service_sorteaza();