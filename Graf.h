#pragma once
class Graf
{
public:
	Graf();
	~Graf();
	virtual void utworz(unsigned int _W, unsigned int _K, bool _skierowany) = 0;
	virtual void kasuj() = 0;
	virtual bool wstaw(unsigned int r, unsigned int c, unsigned int waga) = 0;
	virtual void wyswietl() = 0;
	virtual unsigned int wierzcholki() = 0;
	virtual unsigned int krawedzie() = 0;
	virtual Kolejka* podaj(int wierzcholek) = 0;
	virtual Wierzcholek* podaj_s¹siada(int nr, int kolejnosc) = 0;
};

