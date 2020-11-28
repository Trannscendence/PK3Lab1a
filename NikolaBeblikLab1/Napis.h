#pragma once
#include <iostream>
#pragma warning(disable:4996)
class Napis
{
private:
	char* tablicaZnakow = NULL;
	int dlugosc = 0;

public:
	Napis();

	Napis(const char * napis)
	{
		this->dlugosc = strlen(napis);
		if (tablicaZnakow != NULL)
			delete[] tablicaZnakow;
		this->tablicaZnakow = new char[dlugosc + 1];
		strcpy(tablicaZnakow, napis);
	}
	Napis(const char znak)
	{
		this->dlugosc = 1;
		if (tablicaZnakow != NULL)
			delete[] tablicaZnakow;
		this->tablicaZnakow = new char[dlugosc + 1];
		tablicaZnakow[0] = znak;
	}
	Napis(const Napis& napis)
	{
		this->dlugosc = napis.dlugosc;
		if (tablicaZnakow != NULL)
			delete[] tablicaZnakow;
		this->tablicaZnakow = new char[dlugosc + 1];
		strcpy(tablicaZnakow, napis.tablicaZnakow);
	}


	~Napis()
	{
		if (tablicaZnakow != NULL)
			delete[] tablicaZnakow;
	}

	int zwrocDlugosc()
	{
		return dlugosc;
	};
	void wypisz()
	{
		for (int i=0; i<dlugosc;i++)
			std::cout << tablicaZnakow[i];

		std::cout << std::endl;
	};

	Napis operator=(const Napis& n) {
		this->dlugosc = n.dlugosc;
		if (tablicaZnakow != NULL)
			delete[] tablicaZnakow;
		this->tablicaZnakow = new char[dlugosc + 1];
		strcpy(tablicaZnakow, n.tablicaZnakow);
		return *this;
	}

	Napis polaczNapisy(const Napis& n)
	{
		int tempDlugosc = this->dlugosc + n.dlugosc;
		char * tempTablica = new char [tempDlugosc + 1];
		strcpy(tempTablica, this->tablicaZnakow);
		strcat(tempTablica, n.tablicaZnakow);
		return tempTablica;
	}

	Napis polaczNapisTablica(const char * napis)
	{
		int tempDlugosc = this->dlugosc + strlen(napis);
		char* tempTablica = new char[tempDlugosc + 1];
		strcpy(tempTablica, this->tablicaZnakow);
		strcat(tempTablica, napis);
		return tempTablica;
	}
	Napis polaczNapisZnak(const char znak)
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
};


