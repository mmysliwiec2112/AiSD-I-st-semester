#ifndef LISTAPODWOJNIEWIAZANA_H
#define LISTAPODWOJNIEWIAZANA_H
struct cell
    {
        int element;
        cell *next;
        cell *previous;
    };
class DoubleLinkedList
{
    

public:
    cell *header; // głowa listy
public:
    DoubleLinkedList
();                         //konstruktor
    ~DoubleLinkedList
();                        //destruktor
    void Insert(int x, cell *p); // wstawia komórkę z elementem x na pozycję next komórki o wskaźniku p
                                     // (lub w przypadku pustej listy tworzy komórkę z elementem x w miejscu głowy listy)
    void Delete(cell *p);            // usuwa komórkę o wskaźniku p
    int Retrieve(cell *p);       // zwraca element komórki o wskaźniku p
    cell *Locate(int x);         // zwraca wskaźnik do pierwszej komórki z elementem x
    cell *First();                   // zwraca wskaźnik do pierwszej komórki na liście
    cell *Next(cell *p);             // zwraca wskaźnik do kolejnej komórki po komórce o wskaźniku p
    cell *Previous(cell *p);         // zwraca wskaźnik do komórki poprzedzającej komórkę o wskaźniku p
    cell *Last();                    // zwraca wskaźnik do ostatniej komórki na liście

    void print(); // wyświetla wszystkie elementy listy
};
#endif