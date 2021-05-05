#include <iostream>

void insertSort(int tab[], int size)
{
    if (tab != nullptr)
    {
        int  temp;
        for (int i = 0; i < size; i++)
        {
            for (int j = i - 1; j > 0; j--)
            {
                if(tab[j] > tab[j + 1]){
                    temp = tab[j];
                    tab[j] = tab[j + 1];
                    tab[j + 1] = temp;

                }
            }
        }
    }
}

int main(){
    int tab[] = {2, 3, 6, 4, 8, 2, 7, 9};
    for(int i = 0; i < 8; i ++)
    {
        std::cout<<tab[i]<<" ";
    }
    insertSort(tab, 8);
    for(int i = 0; i < 8; i ++)
    {
        std::cout<<tab[i]<<" ";
    }
    return 0;
}