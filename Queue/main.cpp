#include <iostream>
#include "Queue.h"

int main()
{
    // Lista list1;
    // list1.Insert(3, nullptr);
    // list1.Insert(2, list1.header);
    // cell temp;
    // temp = *list1.Locate(2);
    // std::cout<<"pierwsza komorka trzymajaca 2 wskazuje na komorke: "<<temp.next<<std::endl;
    // list1.Insert(4,list1.header);
    // list1.Insert(5,list1.header);
    // list1.Insert(8,list1.header);
    // list1.Insert(7,list1.header);
    // temp = *list1.Last();
    // std::cout<<"ostatnia komorka listy ma wartosc: "<<temp.element<<" i wskazuje na: "<<temp.next<<std::endl;
    // list1.print();
    // cell temp2;
    // temp2 = *list1.Previous(&temp);
    // std::cout<<"przedostatnia komorka listy ma wartosc: "<<temp2.element<<" i wskazuje na: "<<temp2.next<<std::endl;
    // list1.Delete(list1.Locate(8));
    // list1.print();

    Queue kolejka1;
    kolejka1.put(5);
    kolejka1.print();
    kolejka1.put(4);
    kolejka1.print();
    kolejka1.put(2);
    kolejka1.print();
    std::cout<<kolejka1.get()<<std::endl;
    kolejka1.print();
    kolejka1.makenull();
    if (kolejka1.empty())
    {
        std::cout << "Pusta" << std::endl;
    }
    kolejka1.put(3);
    kolejka1.print();

    return 0;
}