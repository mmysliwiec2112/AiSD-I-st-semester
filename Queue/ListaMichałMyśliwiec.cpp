#include "Lista.h"
#include <iostream>

Lista::Lista()
{
    header = nullptr;
    // header->next = nullptr;
}
Lista::~Lista()
{
    cell *komorka = header;
    while (komorka != 0)
    {
        cell *next = komorka->next;
        delete komorka;
        komorka = next;
    }
    header = 0;
}
void Lista::Insert(int x, cell *p)
{
    if (header != nullptr)
    {
        if (p == tail)
        {
            cell *komorka = new cell();
            komorka->element = x;
            cell *temp = tail;
            temp->next = komorka;
            tail = komorka;
            komorka->next = nullptr;
        }
        else
        {
            if (p == header)
            {
                cell *komorka = new cell();
                komorka->element = x;
                komorka->next = header;
                header = komorka;
            }
            else
            {
                cell* komorka = new cell();
                komorka->element = x;
                komorka->next = p->next;
                p->next = komorka->next;
            }
            
        }
    }
    else
    {

        cell *komorka = new cell();
        cell *komorka2 = new cell();
        komorka->element = x;
        header = komorka;
        header->next = tail;
        tail = header;
    }
}

void Lista::Delete(cell *p)
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
    if (temp == header)
    {
        header = temp->next;
    }
    delete p;
}

int Lista::Retrieve(cell *p)
{
    return p->element;
}

cell *Lista::Locate(int x)
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

cell *Lista::First()
{
    return header;
}

cell *Lista::Next(cell *p)
{
    return p->next;
}

cell *Lista::Previous(cell *p)
{
    cell *temp;
    cell *prev;
    temp = header;
    while (temp->next != p->next && temp->next != nullptr)
    {
        prev = temp;
        temp = temp->next;
    }
    return prev;
}

cell *Lista::Last()
{
    return tail;
}
void Lista::print()
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