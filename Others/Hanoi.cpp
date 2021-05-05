#include <iostream>
// algorytm przekłada n krążków z A korzystając z B na C
void Hanoi(char A, char B, char C, int disk_amount)
{
  if (disk_amount > 0)
  {
    //rozwiązuje problem wieży dla n-1 krążków i zamieniam słupek docelowy z pomocniczym,
    //aby przy zakończeniu wszystkie krązki były na początkowym słupku C - końcowym
    //sposob ułożenia dwóch wywołań ma na celu stworzenie stosu wywołań umożliwiającego poprawne rozwiązanie kolejnych etapów algorytmu
    Hanoi(A, C, B, disk_amount-1);
    std::cout <<"Przeloz najmniejszy krazek ze slupka "<< A << " na slupek " << C << std::endl;
    Hanoi(B, A, C, disk_amount-1);
  }
}

int main(int argc, char *argv[])
{
  //testowe wywołania algorytmu
  std::cout<<"Algortym wiezy Hanoi dla trzech krazkow: "<<std::endl;
  Hanoi('A', 'B', 'C', 3);
  std::cout<<"Algorytm wiezy Hanoi dla czterech krazkow: "<<std::endl;
  Hanoi('A','B','C', 4);
  return 0;
}