#include <iostream>

using namespace std;

int cinValue(int min, int max)
{
    int value;
    do
    {
        cin >> value;
    } while (value < min || value > max);
    return value;
}

bool check(int typeAmount)
{
    int *count = new int[typeAmount];
    int length=0;
    int particle=0;
    for (int i=0; i<typeAmount; i++)
    {
        count[i] = 0;
    }
    do
    {
            particle = cinValue(-1, typeAmount-1);

        if(particle != -1) 
        {
            count[particle]++;
            length++;
        }
    } while (particle != -1);

    do
    {
        particle = cinValue(-1, typeAmount-1);


        if(particle != -1) 
        {
            count[particle]--;
            length--;
        }
        if(particle != -1 && (count[particle] < 0 || length < 0))
        {
            delete [] count;
            return 0;
        }
    } while (particle != -1);


    for (int i=0; i<typeAmount; i++)
    {
        if(count[i] != 0) 
        {
            delete [] count;
            return 0;
        }
    }
    delete [] count;
    return 1;
}



int main() 
{
    ios_base::sync_with_stdio(false); 

    int typeAmount, groupAmount;
        groupAmount = cinValue(1, 10);


    bool *result = new bool[groupAmount];

    //sprawdzanie wartosci logicznej dla wszystkich grup
    for (int i=0; i<groupAmount; i++)
    {
            typeAmount = cinValue(1, 1000000);


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