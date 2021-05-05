#include<iostream>
int BinarySearch(int tab[], int x, int beg, int end)
{
    if(beg > end)
        return -1;
    else if(x == tab[(beg + end)/2])
        return (beg+end)/2 + 1;
    else if(x > tab[end/2])
        return BinarySearch(tab,x,(beg + end)/2 + 1,end);
    else if(x < tab[end/2])
        return BinarySearch(tab,x,beg,beg + (end - beg)/2 - 1);

}
int main()
{
    int tablica[] = {2,4,7,9,10,12,15,22,23};
    int szukana = 0;
    int indeks = 0;
    std::cout<<"Podaj wartosc elementu, ktorego indeks jest Ci potrzebny: "<<std::endl;
    std::cin>>szukana;
    if((indeks = BinarySearch(tablica, szukana, 0, 8)) == -1)
    {
        std::cout<<"Brak podanej liczby w tablicy. ";
        exit(0);
    }
    std::cout<<"Indeks szukanego elementu wynosi = "<<indeks<<std::endl;

    return 0;
}