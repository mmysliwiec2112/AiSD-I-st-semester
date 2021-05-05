#include <iostream>

void bubbleSort(int tab[], int size)
{
    if (tab != nullptr)
    {
        int temp = 0;
        for (int i = 0; i < size - 1; i++)
        {
            for (int j = 0; j < size - 1; j++)
            {
                if (tab[j] > tab[j + 1])
                {
                    temp = tab[j];
                    tab[j] = tab[j + 1];
                    tab[j + 1] = temp;
                }
            }
        }
    }
}
int main()
{
    int tab[] = {3, 2, 6, 4, 8, 2, 7, 9};
    for (int i = 0; i < 8; i++)
    {
        std::cout << tab[i] << " ";
    }
    std::cout << std::endl;
    bubbleSort(tab, 8);
    for (int i = 0; i < 8; i++)
    {
        std::cout << tab[i] << " ";
    }
    return 0;
}