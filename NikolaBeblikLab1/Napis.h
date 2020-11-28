#pragma once
#ifndef NAPIS_H
#define NAPIS_H
#include <iostream>
#pragma warning(disable:4996)
class Napis
{
private:
	char* tablicaZnakow = NULL;
	int dlugosc = 0;

public:
	Napis();
	Napis(const char* napis);
	Napis(const char znak);
	Napis(const Napis& napis);
	~Napis();

	int zwrocDlugosc();

	Napis operator=(const Napis& n);
	void wypisz();
	Napis polaczNapisy(const Napis& n);
	Napis polaczNapisTablica(const char* napis);
	Napis polaczNapisZnak(const char znak);
	void zmienZnak(const char znak, const int miejsce);
};
#endif