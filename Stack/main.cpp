
#include"Stack.h"
#include<iostream>

int main(){
    Stack kolejka1;
    kolejka1.push(5);
    kolejka1.print();
    kolejka1.push(4);
    kolejka1.print();
    kolejka1.push(2);
    kolejka1.print();
    std::cout<<kolejka1.pop()<<std::endl;
    kolejka1.print();
    kolejka1.makenull();
    if (kolejka1.empty())
    {
        std::cout << "Pusta" << std::endl;
    }
    kolejka1.push(3);
    kolejka1.print();

    return 0;
}