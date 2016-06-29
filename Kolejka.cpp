#include "stdafx.h"
#include "Kolejka.h"


Kolejka::Kolejka()
{
	tab = (Krawedz*)malloc(sizeof(Krawedz) * 10);
	wielkosc = 10;
	for (int i = 0; i < wielkosc; i++){
		tab[i] = Krawedz(0, 0, 0);
	}
	rozmiar = 0;
}

Kolejka::Kolejka(Kolejka &a){
	rozmiar = a.rozmiar;
	wielkosc = a.wielkosc;
	tab = a.tab;
}

Kolejka::~Kolejka()
{
	rozmiar = 0;
}

void Kolejka::push(Krawedz a){
	if (a.podajwage() == 0)
		return;
	if (rozmiar == wielkosc)
		zwieksz();
	tab[rozmiar] = a;
	int pozycja = rozmiar;

	while (tab[pozycja].podajwage() < tab[pozycja / 2].podajwage() && pozycja != 0){
		swap(tab[pozycja], tab[pozycja / 2]);
		pozycja = pozycja / 2;
	}
	rozmiar++;
}

Krawedz Kolejka::pop(){
	if (rozmiar == 0){
		Krawedz tmp(0, 0, 0);
		return tmp;
	}
	Krawedz tmp = tab[0];
	tab[0].reset();
	swap(tab[0], tab[rozmiar - 1]);
	int pozycja = 0;
	while (pozycja * 2 + 2 < rozmiar){
		if (tab[pozycja * 2 + 1].podajwage() > 0 && tab[pozycja * 2 + 2].podajwage() > 0 && tab[pozycja * 2 + 1].podajwage() < tab[pozycja * 2 + 2].podajwage()){
			if (tab[pozycja].podajwage() >= tab[pozycja * 2 + 1].podajwage()){
				swap(tab[pozycja], tab[pozycja * 2 + 1]);
			}
			pozycja = pozycja * 2 + 1;
		}
		else if (tab[pozycja * 2 + 1].podajwage() > 0 && tab[pozycja * 2 + 2].podajwage() > 0){
			if (tab[pozycja].podajwage() >= tab[pozycja * 2 + 2].podajwage()){
				swap(tab[pozycja], tab[pozycja * 2 + 2]);
			}
			pozycja = pozycja * 2 + 2;
		}
		else if (tab[pozycja * 2 + 1].podajwage() == 0){
			if (tab[pozycja].podajwage() >= tab[pozycja * 2 + 2].podajwage() && tab[pozycja * 2 + 2].podajwage() > 0){
				swap(tab[pozycja], tab[pozycja * 2 + 2]);
			}
			pozycja = pozycja * 2 + 2;
		}
		else if (tab[pozycja * 2 + 2].podajwage() == 0){
			if (tab[pozycja].podajwage() >= tab[pozycja * 2 + 1].podajwage() && tab[pozycja * 2 + 1].podajwage() > 0){
				swap(tab[pozycja], tab[pozycja * 2 + 1]);
			}
			pozycja = pozycja * 2 + 1;
		}
	}
	/*
	Krawedz tmp = tab[0];
	tab[0].reset();
	int pozycja = 0;

	while (pozycja * 2 < rozmiar){
	if (tab[pozycja * 2 + 1].podajwage() <= 0){
	swap(tab[pozycja], tab[pozycja * 2 + 2]);
	pozycja = pozycja * 2 + 2;
	}
	else if (tab[pozycja * 2 + 2].podajwage() <= 0){
	swap(tab[pozycja], tab[pozycja * 2 + 1]);
	pozycja = pozycja * 2 + 1;
	}
	else if (tab[pozycja * 2 + 1].podajwage() <= 0 && tab[pozycja * 2 + 2].podajwage() <= 0)
	break;
	else{
	if (tab[pozycja * 2 + 1].podajwage() < tab[pozycja * 2 + 2].podajwage()){
	swap(tab[pozycja], tab[pozycja * 2 + 1]);
	pozycja = pozycja * 2 + 1;
	}
	else{
	swap(tab[pozycja], tab[pozycja * 2 + 2]);
	pozycja = pozycja * 2 + 2;
	}
	}
	}
	for (int i = 0; i < rozmiar-1; i++){
	if (tab[i].podajwage()== 0){
	for (int j = i; j < rozmiar - 1; j++){
	tab[j] = tab[j + 1];
	}
	break;
	}
	}
	*/
	rozmiar--;
	if (wielkosc - rozmiar > 12)
		zmniejsz();
	return tmp;
}

void Kolejka::reset(){
	tab = (Krawedz*)realloc(tab, sizeof(Krawedz) * 10);
	wielkosc = 10;
	for (int i = 0; i < wielkosc; i++){
		tab[i] = Krawedz(0, 0, 0);
	}
	rozmiar = 0;
}

void Kolejka::zwieksz(){
	tab = (Krawedz*)realloc(tab, sizeof(Krawedz) * (wielkosc + 10));
	for (int i = wielkosc; i < wielkosc + 9; i++){
		tab[i] = Krawedz(0, 0, 0);
	}
	wielkosc += 10;
}

void Kolejka::zmniejsz(){
	tab = (Krawedz*)realloc(tab, sizeof(Krawedz) * (wielkosc - 10));
	wielkosc -= 10;
}

void Kolejka::wyswietl(){
	cout << "\\\\\\\\\\\\\\\\\\\poczatek\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\n";
	for (int i = 0; i < wielkosc; i++){
		cout << i << " ";
		tab[i].wyswietl();
	}
	cout << "\\\\\\\\\\\\\\\\\\\\\\\koniec\\\\\\\\\\\\\\\\\\\\\\\\\\\n";
}