#include <iostream>

void selectionSort(int tab[], int size)
{
    if (tab != nullptr)
    {
        int minValId = 0;
        int temp;
        for (int i = 0; i < size; i++)
        {
            minValId = i;
            for (int j = i; j < size; j++)
            {
                if (tab[minValId] > tab[j])
                {
                    minValId = j;
                }
            }
            temp = tab[minValId];
            tab[minValId] = tab[i];
            tab[i] = temp;
        }
    }
}

int main()
{
    int tab[] = {2, 3, 6, 4, 8, 2, 7, 9};
    for (int i = 0; i < 8; i++)
    {
        std::cout << tab[i] << " ";
    }
    std::cout << std::endl;
    selectionSort(tab, 8);
    for (int i = 0; i < 8; i++)
    {
        std::cout << tab[i] << " ";
    }
    return 0;
}