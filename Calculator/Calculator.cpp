#include <iostream>
#include <string>
#include <stack>
#include <sstream>
#include <cmath>
using namespace std;

//funkcja sprawdza, czy dany string jest liczbą
bool isNumeric(string str)
{
    for (int i = 0; i < str.length(); i++)
        if (isdigit(str[i]) == false)
            return false; //kiedy zostanie znaleziony char nie bedacy numerem - zwracany jest false
    return true;
}

// funkcja sprawdza czy podany argument jest jednym z operatorow dzialan
bool isOperator(char c)
{
    if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^')
        return true;
    else
        return false;
}

// funkcja sprawdzajaca waznosc operatora
// potegowanie - 3
// mnozenie i dzielenie - 2
// dodawanie i odejmowanie - 1
// pozostaly, ubezpieczajacy warunek ma -1
int importanceOfOperator(char c)
{
    if (c == '^')
        return 3;
    if (c == '*' || c == '/')
        return 2;
    if (c == '+' || c == '-' )
        return 1;
    else
        return -1;
}

//funkcja odwraca zapis standardowy na Odwrotna Notacje Polska
//zwraca string zapusany w ONP, ktory na poczatku bedzie miec wszystkie wartosci, a po nich zapisane znaki obliczen
//zwrocony przez te funkcje string jest wykorzystywany do obliczenia wartosci wyrazenia
string infixToRPN(string input)
{
    stack<char> stack;
    string exprInRPN;
    for (int i = 0; i < input.length(); i++)
    { 
        // po pojawieniu sie prawego nawiasu, ze stosu sciagane sa wszystkie znaki znajdujace sie przed lewym nawiasem  
        if (input[i] == ')')
        {
            while (stack.top() != '(' && !stack.empty())
            {
                char temp = stack.top();
                exprInRPN += temp;
                exprInRPN += ' ';
                stack.pop();
            }
            //usuwanie lewej klary nawiasu ze stosu
            if (!stack.empty())
                stack.pop();
        }
        // lewy nawias jest po prostu dodawany do stosu
        else if (input[i] == '(')
        {
            stack.push(input[i]);
        }
        //zwykłe przepisanie liczby
        else if (i != input.length() - 1 && !isOperator(input[i]) && input[i] != ' ' && isdigit(input[i + 1]))
        {
            exprInRPN += input[i];
        }
        // blok ustawiajacy operator w odpowiedniej kolejnosci w stosunku do pozostalych
        else if (isOperator(input[i]))
        {
            //jesli stos jest pusty - po prostu dodajemy element do stosu
            if (stack.empty())
                stack.push(input[i]);
            else
            {

                //jezeli waznosc aktualnie sprawdzanego operatora jest wieksza od waznosci operatora na szczycie stosu, dodajemy do stosu aktualnie sprawdzany element
                if (importanceOfOperator(input[i]) > importanceOfOperator(stack.top()))
                {
                    stack.push(input[i]);
                }

                //jezeli na szczycie stosu jest operator o waznosci potegi (najwieszkej), wtedy operator nadal idzie na stos
                else if (importanceOfOperator(input[i]) == importanceOfOperator(stack.top()) && input[i] == '^')
                {
                    stack.push(input[i]);
                }
                else
                {

                    //jesli na szczycie stosu jest operator o wiekszej waznosci, operator zostaje po prostu przeniesiony do wyrazenia w ONP
                    while ((!stack.empty()) && importanceOfOperator(input[i]) <= importanceOfOperator(stack.top()))
                    {
                        char temp = stack.top();
                        exprInRPN += temp;
                        exprInRPN += ' ';
                        stack.pop();
                    }
                    stack.push(input[i]);
                }
            }
        }
        //dodanie do wyrazenia w ONP liczb, ktore nie sa zadnym z poprzednich warunkow, warunek if ma chronic przed dodaniem w srodku wyrazenia losowego znaku spoza obslugiwanych przez kalkulator
        else if (isdigit(input[i]))
        {
            exprInRPN += input[i];
            exprInRPN += ' ';
        }
    }

    //oproznianie stosu ze wszystkich znakow, ktore na nim zostaly, zaczynajac od tego o najwyzszej waznosci
    while (!stack.empty())
    {
        exprInRPN += stack.top();
        exprInRPN += ' ';
        stack.pop();
    }
    cout<<"Koniec konwersji do ONP"<<endl;
    return exprInRPN;
}

//dodawanie
int add(int a, int b)
{
    return a + b;
}

//odejmowanie
int sub(int a, int b)
{
    return a - b;
}

//dzielenie
int divd(int a, int b)
{
    if (b != 0)
    {
        return a / b;
    }
}

//mnożenie
int mult(int a, int b)
{
    return a * b;
}

//potęgi
int power(int a, int b)
{
    int temp = pow(a, b);
    return temp;
}

//funkcja wywoływana do obliczenia w ONP
int calculate(string &exprInRPN)
{
    int a, b = 0;
    char temp;
    stringstream s(exprInRPN);
    string element;
    stack<int> stack;

    //aby uzyc funkcji getline potrzebny jest stringstream - dzieki tej funkcji kalkulator moze obslugiwac wielocyfrowe liczby, poniewaz wszystkie elementy sa rozdzielone spacjami
    while (getline(s, element, ' '))
    {
        if (element[0] != ' ')
        {
            //sprawdzam czy aktualnie sprawdzany element rozdzielony spacjami to operator, aby moc uzyc funkcji dla chara musze brac element 0 elementu, chociaz on sam nie ma wiecej.
            if (isOperator(element[0]))
            {
                char convToken = element[0];
                if (convToken == '+')
                {
                    a = stack.top();
                    stack.pop();
                    b = stack.top();
                    stack.pop();
                    stack.push(add(b, a));
                    cout << b << " + " << a << endl;
                }
                else if (convToken == '-')
                {
                    a = stack.top();
                    stack.pop();
                    b = stack.top();
                    stack.pop();
                    cout << b << " - " << a << endl;
                    stack.push(sub(b, a));
                }
                else if (convToken == '*')
                {
                    a = stack.top();
                    stack.pop();
                    b = stack.top();
                    stack.pop();
                    cout << b << " * " << a << endl;
                    stack.push(mult(b, a));
                }
                else if (convToken == '/')
                {
                    if (a != 0)
                    {
                        a = stack.top();
                        stack.pop();
                        b = stack.top();
                        stack.pop();
                        cout << b << " / " << a << endl;
                        stack.push(divd(b, a));
                    }
                }
                else if (convToken == '^')
                {
                    a = stack.top();
                    stack.pop();
                    b = stack.top();
                    stack.pop();
                    cout << b << " ^ " << a << endl;
                    stack.push(power(b, a));
                }
            }
            // sprawdza czy dany element jest liczba, tu potrzeba juz funkcji sprawdzajacej string, poniewaz moga pojawic sie liczby wielocyfrowe
            else if (isNumeric(element))
            {
                stack.push(stoi(element));
            }
        }
    }
    return stack.top();
}

int main()
{
    bool quitFlag = true;
    char answer;
    int result;
    string input, exprInRPN;
    cout << "Podaj wyrazenie w standardowej notacji" << endl;
    getline(cin, input);
    cout << "Obliczam wyrazenie w ONP" << endl;
    exprInRPN = infixToRPN(input);
    cout << "Wynik obliczen: " << exprInRPN << endl;
    cout << "Trwa obliczanie wyniku zadanego dzialania..." << endl;
    result = calculate(exprInRPN);
    cout << "Wynik obliczen: " << result << endl;
    return 0;
}