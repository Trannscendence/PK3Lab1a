#include "Napis.h"
#include <iostream>
#pragma warning(disable:4996)
Napis::Napis(const char* napis)
{
	this->dlugosc = strlen(napis);
	if (tablicaZnakow != NULL)
		delete[] tablicaZnakow;
	this->tablicaZnakow = new char[dlugosc + 1];
	strcpy(tablicaZnakow, napis);
}
Napis::Napis(const char znak)
{
	this->dlugosc = 1;
	if (tablicaZnakow != NULL)
		delete[] tablicaZnakow;
	this->tablicaZnakow = new char[dlugosc + 1];
	tablicaZnakow[0] = znak;
}
Napis::Napis(const Napis& napis)
{
	this->dlugosc = napis.dlugosc;
	if (tablicaZnakow != NULL)
		delete[] tablicaZnakow;
	this->tablicaZnakow = new char[dlugosc + 1];
	strcpy(tablicaZnakow, napis.tablicaZnakow);
}


Napis::~Napis()
{
	if (tablicaZnakow != NULL)
		delete[] tablicaZnakow;
}

int Napis::zwrocDlugosc()
{
	return dlugosc;
};
void Napis::wypisz()
{
	for (int i = 0; i < dlugosc; i++)
		std::cout << tablicaZnakow[i];

	std::cout << std::endl;
};

Napis Napis::operator=(const Napis& n) {
	this->dlugosc = n.dlugosc;
	if (tablicaZnakow != NULL)
		delete[] tablicaZnakow;
	this->tablicaZnakow = new char[dlugosc + 1];
	strcpy(tablicaZnakow, n.tablicaZnakow);
	return *this;
}

Napis Napis::polaczNapisy(const Napis& n)
{
	int tempDlugosc = this->dlugosc + n.dlugosc;
	char* tempTablica = new char[tempDlugosc + 1];
	strcpy(tempTablica, this->tablicaZnakow);
	strcat(tempTablica, n.tablicaZnakow);
	return tempTablica;
}

Napis Napis::polaczNapisTablica(const char* napis)
{
	int tempDlugosc = this->dlugosc + strlen(napis);
	char* tempTablica = new char[tempDlugosc + 1];
	strcpy(tempTablica, this->tablicaZnakow);
	strcat(tempTablica, napis);
	return tempTablica;
}
Napis Napis::polaczNapisZnak(const char znak)
{
	char cToStr[2];
	cToStr[1] = '\0';
	cToStr[0] = znak;
	int tempDlugosc = this->dlugosc + 1;
	char* tempTablica = new char[tempDlugosc + 1];
	strcpy(tempTablica, this->tablicaZnakow);
	strcat(tempTablica, cToStr);
	return tempTablica;
}

Napis Napis::zmienZnak(const char znak, const int miejsce)
{
	char cToStr[2];
	cToStr[1] = '\0';
	cToStr[0] = znak;
	if (miejsce > dlugosc || miejsce < 1)
	{
		std::cout << "Nie ma takiego miejsca w Napisie!" << std::endl;
	}
	else
	{
		std::cout << "Litera na " << miejsce << " miejscu: ";
		std::cout << this->tablicaZnakow[miejsce-1] << std::endl;
		std::cout << "Nowy napis: ";
		this->tablicaZnakow[miejsce - 1] = znak;
	}
	return tablicaZnakow;
}