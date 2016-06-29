#include "stdafx.h"
#include "Lista.h"

Lista::Lista(){}

Lista::~Lista(){}

void Lista::utworz(unsigned int _W, unsigned int _K, bool _skierowany)
{
	W = _W;
	K = _K;
	skierowany = _skierowany;
	lista = new Wierzcholek*[W];
	for (int i = 0; i < W; i++){
		lista[i] = NULL;
	}
}

void Lista::kasuj()
{
	Wierzcholek *tmp;
	for (int i = 0; i < W; i++){
		tmp = lista[i];
		while (tmp != NULL && lista[i]->nastepny != NULL){
			lista[i] = lista[i]->nastepny;
			delete tmp;
			tmp = *lista;
		}
		delete tmp;
		lista[i] = NULL;
	}
	delete[] lista;
}

bool Lista::wstaw(unsigned int a, unsigned int b, unsigned int waga){
	if (szukaj(a, b) != NULL)					//sprawdza czy istnieje
		return false;

	Wierzcholek *nowy = new Wierzcholek;		//tworzy nowy
	nowy->nr = b;
	nowy->waga = waga;
	nowy->nastepny = lista[a];
	lista[a] = nowy;							//wstawia
	if (!skierowany){							//jesli graf nieskierowany to wstawia symetryczn¹ krawêdz
		Wierzcholek *nowy2 = new Wierzcholek;
		nowy2->nr = a;
		nowy2->waga = waga;
		nowy2->nastepny = lista[b];
		lista[b] = nowy2;
	}
	return true;
}

Wierzcholek* Lista::szukaj(unsigned int a, unsigned int b){
	Wierzcholek *tmp = lista[a];
	while (tmp != NULL && tmp->nastepny != NULL){
		if (tmp->nr == b)
			return tmp;
		tmp = tmp->nastepny;
	}
	if (tmp != NULL && tmp->nr == b)
		return tmp;
	return NULL;
}

void Lista::wyswietl(){
	Wierzcholek *tmp;
	for (int i = 0; i < W; i++){
		cout << i << ": ";
		tmp = lista[i];
		if (tmp != NULL){
			while (tmp->nastepny != NULL){
				cout << "Nr: " << tmp->nr << " (" << tmp->waga << ") ";
				tmp = tmp->nastepny;
			}
			cout << "N: " << tmp->nr << " (" << tmp->waga << ")";
		}
		cout << endl;
	}
}

Kolejka* Lista::podaj(int wierzcholek){
	Kolejka* tab = new Kolejka();
	Wierzcholek* tmp = lista[wierzcholek];
	for (int i = 0; tmp != NULL; i++){
		Krawedz a(wierzcholek, tmp->nr, tmp->waga);
		tab->push(a);
		tmp = tmp->nastepny;
	}
	return tab;
}

Wierzcholek* Lista::podaj_s¹siada(int nr, int kolejnosc){
	Wierzcholek* out = lista[nr];
	for (int i = 0; out != NULL && i < kolejnosc; i++){
		out = out->nastepny;
	}
	return out;
}

unsigned int Lista::wierzcholki(){
	return W;
}

unsigned int Lista::krawedzie(){
	return K;
}