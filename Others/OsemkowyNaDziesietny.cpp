#include <iostream>
#include <vector>
#include <string>
#include <cmath>

int main()
{
    std::string liczba_osemkowa;
    std::cout << "Podaj liczbe w systemie osemkowym, ktora chcesz przekonwertowac na dziesietny: " << std::endl;
    std::cin >> liczba_osemkowa;
    int suma = 0;
    int rozmiar = liczba_osemkowa.size();

    for (auto i = 0; i < rozmiar; i++)
    {
        int potega = pow(8, i);
        int cyfra_osemkowa = (liczba_osemkowa[rozmiar - i - 1] - '0');
        if(cyfra_osemkowa > 7)
        {
            std::cout<<"Podales cyfre wieksza niz 7, ktorej nie ma w systemie osemkowym.22"<<std::endl;
            exit(0);
        }
        suma = suma + (cyfra_osemkowa * potega);
        std::cout << "Cyfra liczby w postaci osemkowej: " << cyfra_osemkowa << " wynik pomnozenia przez kolejna potege osemki: " << (cyfra_osemkowa * pow(8, i))<<std::endl<< "Aktualna suma: " << suma << std::endl;
    }
    std::cout << "Podana liczba w systemie dziesiętnym ma postać: " << suma << std::endl;

    return 0;
}