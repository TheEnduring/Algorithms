#include <iostream>

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

void mergeValue(sample arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
 
    sample *L = new sample[n1];
    sample *R = new sample[n2];
 
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
 
    i = 0; 
    j = 0; 
    k = l; 
    while (i < n1 && j < n2) 
    {
        if (L[i].value <= R[j].value) 
        {
            arr[k] = L[i];
            i++;
        }
        else 
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
 
    while (i < n1) 
    {
        arr[k] = L[i];
        i++;
        k++;
    }
 
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}
 
void mergeSortValue(sample arr[], int l, int r)
{
    if (l < r) 
    {
        int m = l + (r - l) / 2;
        mergeSortValue(arr, l, m);
        mergeSortValue(arr, m + 1, r);
        mergeValue(arr, l, m, r);
    }
}


void mergeString(sample arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
 
    sample *L = new sample[n1];
    sample *R = new sample[n2];
 
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
 
    i = 0; 
    j = 0; 
    k = l; 
    while (i < n1 && j < n2) 
    {
        if (L[i].descript <= R[j].descript) 
        {
            arr[k] = L[i];
            i++;
        }
        else 
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
 
    while (i < n1) 
    {
        arr[k] = L[i];
        i++;
        k++;
    }
 
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}
 
void mergeSortString(sample arr[], int l, int r)
{
    if (l < r) 
    {
        int m = l + (r - l) / 2;
        mergeSortString(arr, l, m);
        mergeSortString(arr, m + 1, r);
        mergeString(arr, l, m, r);
    }
}
 
 


int main()
{
    ios_base::sync_with_stdio(false); 



    //deklaracja zmiennych
    int t, n, begin;
    bool sortByValue;
    cin >> t;


    //pętla - ilość grup do posortowania
    for (int k=0; k<t; k++)
    {
        cin >> n;
        sample* samples = new sample[n];

        //pętla - ilość próbek do posortowania w grupie
        for (int i=0; i<n; i++)
        {
            cin >> samples[i].descript;
            cin >> samples[i].value;
        }


        //względem których segmentów sortować
        cin >> sortByValue;

        //jeśli dla liczb
        if(sortByValue)
        {
            mergeSortValue(samples, n, 0);

            for (int i=1; i<n; i++)
            {
                if(samples[i-1].value == samples[i].value) 
                {
                    begin=i-1;

                while(samples[i-1].value == samples[i].value) 
                {
                    i++;
                }
                mergeSortString(samples, i, begin);
                }
            }
        }


        //jeśli dla stringów
        else
        {
            mergeSortString(samples, n, 0);
            for (int i=1; i<n; i++)
            {
                if(ifEquals(samples[i-1].descript, samples[i].descript))
                {
                    begin=i-1;
                
                while(ifEquals(samples[i-1].descript, samples[i].descript))
                {
                    i++;
                }
                mergeSortValue(samples, i, begin);
                }
            }
        }
        


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