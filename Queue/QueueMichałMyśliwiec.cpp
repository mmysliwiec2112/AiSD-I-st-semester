#include <iostream>
#include "Queue.h"
void Queue::put(element x)
{
    queue.Insert(x, queue.header);
}
element Queue::get()
{
    int temp = queue.Retrieve(queue.tail);
    // queue.header = queue.header->next;
    queue.Delete(queue.tail);
    return temp;
}
void Queue::makenull()
{
   while (queue.header->next != nullptr)
   {
       queue.Delete(queue.header->next);
   }
   queue.tail = nullptr;
   queue.header = nullptr;
   
}
bool Queue::empty()
{
    return queue.header == nullptr;
}

void Queue::print(){
    queue.print();
}
