#ifndef QUEUE_H
#define QUEUE_H
#include "Lista.h"
typedef int element;

class Queue
{
    Lista queue;

public:
    Queue() = default;
    ~Queue() = default;
    void put(element x); // dodaje element do kolejki,
    element get();       //pobiera (i usuwa) pierwszy element z kolejki,
    void front();        // zwraca element znajdujący się na początku kolejki (bez usuwania),
    void makenull();     // usuwa wszystkie elementy z kolejki,
    bool empty();        //sprawdza, czy kolejka jest pusta.
    void print();
};
#endif