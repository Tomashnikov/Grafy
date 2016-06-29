#pragma once
class Zbior
{
	class Element{
	public:
		int nr;
		Element *next = 0;
	};
	Element *lista = 0;
public:
	Zbior();
	~Zbior();
	void scal(Zbior *a);
	bool cykl(int _wierzcholek);
	int podaj(int a);
	void dodaj(int a);
	int zdejmij();
	void kasuj();
	bool czy_null();
};

