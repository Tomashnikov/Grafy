#pragma once
class Krawedz
{
	int w1;
	int w2;
	int waga;
public:
	Krawedz();
	Krawedz(int a, int b, int w);
	int podajwage();
	int podaj_w1();
	int podaj_w2();
	~Krawedz();
	void operator =(Krawedz a);
	void reset();
	void wyswietl();
};

