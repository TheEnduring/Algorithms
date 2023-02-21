#include <iostream>

using namespace std;

bool check(int typeAmount)
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
        cin >> particle;

        if(particle != -1) 
        {
            count[particle]++;
            length++;
        }
    } while (particle != -1);

    do
    {
        cin >> particle;

        if(particle != -1) 
        {
            count[particle]--;
            length--;
        }

        if(particle != -1 && (count[particle] < 0 || length < 0))
        {
            result = false;
        }

    } while (particle != -1);

    if (!result || length > 0) 
    {
        delete [] count;
        return false;
    }



    for (int i=0; i<typeAmount; i++)
    {
        if(count[i] != 0) 
        {
            delete [] count;
            return false;
        }
    }


    delete [] count;
    return true;
}


int main() 
{
    ios_base::sync_with_stdio(false); 

    int typeAmount, groupAmount;
        cin >> groupAmount;

    bool* result = new bool[groupAmount];
    //sprawdzanie wartosci logicznej dla wszystkich grup
    for (int i=0; i<groupAmount; i++)
    {
        cin >> typeAmount;
        result[i] = check(typeAmount);
    }

    //wyniki
    for (int i=0; i<groupAmount; i++)
    {
        if (result[i])  cout << "TAK" << "\n";
        else            cout << "NIE" << "\n";
    }
    delete [] result;
    return 0;
}