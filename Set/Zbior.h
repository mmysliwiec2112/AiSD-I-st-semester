#ifndef ZBIOR_H
#define ZBIOR_H
#include<string>

class Zbior{

private:
    int size_ = 0;
    int maxSize_ = 100;
    int tablica[100] = {0};
public:
    Zbior() = default;
    Zbior(int tab[], int size);
    ~Zbior() = default;
    // Zbior& operator=(const Zbior &source) = default;
    // Zbior& operator=(Zbior &&source) = default;

    void dodajElement(int el);
    void usunElement(int idx);
    Zbior sumaZbiorow(Zbior set);
    Zbior iloczynZbiorow(Zbior set);
    Zbior roznicaZbiorow(Zbior set);
    bool relacjaRownosci(Zbior set);
    bool relacjaRownolicznosci(Zbior set);
    bool relacjaZawierania(Zbior set);
    void wypisz();
    void wyczysc();


    
};

#endif