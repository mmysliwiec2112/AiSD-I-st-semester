#include "ListaPodwojnieWiazana.h"
#include <iostream>

DoubleLinkedList::DoubleLinkedList()
{
    header = nullptr;
    // header->next = nullptr;
}
DoubleLinkedList::~DoubleLinkedList()
{
    cell *komorka = header;
    while (komorka != 0)
    {
        cell *next = komorka->next;
        std::cout<<"Usuwam komorke o wartosci: "<<komorka->element<<std::endl;
        delete komorka;
        komorka = next;
    }
    header = nullptr;
}
void DoubleLinkedList::Insert(int x, cell *p)
{
    if (header != nullptr)
    {
        cell *komorka = new cell();
        komorka->element = x;
        komorka->next = p->next;
        if (p->next != nullptr)
            p->next->previous = komorka;
        komorka->previous = p;
        p->next = komorka;
    }
    else
    {
        cell *komorka = new cell();
        komorka->element = x;
        header = komorka;
        header->next = nullptr;
    }
}

void DoubleLinkedList::Delete(cell *p)
{
    cell *temp;
    cell *prev;
    temp = header;
    while (temp->next != p->next && temp->next != nullptr)
    {
        prev = temp;
        temp = temp->next;
    }
    prev->next = temp->next;
    temp->next->previous = prev;
    delete p;
}

int DoubleLinkedList::Retrieve(cell *p)
{
    return p->element;
}

cell *DoubleLinkedList::Locate(int x)
{
    cell *temp;
    temp = header;
    while (temp->element != x)
    {
        if (temp->next == nullptr)
            return nullptr;
        temp = temp->next;
    }
    return temp;
}

cell *DoubleLinkedList::First()
{
    return header;
}

cell *DoubleLinkedList::Next(cell *p)
{
    return p->next;
}

cell *DoubleLinkedList::Previous(cell *p)
{
    return p->previous;
}

cell *DoubleLinkedList::Last()
{
    cell *temp;
    temp = header;
    while (temp->next != nullptr)
    {
        temp = temp->next;
    }
    return temp;
}
void DoubleLinkedList::print()
{
    cell *temp;
    temp = header;
    while (temp != nullptr)
    {
        std::cout << temp->element << " ";
        temp = temp->next;
    }
    std::cout << std::endl;
}