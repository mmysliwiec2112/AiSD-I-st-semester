#include"ArrayQueue.h"

void Queue::put(int element){
    if(size + 1 < maxSize)
    tab[size] = element;
}
int Queue::get(){
    if(size > 0){
        int temp = tab[0];
        for(int i = 1; i < size; i ++)
        {
            tab[i-1] = tab[i];
        }
        return temp;
    }
    else return 0;
}
int Queue::front(){
    return tab[0];
}