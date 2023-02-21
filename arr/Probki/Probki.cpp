#include <iostream>
#include <fstream>

using namespace std;

struct sample
{
    int value, stability;
    string descript;
};


bool ifEquals(const string& a, const string& b)
{
    unsigned int size = a.size();
    if (b.size() != size)
        return false;
    for (unsigned int i = 0; i < size; ++i)
        if (tolower(a[i]) != tolower(b[i]))
            return false;
    return true;
}

void insertionSortValue(sample samples[], int n, int m)
{
    for(int k=1; k<n; k++)
    {
        sample temp = samples[k];
        int j = k - 1;
        while (j >= m && temp.value > samples[j].value)
        {
            samples[j + 1] = samples[j];
            j = j - 1;
        }
        samples[j + 1] = temp;
    }
}


void insertionSortString(sample samples[], int n, int m)
{
    for(int k=1; k<n; k++)
    {
        sample temp = samples[k];
        int j = k - 1;
        while (j >= m && temp.descript < samples[j].descript)
        {
            samples[j + 1] = samples[j];
            j = j - 1;
        }
        samples[j + 1] = temp;
    }
}


int main()
{
    ios_base::sync_with_stdio(false); 
    fstream file("test.txt");
    if(file.is_open()) cout << "Plik otwarty." << endl;


    //deklaracja zmiennych
    int t, n, begin;
    bool sortByValue;
    file >> t;


    //pętla - ilość grup do posortowania
    for (int k=0; k<t; k++)
    {
        file >> n;
        sample* samples = new sample[n];

        //pętla - ilość próbek do posortowania w grupie
        cout << "Przed sortowaniem: " << endl;
        for (int i=0; i<n; i++)
        {
            file >> samples[i].descript;
            file >> samples[i].value;
            samples[i].stability = i;
            cout << samples[i].descript << "-" << samples[i].value << "-" << samples[i].stability << " ";
        }
        cout << endl;


        //względem których segmentów sortować
        file >> sortByValue;

        //jeśli dla liczb
        if(sortByValue)
        {
            insertionSortValue(samples, n, 0);
            cout << "Pierwsze sortowanie: " << endl;
            for (int i=0; i<n; i++)
            {
                cout << samples[i].descript << "-" << samples[i].value << "-" << samples[i].stability << " ";
            }
            cout << endl;

            for (int i=1; i<n; i++)
            {
                if(samples[i-1].value == samples[i].value) 
                {
                    begin=i-1;

                while(samples[i-1].value == samples[i].value) 
                {
                    i++;
                }
                insertionSortString(samples, i, begin);
                cout << "Drugie sortowanie: " << endl;
                for (int i=0; i<n; i++)
                {
                    cout << samples[i].descript << "-" << samples[i].value << "-" << samples[i].stability << " ";
                }
                cout << endl;
                }
            }
        }


        //jeśli dla stringów
        else
        {
            insertionSortString(samples, n, 0);
            cout << "Pierwsze sortowanie: " << endl;
            for (int i=0; i<n; i++)
            {
                cout << samples[i].descript << "-" << samples[i].value << "-" << samples[i].stability << " ";
            }
            cout << endl;
            for (int i=1; i<n; i++)
            {
                if(ifEquals(samples[i-1].descript, samples[i].descript))
                {
                    begin=i-1;
                
                while(ifEquals(samples[i-1].descript, samples[i].descript))
                {
                    i++;
                }
                insertionSortValue(samples, i, begin);
                cout << "Drugie sortowanie: " << endl;
                for (int i=0; i<n; i++)
                {
                    cout << samples[i].descript << "-" << samples[i].value << "-" << samples[i].stability << " ";
                }
                cout << endl;
                }
            }
        }
        


        //wynik
        cout << "wynik" << endl;
        for (int i=0; i<n; i++)
        {
            cout << samples[i].descript << "-";
            cout << samples[i].value << "-" << samples[i].stability << " ";
        }
        if(k != t-1) cout << "\n";
        delete [] samples;

        cout << endl;
    }

    cout << endl << endl;



    return 0;
}