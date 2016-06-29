#pragma once
#include "stdafx.h"
class Lista : public Graf
{
protected:
	unsigned int W, K;
	Wierzcholek **lista;
	bool skierowany;
public:
	Lista();
	~Lista();
	void utworz(unsigned int _W, unsigned int _K, bool _skierowany);
	void kasuj();
	bool wstaw(unsigned int a, unsigned int b, unsigned int waga);
	Wierzcholek* szukaj(unsigned int a, unsigned int b);
	void wyswietl();
	unsigned int wierzcholki();
	unsigned int krawedzie();
	Kolejka* podaj(int wierzcolek);
	Wierzcholek* podaj_s¹siada(int nr, int kolejnosc);
};

