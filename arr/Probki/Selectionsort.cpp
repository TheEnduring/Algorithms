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
        while (max < i)
        {
            samples[max] = samples[max+1];
            max++;
        }
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
        while (max < i)
        {
            samples[max] = samples[max+1];
            max++;
        }
        samples[i] = additional;
    }  
}  


int main()
{
    ios_base::sync_with_stdio(false); 



    //deklaracja zmiennych
    int t, n, begin;
    bool sortByValue;
    fstream file("test.txt");
    if(file.is_open()) cout << "Plik otwarty." << endl;
    file >> t;


    //pętla - ilość grup do posortowania
    for (int k=0; k<t; k++)
    {
        cout << endl << endl;
        file >> n;
        sample* samples = new sample[n];

        //pętla - ilość próbek do posortowania w grupie
        cout << "Przed sortowaniem: " << endl;
        for (int i=0; i<n; i++)
        {
            file >> samples[i].descript;
            file >> samples[i].value;
            
            cout << samples[i].descript << "-" << samples[i].value << " ";
        }
        cout << endl;

        //względem których segmentów sortować
        file >> sortByValue;

        //jeśli dla liczb
        if(sortByValue)
        {
            selectionSortValue(samples, n, 0);
            cout << "Pierwsze sortowanie: " << endl;
            for (int i=0; i<n; i++)
            {
                cout << samples[i].descript << "-" << samples[i].value << " ";
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
                cout << "Drugie sortowanie: " << endl;
            for (int i=0; i<n; i++)
            {
                cout << samples[i].descript << "-" << samples[i].value << " ";
            }
            cout << endl;
                selectionSortString(samples, i, begin);
                }
            }
        }


        //jeśli dla stringów
        else
        {
            cout << "Pierwsze sortowanie: " << endl;
            for (int i=0; i<n; i++)
            {
                cout << samples[i].descript << "-" << samples[i].value << " ";
            }
            cout << endl;
            selectionSortString(samples, n, 0);
            for (int i=1; i<n; i++)
            {
                if(ifEquals(samples[i-1].descript, samples[i].descript))
                {
                    begin=i-1;
                
                while(ifEquals(samples[i-1].descript, samples[i].descript))
                {
                    i++;
                }
                cout << "Drugie sortowanie: " << endl;
                for (int i=0; i<n; i++)
                {
                    cout << samples[i].descript << "-" << samples[i].value << " ";
                }
                cout << endl;
                selectionSortValue(samples, i, begin);
                }
            }
        }
        
        cout << endl;
        cout << endl;

        //wynik
        for (int i=0; i<n; i++)
        {
            cout << samples[i].descript << "-";
            cout << samples[i].value << " ";
        }
        if(k != t-1) cout << "\n";
        delete [] samples;
    }



    return 0;
}