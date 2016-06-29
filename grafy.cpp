// Grafy.cpp: Okreœla punkt wejœcia dla aplikacji konsoli.
//

#include "stdafx.h"


void Prime(Graf *a);
void Kruskal(Graf *a);
void Dijkstry(Graf *a, int p, int k);
void BF(Graf *a, int p, int k);
void print(int *p, int *d, int poczatek, int koniec, bool opcja);
void sciezka();
void MST();
void generuj(Graf *a, Graf *b, bool skierowany);
void wczytaj(Graf *a, string s, bool skierowany);
void generuj(Graf *a, Graf *b, bool skierowany, int &poczatek);
void wczytaj(Graf *a, bool skierowany, int &poczatek);

int _tmain(int argc, _TCHAR* argv[])
{
	/*
	Kolejka k;
	srand(time(NULL));
	int w;
	for (int i = 0; i < 10; i++){
		w = rand() % 9 + 1;
		Krawedz *tmp = new Krawedz(0, 0, w);
		k.push(*tmp);
	}
	k.wyswietl();
	Krawedz tmp;
	for (int i = 0; i < 12; i++){
	tmp=k.pop();
	k.wyswietl();
	}
	*/


	char opcja;
	while (true){
		cout << "Podaj opcje: \nD - Drzewo \nS - Sciezka \nK - Koniec\n";
		cin >> opcja;
		switch (opcja){
		case 'D': MST(); break;
		case 'S': sciezka(); break;
		case 'K': return 0;
		default: break;
		}
	}
}

void Prime(Graf *a){
	Pomiar czas;
	czas.start();
	int wierzcholki = a->wierzcholki();
	int krawedzie = a->krawedzie();
	Kolejka *pom = new Kolejka();
	Kolejka *Q = new Kolejka();
	bool *odwiedzone = new bool[wierzcholki];
	for (int i = 0; i < wierzcholki; i++){
		odwiedzone[i] = false;
	}
	/*
	for (int i = 0; i < wierzcholki; i++){
	if (odwiedzone[i])
	cout <<i<< " t\n";
	else
	cout <<i<< " n\n";
	}
	cout << endl;
	*/
	int suma = 0;
	int v = 0;
	bool koniec = false;
	Krawedz tmp;
	Krawedz *drzewo = new Krawedz[krawedzie];
	odwiedzone[v] = true;
	for (int i = 0; i < wierzcholki - 1; i++){
		for (int j = 0; j < wierzcholki; j++){					//Tworzenie kolejki krawedzie z wierzcholków nalerzacych do drzewa
			if (odwiedzone[j]) {
				pom = a->podaj(j);
				while (true){
					tmp = pom->pop();
					if (tmp.podajwage() == 0)
						break;
					Q->push(tmp);
				}
				pom->reset();
			}
		}
		do{
			tmp = Q->pop();
			//Q->wyswietl();
		} while (odwiedzone[tmp.podaj_w2()]);
		odwiedzone[tmp.podaj_w2()] = true;
		v = tmp.podaj_w2();
		drzewo[i] = tmp;
		suma += tmp.podajwage();
		Q->reset();

		/*for (int i = 0; i < wierzcholki; i++){
		if (odwiedzone[i])
		cout <<i<< " t\n";
		else
		cout <<i<< " n\n";
		}
		cout << endl;*/

	}
	for (int i = 0; i<wierzcholki - 1; i++){
		drzewo[i].wyswietl();
	}
	cout << suma << endl;
	cout << czas.podaj() << endl << endl;
}

void Kruskal(Graf *a){
	Pomiar czas;
	czas.start();
	int suma = 0;
	int wierzcholki = a->wierzcholki();
	Kolejka *Q = new Kolejka();
	Kolejka *tmp = new Kolejka();
	Krawedz *drzewo = new Krawedz[wierzcholki];
	Krawedz kr;
	Zbior **z = new Zbior*[wierzcholki];
	for (int i = 0; i < wierzcholki; i++){
		z[i] = new Zbior();
		z[i]->dodaj(i);
	}


	/*for (int i = 0; i < wierzcholki; i++){
	for (int j = 0; z[i]->podaj(j) !=-1; j++){
	cout << z[i]->podaj(j) << " ";
	}
	cout << endl;
	}
	cout << "//////////////////////\n";*/

	for (int i = 0; i < wierzcholki; i++){
		tmp = a->podaj(i);
		while (true){
			kr = tmp->pop();
			if (kr.podajwage() == 0)
				break;
			Q->push(kr);
		}
		tmp->reset();
	}
	int i = 0;
	while (i < wierzcholki - 1){
		kr = Q->pop();
		if (!z[kr.podaj_w1()]->cykl(kr.podaj_w2())){
			drzewo[i] = kr;
			i++;
			suma += kr.podajwage();
			if (i < wierzcholki - 1){
				z[kr.podaj_w1()]->scal(z[kr.podaj_w2()]);

				/*		for (int i = 0; i < wierzcholki; i++){
				for (int j = 0; z[i]->podaj(j)!=-1; j++){
				cout << z[i]->podaj(j)<<" ";
				}
				cout << endl;
				}
				*/

				z[kr.podaj_w2()]->kasuj();
				for (int i = 0; i < wierzcholki; i++){
					if (z[i]->czy_null())
						z[i] = z[kr.podaj_w1()];
				}

				/*
				for (int i = 0; i < wierzcholki; i++){
				for (int j = 0; z[i]->podaj(j) != -1; j++){
				cout << z[i]->podaj(j) << " ";
				}
				cout << endl;
				}
				cout << "//////////////////////\n";*/

			}
		}
	}
	for (int i = 0; i < wierzcholki - 1; i++){
		drzewo[i].wyswietl();
	}
	cout << suma << endl;
	//cout << "***********************************************************\n";
	cout << czas.podaj() << endl << endl;
}

void Dijkstry(Graf *a, int poczatek, int koniec){
	int wierzcho³ki = a->wierzcholki();
	int *d = new int[wierzcho³ki];
	int *p = new int[wierzcho³ki];
	int j, k;
	Wierzcholek *pw = new Wierzcholek();
	bool *czy_odwiedzony = new bool[wierzcho³ki];
	for (int i = 0; i < wierzcho³ki; i++){
		d[i] = MAXINT;
		p[i] = -1;
		czy_odwiedzony[i] = false;
	}
	d[poczatek] = 0;
	for (int i = 0; i < wierzcho³ki; i++)
	{
		j = 0;
		while (czy_odwiedzony[j])
			j++;

		k = j++;
		while (j < wierzcho³ki){
			if (!czy_odwiedzony[j] && (d[j] < d[k]))
				k = j;
			j++;
		}
		czy_odwiedzony[k] = true;

		for (int l = 0; l<wierzcho³ki; l++){
			pw = a->podaj_s¹siada(k, l);
			if (pw != NULL){
				if (!czy_odwiedzony[pw->nr] && (d[pw->nr] > d[k] + pw->waga)){
					d[pw->nr] = d[k] + pw->waga;
					p[pw->nr] = k;
				}
			}
		}
	}
	print(p, d, poczatek, koniec, true);
}

void BF(Graf *a, int pocz¹tek, int koniec){
	Pomiar czas;
	czas.start();
	int wierzcho³ki = a->wierzcholki();
	int *d = new int[wierzcho³ki];
	int *p = new int[wierzcho³ki];
	for (int i = 0; i < wierzcho³ki; i++){
		d[i] = MAXINT;
		p[i] = -1;
	}
	bool test;
	Wierzcholek *pv;

	d[pocz¹tek] = 0;
	for (int i = 1; i < wierzcho³ki; i++){
		test = true;
		for (int x = 0; x < wierzcho³ki; x++){
			pv = a->podaj_s¹siada(x, 0);
			for (int k = 1; pv; k++){
				if (d[x] != MAXINT&&d[pv->nr] > d[x] + pv->waga){
					test = false;
					d[pv->nr] = d[x] + pv->waga;
					p[pv->nr] = x;
				}
				pv = a->podaj_s¹siada(x, k);
			}
		}
	}
	for (int x = 0; x < wierzcho³ki; x++){
		pv = a->podaj_s¹siada(x, 0);
		for (int k = 1; pv; k++){
			if (d[pv->nr] > d[x] + pv->waga){
				print(p, (int*)d, pocz¹tek, koniec, false);
				return;
			}
			pv = a->podaj_s¹siada(x, k);
		}
	}
	print(p, (int*)d, pocz¹tek, koniec, true);
	return;
}

void print(int *p, int *d, int poczatek, int koniec, bool opcja){
	if (!opcja){
		cout << "B³¹d!";
		return;
	}
	Zbior tmp;
	for (int i = koniec; i != poczatek; i = p[i]){
		tmp.dodaj(p[i]);
	}
	cout << "Droga: ";
	int nr;
	while (true){
		nr = tmp.zdejmij();
		if (nr == -1)
			break;
		cout << nr << " -> ";
	}
	cout << koniec << endl << "Koszt: " << d[koniec] << endl << endl;
}

void MST(){
	Lista *lista = new Lista();
	Macierz *macierz = new Macierz();
	char opcja;
	string s;
	while (true){
		cout << "Podaj opcje: \nG - Generuj \nW - Wczytaj \nP - Prime \nK - Kruskal \nX - wstecz\n";
		cin >> opcja;
		switch (opcja){
		case 'G': generuj(lista, macierz, false); break;
		case 'W': cout << "Podaj nazwe pliku: "; cin >> s; wczytaj(lista, s, false); wczytaj(macierz, s, false); break;
		case 'P': Prime(lista); Prime(macierz); break;
		case 'K': Kruskal(lista); Kruskal(macierz); break;
		case 'X': return;
		default: break;
		}
	}
}

void sciezka(){
	Lista *lista = new Lista();
	Macierz *macierz = new Macierz();
	int poczatek = 0;
	char opcja;
	string s;
	Pomiar czas;
	while (true){
		cout << "Podaj opcje: " << endl;
		cout << "G - Generuj" << endl;
		cout << "W - Wczytaj" << endl;
		cout << "D - Dijkstry" << endl;
		cout << "B - BF" << endl;
		cout << "X - Wstecz" << endl;;
		cin >> opcja;
		switch (opcja){
		case 'G': generuj(lista, macierz, false, poczatek); break;
		case 'W': cout << "Podaj nazwe pliku: "; cin >> s; wczytaj(lista, false, poczatek); wczytaj(macierz, false, poczatek); break;
		case 'D': czas.start(); for (int i = 0; i < lista->wierzcholki(); i++) Dijkstry(lista, poczatek, i); cout << czas.podaj() << endl << endl;
			czas.start(); for (int i = 0; i < lista->wierzcholki(); i++) Dijkstry(macierz, poczatek, i); cout << czas.podaj() << endl << endl; break;
		case 'B': czas.start(); for (int i = 0; i < lista->wierzcholki(); i++) BF(lista, poczatek, i); cout << czas.podaj() << endl << endl;
			czas.start(); for (int i = 0; i < lista->wierzcholki(); i++) BF(macierz, poczatek, i); cout << czas.podaj() << endl << endl; break;
		case 'X': return;
		default: break;
		}
	}
}

void wczytaj(Graf *a, string s, bool skierowany){
	int wierzcholki, krawedzie, x, y, w;
	fstream plik;
	plik.open(s);
	plik >> krawedzie;
	plik >> wierzcholki;
	a->utworz(wierzcholki, krawedzie, skierowany);
	for (int i = 0; i < krawedzie; i++){
		plik >> x >> y >> w;
		a->wstaw(x, y, w);
	}
	a->wyswietl();
}

void wczytaj(Graf *a, bool skierowany, int &poczatek){
	cout << "Podaj nazwê pliku: ";
	string nazwa;
	int wierzcholki, krawedzie, x, y, w;
	cin >> nazwa;
	fstream plik;
	plik.open(nazwa);
	plik >> krawedzie;
	plik >> wierzcholki;
	plik >> poczatek;
	a->utworz(wierzcholki, krawedzie, skierowany);
	for (int i = 0; i < krawedzie; i++){
		plik >> x >> y >> w;
		a->wstaw(x, y, w);
	}
}

void generuj(Graf *a, Graf *b, bool skierowany){
	a->kasuj();
	b->kasuj();
	cout << "Podaj ilosc wierzcholkow: ";
	int w;
	cin >> w;
	cout << "Podaj gestosc krawedzi: ";
	int k;
	cin >> k;
	double l = k;
	l /= 100;
	int n = (w*(w - 1)) / 2;
	l *= n;
	k = l;
	if (k < w - 1){
		a->utworz(w, w - 1, false);
		b->utworz(w, w - 1, false);
	}
	else{
		a->utworz(w, k, skierowany);
		b->utworz(w, k, skierowany);
	}
	bool *odwiedzone = new bool[w];
	for (int i = 0; i < w; i++)
		odwiedzone[i] = false;
	int x, y, waga;
	srand(time(NULL));


	x = rand() % w;
	odwiedzone[x] = true;
	do{
		y = rand() % w;
	} while (x == y);
	odwiedzone[y] = true;
	waga = rand() % 9 + 1;
	a->wstaw(x, y, waga);
	b->wstaw(x, y, waga);
	for (int i = 0; i < w - 2; i++){
		x = rand() % w;
		do{
			y = rand() % w;
		} while (odwiedzone[x] == odwiedzone[y]);
		waga = rand() % 10 + 1;
		odwiedzone[y] = true;
		odwiedzone[x] = true;
		a->wstaw(x, y, waga);
		b->wstaw(x, y, waga);
	}
	for (int i = w - 1; i < k; i++){
		do{
			x = rand() % w;
			do{
				y = rand() % w;
			} while (x == y);
			waga = rand() % 10 + 1;
			b->wstaw(x, y, waga);
		} while (!a->wstaw(x, y, waga));
	}
	a->wyswietl();
	b->wyswietl();
}

void generuj(Graf *a, Graf *b, bool skierowany, int &poczatek){
	a->kasuj();
	b->kasuj();
	cout << "Podaj ilosc wierzcholkow: ";
	int w;
	cin >> w;
	cout << "Podaj gestosc krawedzi: ";
	int k;
	cin >> k;
	cout << "Podaj wierzcho³ek startowy: ";
	cin >> poczatek;
	double l = k;
	l /= 100;
	int n = (w*(w - 1)) / 2;
	l *= n;
	k = l;
	if (k < w - 1){
		a->utworz(w, w - 1, false);
		b->utworz(w, w - 1, false);
	}
	else{
		a->utworz(w, k, skierowany);
		b->utworz(w, k, skierowany);
	}
	bool *odwiedzone = new bool[w];
	for (int i = 0; i < w; i++)
		odwiedzone[i] = false;
	int x, y, waga;
	srand(time(NULL));


	x = rand() % w;
	odwiedzone[x] = true;
	do{
		y = rand() % w;
	} while (x == y);
	odwiedzone[y] = true;
	waga = rand() % 9 + 1;
	a->wstaw(x, y, waga);
	b->wstaw(x, y, waga);
	for (int i = 0; i < w - 2; i++){
		x = rand() % w;
		do{
			y = rand() % w;
		} while (odwiedzone[x] == odwiedzone[y]);
		waga = rand() % 9 + 1;
		odwiedzone[y] = true;
		odwiedzone[x] = true;
		a->wstaw(x, y, waga);
		b->wstaw(x, y, waga);
	}
	for (int i = w - 1; i < k; i++){
		do{
			x = rand() % w;
			do{
				y = rand() % w;
			} while (x == y);
			waga = rand() % 9 + 1;
			b->wstaw(x, y, waga);
		} while (!a->wstaw(x, y, waga));
	}
	a->wyswietl();
	b->wyswietl();
}
