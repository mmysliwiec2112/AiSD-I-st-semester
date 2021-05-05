#include <iostream>

//reukrencja ogonowa - wywolanie tej funkcji jest ostatnia instrukcja w funkcji 
// przesyla potrzebne wyniki do kolejnych wywolan funkcji
double power_rek(double x, unsigned int n, int result = 1)
{

    if (n == 0)
        return result;
    else
    {
        return power_rek(x, n - 1, result * x);
    }
}
double power_it(double x, unsigned int n)
{
    double temp = 1;
    for (int i = 0; i < n; i++)
    {
        temp = temp * x;
    }
    return temp;
}

int main()
{
    double podstawa;
    unsigned int wykladnik;
    std::cout << "Podaj podstawe potegi: " << std::endl;
    std::cin >> podstawa;
    std::cout << "Podaj wykladnik potegi:" << std::endl;
    std::cin >> wykladnik;
    std::cout << "Wynik podniesienia liczby " << podstawa << " w sposob rekurencyjny do potegi " << wykladnik << " wynosi: " << power_rek(podstawa, wykladnik) << std::endl;
    std::cout << "Wynik podniesienia liczby " << podstawa << " w sposob iteracyjny do potegi " << wykladnik << " wynosi: " << power_it(podstawa, wykladnik) << std::endl;
}