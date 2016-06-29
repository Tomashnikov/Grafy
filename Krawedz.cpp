#include "stdafx.h"
#include "Krawedz.h"


Krawedz::Krawedz(int a, int b, int w)
{
	w1 = a;
	w2 = b;
	waga = w;
}

Krawedz::Krawedz(){
	w1 = 0;
	w2 = 0;
	waga = 0;
}

int Krawedz::podaj_w1(){
	return w1;
}

int Krawedz::podaj_w2(){
	return w2;
}

Krawedz::~Krawedz()
{
}

int Krawedz::podajwage(){
	return waga;
}

void Krawedz::operator=(Krawedz a){
	w1 = a.w1;
	w2 = a.w2;
	waga = a.waga;
}

void Krawedz::reset(){
	w1 = 0;
	w2 = 0;
	waga = 0;
}

void Krawedz::wyswietl(){
	cout << w1 << " " << w2 << " " << waga << endl;
}