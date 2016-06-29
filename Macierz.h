#pragma once
#include "stdafx.h"
class Macierz :public Graf
{
protected:
	unsigned int W, K;
	int **macierz;
	bool skierowany;
public:
	Macierz();
	void utworz(unsigned int _W, unsigned int _K, bool _skierowany);
	~Macierz();
	void kasuj();
	bool wstaw(unsigned int r, unsigned int c, unsigned int waga);
	void wyswietl();
	unsigned int wierzcholki();
	unsigned int krawedzie();
	Kolejka* podaj(int wierzcholek);
	Wierzcholek* podaj_s¹siada(int nr, int kolejnosc);
};

