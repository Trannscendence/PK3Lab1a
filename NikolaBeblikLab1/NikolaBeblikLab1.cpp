#include <iostream>
#include <string>
#include "Napis.h"

int main()
{
    Napis litera = Napis("a");
    litera.wypisz();
    std::cout << litera.zwrocDlugosc() << std::endl;
    char str[] = "hello";
    Napis hello = Napis(str);
    hello.wypisz();
    return 0;
}