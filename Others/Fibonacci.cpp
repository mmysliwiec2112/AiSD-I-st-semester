#include<iostream>
int fib_r(int amount)
{
    std::cout<<"Wchodze do funkcji rekurencyjnej"<<amount<<std::endl;
    int result;
    if(amount <= 0)
        return 0;
    if(amount == 1)
        return 1;
    else 
        return fib_r(amount-1) + fib_r(amount-2);
}
int fib_iter(int amount)
{
    std::cout<<"Wchodze do funkcji iteracyjnej"<<amount<<std::endl;
    int result = 0;
    int temp = 0;
    int a = 1;
    int b = 1;
    for(int i = 0; i < amount - 2; i++)
    {
        result = a + b;
        temp = a;
        a = result;
        b = temp;
    }
    return result;
}
int main()
{
    int amount;
    std::cout<<"Podaj numer wyrazu ciagu fibonacciego, ktory chcesz policzyc: "<<std::endl;
    std::cin>>amount;
    int result = fib_r(amount);
    std::cout<<amount<<"-ty wyraz ciagu wynosi wyliczony rekurencyjnie = "<<result<<std::endl;
    result = fib_iter(amount);
    std::cout<<amount<<"-ty wyraz ciagu wynosi wyliczony iteracyjnie = "<<result<<std::endl;
    return 0;
}