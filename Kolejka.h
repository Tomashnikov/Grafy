#pragma once
class Kolejka
{
	int rozmiar;
	int wielkosc;
	Krawedz *tab;
public:
	Kolejka();
	Kolejka(Kolejka &a);
	~Kolejka();
	void push(Krawedz a);
	Krawedz pop();
	void reset();
	void zwieksz();
	void zmniejsz();
	void wyswietl();
};

