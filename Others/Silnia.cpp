#include <iostream>
int silnia(int n)
{
    int res = 1;
    if(n==1)
        return 1;
    else
    {
        res = n * silnia(n-1);
    }
    
}
int main()
{
    int liczba;
    int wynik;
    std::cout<<"Podaj liczbe ktorej silnie chcesz policzyc: "<<std::endl;
    std::cin>>liczba;
    wynik = silnia(liczba);
    std::cout<<"Wynik obliczen = "<<wynik<<std::endl;
    return 0;
}