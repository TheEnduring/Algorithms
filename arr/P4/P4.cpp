#include <iostream>
#include <string>

using namespace std;

class Lista {
private:
int e_liczba, rozmiar;
string* arr;
public:

Lista();
~Lista();
bool empty();
string front();
string back();
void push_back(string nowy);
void push_front(string nowy);
void pop_front();
void pop_back();
void insert(int pozycja, string nowy);
string at(int p);
string previous(int p);
string next(int p);
};


Lista::Lista()
{
    arr = new string[rozmiar];
}

Lista::~Lista() 
{
    delete [] arr;
}


bool Lista::empty ()
{
    return true;
}





int main()
{
    int n;
    cin >> n;
    string input;
    char first, second;
    for (int i=0; i<n; i++)
    {
        getline(cin, input);
        cout << input;
        if(input[0] != 's') 
        { 
            first = input[0];
            second = input[2];
        }
        else first = input[0];

        cout << first << "  " << second << endl;

    }
    return 0;
}