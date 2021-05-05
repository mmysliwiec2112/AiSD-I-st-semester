#include <iostream>
#include "Zbior.h"
//Da sie to zrobic w odpowiedni sposob?
// Zbior &Zbior::operator=(const Zbior &source)
// {
//     Zbior temp;
//     if (this != &source)
//     {
//         for (int i = 0; i < size_; i++)
//         {
//             temp.tablica[i] = source.tablica[i];
//         }
//     }
//     return temp;
// }
Zbior::Zbior(int tab[], int size) : size_(size)
{
    if (size > maxSize_)
        std::cout << "Zbyt duza liczba elementow, maksymalna to 100" << std::endl;
    else
        for (int i = 0; i < size; i++)
        {
            tablica[i] = tab[i];
        }
}

void Zbior::dodajElement(int el)
{
    bool isEqual = 0;
    if (size_ + 1 > maxSize_)
        std::cout << "Nie ma miejsca w tablicy" << std::endl;
    else
    {
        for (int i = 0; i < size_ && !isEqual; i++)
        {
            if (el == tablica[i])
                isEqual = 1;
        }
    }
    if (!isEqual)
    {
        tablica[size_++] = el;
    }
}

void Zbior::usunElement(int id)
{
    if (size_ - 1 <= 0)
        std::cout << "Nie ma elementow w tablicy" << std::endl;
    else
    {
        for (int i = id; i < size_ - 1; i++)
        {
            tablica[i] = tablica[i + 1];
        }
        size_--;
    }
}

Zbior Zbior::sumaZbiorow(Zbior set)
{
    if (this != &set)
    {
        Zbior temp;
        bool isEqual = 0;
        for (int i = 0; i < size_; i++)
        {
            temp.tablica[i] = tablica[i];
        }
        temp.size_ = size_;
        //przechodzimy dla kazdego elementu jednej z tablic druga i szukamy powtorzen
        for (int i = 0; i < set.size_; i++)
        {
            temp.dodajElement(set.tablica[i]);
        }
        return temp;
    }
    else
        return *this;
}

Zbior Zbior::iloczynZbiorow(Zbior set)
{
    if (this != &set)
    {
        Zbior temp;
        bool isEqual = 0;
        for (int i = 0; i < size_ - 1; i++)
        {
            for (int j = 0; j < set.size_ && !isEqual; j++)
            {
                if (set.tablica[j] == tablica[i])
                    isEqual = 1;
            }
            if (isEqual)
            {
                temp.tablica[temp.size_++] = tablica[i];
                isEqual = 0;
            }
        }
        return temp;
    }
    else
        return *this;
}

Zbior Zbior::roznicaZbiorow(Zbior set)
{
    Zbior temp;
    if (this != &set)
    {
        bool isEqual = 0;
        for (int i = 0; i < size_; i++)
        {
            temp.tablica[i] = tablica[i];
        }
        temp.size_ = size_;
        std::cout << "temp: ";
        temp.wypisz();
        //przechodzimy dla kazdego elementu jednej z tablic druga i szukamy powtorzen
        for (int j = 0; j < temp.size_; j++)
        {
            for (int i = 0; i < set.size_ && !isEqual; i++)
            {
                if (temp.tablica[j] == set.tablica[i])
                {
                    // std::cout << "element ktory jest w obu tablicach: " << set.tablica[i] << " " << temp.tablica[j] << std::endl;
                    isEqual = 1;
                }
            }
            if (isEqual)
            {
                temp.usunElement(j);
                j--;
                isEqual = 0;
            }
        }
        std::cout << "temp: ";
    }
    else
        return temp;
}

bool Zbior::relacjaRownosci(Zbior set)
{
    bool isInBothSets = 1;
    for (int i = 0; i < set.size_ - 1; i++)
    {
        for (int j = 0; j < size_ - 1 && isInBothSets; j++)
        {
            if (tablica[j] != set.tablica[i])
                isInBothSets = 0;
        }
        return isInBothSets;
    }
}

bool Zbior::relacjaRownolicznosci(Zbior set)
{
    if (size_ = set.size_)
        return 1;
    else
        return 0;
}

bool Zbior::relacjaZawierania(Zbior set)
{
    int includes = 0;
    if (size_ > set.size_)
    {
        for (int i = 0; i < size_ - 1; i++)
        {
            for (int j = 0; j < set.size_ && includes - 1; j++)
            {
                if (tablica[j] == set.tablica[i])
                    includes++;
            }
            if (includes == set.size_)
                return true;
            else
                return false;
        }
    }
    return false;
}

void Zbior::wypisz()
{
    if (size_ == 0)
    {
        std::cout << "Brak elementow w zbiorze. " << std::endl;
    }
    else
    {
        std::cout << "[";
        for (int i = 0; i < size_; i++)
        {
            if (i == size_ - 1)
                std::cout << tablica[i] << "]" << std::endl;
            else
                std::cout << tablica[i] << ", ";
        }
    }
}

void Zbior::wyczysc()
{
    for (int i = 0; i < size_; i++)
    {
        tablica[i] = 0;
    }
    size_ = 0;
}