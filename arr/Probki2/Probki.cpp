#include <iostream>
#include <fstream>

using namespace std;

struct sample
{
    int value;
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

void selectionSortValue(sample samples[], int n, int k)  
{  
    int max;  
    for (int i = k; i < n-1; i++)  
    {    
        max = i;
        for (int j = i+1; j < n; j++)  
            if (samples[j].value > samples[max].value)  
                max = j;  

        sample additional;
        additional = samples[max];
        samples[max] = samples[i];
        samples[i] = additional;
    }  
}  


void selectionSortString(sample samples[], int n, int k)  
{  
    int max;  
    for (int i = k; i < n-1; i++)  
    {    
        max = i;
        for (int j = i+1; j < n; j++)  
            if (samples[j].descript < samples[max].descript)  
                max = j;  

        sample additional;
        additional = samples[max];
        samples[max] = samples[i];
        samples[i] = additional;
    }  
}  



void insertionSortValue(sample samples[], int n, int j)
{
    sample additional;
    int index;
        for (int i = j+1; i < n; i++)
        {
            additional = samples[i];
            index = i-1;

            while (additional.value > samples[index].value && index >= j)
            {
                samples[index+1] = samples[index];
                index--;
            }

            samples[index+1] = additional;
        }
}


void insertionSortString(sample samples[], int n, int j)
{

    sample additional;
    int index;
        for (int i = j+1; i < n; i++)
        {
            additional = samples[i];
            index = i-1;

            while (additional.descript < samples[index].descript && index >= j)
            {
                samples[index+1] = samples[index];
                index--;
            }

            samples[index+1] = additional;
        }
}


int main()
{
    ios_base::sync_with_stdio(false); 

    //plik tekstowy
    ifstream file("test.TXT");
    if(file.is_open()) cout << "Plik otwarty." << endl << endl << endl;



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
        for (int i=0; i<n; i++)
        {
            file >> samples[i].descript;
            file >> samples[i].value;
            cout << samples[i].descript << " " << samples[i].value << endl;
        }


        //względem których segmentów sortować
        file >> sortByValue;
        cout << sortByValue << endl << endl;


        //jeśli dla liczb
        if(sortByValue)
        {
            selectionSortValue(samples, n, 0);
            cout << "Pierwsze sortowanie: " << endl;
            for (int i=0; i<n; i++)
            {
                cout << samples[i].descript << "-";
                cout << samples[i].value << " ";
            }
            for (int i=1; i<n; i++)
            {
                if(samples[i-1].value == samples[i].value) 
                {
                    cout << "warunek" << endl;
                    begin=i-1;
                    cout << "begin: " << begin << endl;

                while(samples[i-1].value == samples[i].value) 
                {
                    i++;
                    cout << "adres: " << i << endl;
                }
                selectionSortString(samples, i, begin);
                }
            }
        }


        //jeśli dla stringów
        else
        {
            selectionSortString(samples, n, 0);
            cout << endl << "Pierwsze sortowanie: " << endl;
            for (int i=0; i<n; i++)
            {
                cout << samples[i].descript << "-";
                cout << samples[i].value << " ";
            }
            for (int i=1; i<n; i++)
            {
                if(ifEquals(samples[i-1].descript, samples[i].descript))
                {
                    cout << "warunek" << endl;
                    begin=i-1;
                    cout << "begin: " << begin << endl;
                
                while(ifEquals(samples[i-1].descript, samples[i].descript))
                {
                    i++;
                    cout << "adres: " << i << endl;
                }
                selectionSortValue(samples, i, begin);
                }
            }
        }
        


        //wynik
        cout << "wynik: " << endl;
        for (int i=0; i<n; i++)
        {
            cout << samples[i].descript << "-";
            cout << samples[i].value << " ";
        }
        if(k != t-1) cout << "\n";
        cout << endl << endl << endl;
        delete [] samples;
    }



    return 0;
}