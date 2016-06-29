#include "stdafx.h"
#include "Pomiar.h"


Pomiar::Pomiar()
{
}


Pomiar::~Pomiar()
{
}

void Pomiar::start(){
	LARGE_INTEGER li;
	if (!QueryPerformanceFrequency(&li))
		cout << "QueryPerformanceFrequency failed!\n";

	PCFreq = double(li.QuadPart) / 1000.0;

	QueryPerformanceCounter(&li);
	CounterStart = li.QuadPart;
}

double Pomiar::podaj(){
	LARGE_INTEGER li;
	QueryPerformanceCounter(&li);
	return double(li.QuadPart - CounterStart) / PCFreq;
}