#pragma once

class Queue{
    int maxSize = 100;
    int tab[100];
    int size = 0;
    public:
    void put(int element);
    int get();
    int front();
};