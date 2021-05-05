#include "ArrayStack.h"

void Stack::push(int element){
    if(size + 1 < maxSize){
        tab[size] = element;
        size++;
    }
}

int Stack::pop(){
    if(size > 0){
    size--;
    return tab[size];
    }
    else return 0;
}

int Stack::top(){
    if(size > 0)
        return tab[size - 1];
    else return 0;
}