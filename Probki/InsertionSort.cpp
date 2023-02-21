#include <iostream>

using namespace std;

struct sample
{
    long long int value;
    string descript;
};


bool ifEquals(const string& a, const string& b)
{
    unsigned long long int size = a.size();
    if (b.size() != size)
        return false;
    for (unsigned long long int i = 0; i < size; ++i)
        if (tolower(a[i]) != tolower(b[i]))
            return false;
    return true;
}


void insertionSort(sample samples[], long long int n, long long int j, bool sortByValue)
{
    sample additional;
    unsigned long long int index;
        for (long long int i = j+1; i < n; i++)
        {
            additional = samples[i];
            index = i-1;
            if(sortByValue)
            {
                while (additional.value > samples[index].value && index >= j)
                {
                    samples[index+1] = samples[index];
                    index--;
                }
            }
            else 
            {
                while (additional.descript < samples[index].descript && index >= j)
                {
                    samples[index+1] = samples[index];
                    index--;
                }

            }

            samples[index+1] = additional;
        }
}


int main()
{
    ios_base::sync_with_stdio(false); 



    //deklaracja zmiennych
    long long int t, n, begin;
    bool sortByValue;
    cin >> t;


    //pętla - ilość grup do posortowania
    for (long long int k=0; k<t; k++)
    {
        cin >> n;
        sample* samples = new sample[n];


        //pętla - ilość próbek do posortowania w grupie
        for (long long int i=0; i<n; i++)
        {
            cin >> samples[i].descript;
            cin >> samples[i].value;
        }


        //względem których segmentów sortować
        cin >> sortByValue;


        //jeśli dla liczb
        if(sortByValue)
        {
            insertionSort(samples, n, 0, 1);
            for (long long int i=1; i<n; i++)
            {
                if(samples[i-1].value == samples[i].value) 
                {
                    begin=i-1;

                while(samples[i-1].value == samples[i].value) 
                {
                    i++;
                }
                insertionSort(samples, i, begin, 0);
                }
            }
        }


        //jeśli dla stringów
        else
        {
            insertionSort(samples, n, 0, 0);
            for (long long int i=1; i<n; i++)
            {
                if(ifEquals(samples[i-1].descript, samples[i].descript))
                {
                    begin=i-1;
                
                while(ifEquals(samples[i-1].descript, samples[i].descript))
                {
                    i++;
                }
                insertionSort(samples, i, begin, 1);
                }
            }
        }
        


        //wynik
        for (long long int i=0; i<n; i++)
        {
            cout << samples[i].descript << "-";
            cout << samples[i].value << " ";
        }
        if(k != t-1) cout << "\n";
        delete [] samples;
    }



    return 0;
}