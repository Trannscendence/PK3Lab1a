#include <iostream>
#include <string>
#include "Napis.h"
#pragma warning(disable:4996)

int main()
{
    Napis napis = Napis("napis");
    char str[] = "hello";
    Napis hello = Napis(str);
    char znak = '!';
    Napis znakNapis = Napis(znak);
    Napis kopiaHello = Napis(hello);
    Napis przypisanyNapis = napis;
    std::cout << "Wypisz napis: ";
    napis.wypisz();

    std::cout << "Dlugosc napisu: ";
    std::cout << napis.zwrocDlugosc() << std::endl;

    std::cout << "Wypisz hello: ";
    hello.wypisz();

    std::cout << "Wypisz znak: ";
    znakNapis.wypisz();

    std::cout << "Polacz Napisy napis i hello: ";
    Napis polaczoneNapisy = napis.polaczNapisy(hello);
    polaczoneNapisy.wypisz();

    std::cout << "Polacz Napis hello i znak '!': ";
    Napis NapisOrazZnak = hello.polaczNapisZnak(znak);
    NapisOrazZnak.wypisz();

    std::cout << "Polacz Napis napis i ciag znakow 'hello': ";
    Napis NapisOrazCiag = napis.polaczNapisTablica(str);
    NapisOrazCiag.wypisz();
    std::cout << "Dlugosc Napisu powyzej: ";
    std::cout << NapisOrazCiag.zwrocDlugosc() << std::endl;

    std::cout << "Wypisz przypisany napis: ";
    przypisanyNapis.wypisz();
    std::cout << "Zmien znak w napisie hello na heblo: " << std::endl;
    hello.zmienZnak('b', 3);
    std::cout << "Zmien znak ktory nie istnieje (6): " << std::endl;
    hello.zmienZnak('b', 6);
    std::cout << "Zmien znak ktory nie istnieje (0): " << std::endl;
    hello.zmienZnak('b', 0);
    return 0;
}