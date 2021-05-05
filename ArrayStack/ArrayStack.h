#pragma once

class Stack{
    int tab[100];
    int size = 0;
    int maxSize = 100;
    public:
    void push(int element);
    int pop();
    int top();
};