#include <iostream>
#include <fstream>

using namespace std;

bool check(int typeAmount, ifstream &file)
{
    int* count = new int[typeAmount];
    int length=0;
    int particle=0;
    bool result = true;
    for (int i=0; i<typeAmount; i++)
    {
        count[i] = 0;
    }
    do
    {
            file >> particle;
            cout << particle << " " << endl;

        if(particle != -1) 
        {
            count[particle]++;
            length++;
            cout << endl << particle << " particle:   " << count[particle];
            cout << endl << "length:   " << length << endl;
        }
    } while (particle != -1);


    cout << endl;

    do
    {
        file >> particle;
        cout << particle << " ";

        if(particle != -1) 
        {
            count[particle]--;
            length--;
            cout << endl << particle << " particle:   " << count[particle];
            cout << endl << "length:   " << length << endl;
        }

        if(particle != -1 && (count[particle] < 0 || length < 0))
        {
            result = false;
        }

    } while (particle != -1);

    cout << endl;
    if (!result || length > 0) 
    {
        cout << endl << "pierwszy warun" << endl;
        cout << endl;
        delete [] count;
        return false;
    }



    for (int i=0; i<typeAmount; i++)
    {
        if(count[i] != 0) 
        {
            cout << endl << "drugi warun" << endl;
            cout << endl;
            delete [] count;
            return false;
        }
    }


    cout << endl << "trzeci warun" << endl;
    delete [] count;
    return true;
}


int main() 
{
    ios_base::sync_with_stdio(false); 
    ifstream file("test.TXT", ios::app);

    if(file.is_open()) cout << "Plik otwarty." << endl;

    int typeAmount, groupAmount;
        file >> groupAmount;
        cout << groupAmount << endl;

    bool* result = new bool[groupAmount];
    //sprawdzanie wartosci logicznej dla wszystkich grup
    for (int i=0; i<groupAmount; i++)
    {
        file >> typeAmount;
        cout << endl << endl << "______" << endl << typeAmount << endl;
        result[i] = check(typeAmount, file);
    }
    cout << endl;

    //wyniki
    for (int i=0; i<groupAmount; i++)
    {
        if (result[i])  cout << "TAK" << "\n";
        else            cout << "NIE" << "\n";
    }
    delete [] result;
    return 0;
}