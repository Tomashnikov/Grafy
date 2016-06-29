#include "stdafx.h"
#include "Zbior.h"


Zbior::Zbior()
{
}

Zbior::~Zbior()
{
}

void Zbior::scal(Zbior *a){
	int tmp;
	tmp = a->podaj(0);
	for (int i = 1; tmp != -1; i++){
		Element *nowy = new Element();
		nowy->nr = tmp;
		nowy->next = lista;
		lista = nowy;
		tmp = a->podaj(i);
	}
}

bool Zbior::cykl(int wierzcholek){
	Element *tmp = new Element();
	tmp = lista;
	bool out = false;
	while (tmp != NULL){
		if (tmp->nr == wierzcholek){
			out = true;
			break;
		}
		tmp = tmp->next;
	}
	return out;
}

int Zbior::podaj(int a){
	Element *tmp = new Element();
	tmp = lista;
	for (int i = 0; i < a; i++){
		if (tmp == NULL){
			return -1;
		}
		tmp = tmp->next;
	}
	if (tmp == NULL){
		return -1;
	}
	return tmp->nr;
}

void Zbior::dodaj(int a){
	Element *tmp = new Element();
	tmp->nr = a;
	tmp->next = lista;
	lista = tmp;
}

int Zbior::zdejmij(){
	Element *tmp = new Element();
	tmp = lista;
	if (lista == NULL){
		return -1;
	}
	lista = lista->next;
	return tmp->nr;
}

void Zbior::kasuj(){
	Element *tmp = new Element();
	while (lista != NULL){
		tmp = lista;
		lista = lista->next;
		delete tmp;
	}
}

bool Zbior::czy_null(){
	if (lista == NULL)
		return true;
	return false;
}