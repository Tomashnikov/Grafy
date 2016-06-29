#include "stdafx.h"
#include "Macierz.h"

Macierz::Macierz(){
}

void Macierz::utworz(unsigned int _W, unsigned int _K, bool _skierowany)
{
	W = _W;
	K = _K;
	skierowany = _skierowany;
	macierz = new int*[W];
	for (int i = 0; i < W; i++){
		macierz[i] = new int[W];
		for (int j = 0; j < W; j++){
			macierz[i][j] = 0;
		}
	}
}

Macierz::~Macierz()
{
}

void Macierz::kasuj(){
	for (int i = 0; i < W; i++){
		delete[] macierz[i];
	}
	delete[] macierz;
}

bool Macierz::wstaw(unsigned int r, unsigned int c, unsigned int waga){
	if (macierz[r][c]>0)				//czy krawêdz istnieje
		return false;
	macierz[r][c] = waga;
	if (!skierowany)					//czy graf skierowany jesli nie to krawêdz symetryczna
		macierz[c][r] = waga;
	return true;
}

void Macierz::wyswietl(){
	for (int i = 0; i < W; i++){
		for (int j = 0; j < W; j++){
			cout << macierz[i][j];
		}
		cout << endl;
	}
	cout << endl;
}

unsigned int Macierz::wierzcholki(){
	return W;
}

unsigned int Macierz::krawedzie(){
	return K;
}

Kolejka* Macierz::podaj(int wierzcholek){
	Kolejka* tab = new Kolejka();
	for (int i = 0; i < W; i++){
		Krawedz a(wierzcholek, i, macierz[wierzcholek][i]);
		tab->push(a);
	}
	return tab;
}

Wierzcholek* Macierz::podaj_s¹siada(int nr, int kolejnosc){
	if (kolejnosc >= W)
		return NULL;
	Wierzcholek *out = new Wierzcholek();
	int pozycja = 0;
	for (int i = 0; i < W; i++){
		if (macierz[nr][i] != 0){
			if (pozycja == kolejnosc){
				out->nr = i;
				out->waga = macierz[nr][i];
				return out;
			}
			pozycja++;
		}
	}
	return NULL;
}