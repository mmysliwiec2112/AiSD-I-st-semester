#include "Stack.h"
#include "Lista.h"
#include <iostream>

void Stack::push(element x){
    stack.Insert(x,stack.tail);
}
element Stack::pop(){
    element temp = stack.Retrieve(stack.tail);
    stack.Delete(stack.tail);
    return temp;
}
element Stack::top(){
    element temp = stack.Retrieve(stack.tail);
    return temp;
}
void Stack::makenull(){
    while (stack.header->next != nullptr)
   {
       stack.Delete(stack.header->next);
   }
   stack.tail = nullptr;
   stack.header = nullptr;
}
bool Stack::empty(){
    return stack.header == nullptr;
}
void Stack::print(){
    stack.print();
}