#pragma once
#include "stdafx.h"
class Pomiar
{
public:
	double PCFreq = 0.0;
	__int64 CounterStart = 0;
	Pomiar();
	~Pomiar();
	void start();
	double podaj();
};

