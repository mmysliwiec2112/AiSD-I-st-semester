#pragma once
#include "Lista.h"
typedef int element;
class Stack
{
private:
    Lista stack;

public:
    Stack() = default;
    ~Stack() = default;
    void push(element x); //- dodaje element x na szczyt stosu,
    element pop();        //- pobiera (i usuwa) element ze szczytu stosu,
    element top();        // - zwraca element znajdujący się na szczycie stosu (bez usuwania),
    void makenull();      // - usuwa wszystkie elementy ze stosu,
    bool empty();      //-sprawdza, czy stos jest pusty.
    void print();
};
