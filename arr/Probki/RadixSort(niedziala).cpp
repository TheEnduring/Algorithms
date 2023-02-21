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

// A utility function to get maximum value in arr[] 
int getMax(sample arr[], int n) 
{ 
    int mx = arr[0].value; 
    for (int i = 1; i < n; i++) 
        if (arr[i].value > mx) 
            mx = arr[i].value; 
    return mx; 
} 

void countSort(sample arr[], int n, int exp, int k) 
{ 
    sample *output = new sample[n]; // output array 
    int i, count[10] = { 0 }; 
  
    // Store count of occurrences in count[] 
    for (i = 0; i < n; i++) 
        count[(arr[i].value / exp) % 10]++; 
  
    // Change count[i] so that count[i] now contains actual 
    //  position of this digit in output[] 
    for (i = 1; i < 10; i++) 
        count[i] += count[i - 1]; 
  
    // Build the output array 
    for (i = n - 1; i >= k; i--) 
    { 
        output[count[(arr[i].value / exp) % 10] - 1] = arr[i]; 
        count[(arr[i].value / exp) % 10]--; 
    } 
  
    // Copy the output array to arr[], so that arr[] now 
    // contains sorted numbers according to current digit 
    for (i = 0; i < n; i++) 
    {
        arr[i] = output[i];
    }

    delete [] output;
} 
  
// The main function to that sorts arr[] of size n using 
// Radix Sort 
void radixSortValue(sample arr[], int n, int k) 
{ 
    // Find the maximum number to know number of digits 
    int m = getMax(arr, n); 
  
    // Do counting sort for every digit. Note that instead 
    // of passing digit number, exp is passed. exp is 10^i 
    // where i is current digit number 
    for (int exp = 1; m / exp > 0; exp *= 10) 
        countSort(arr, n, exp, k); 
} 


void gnomeSortString(sample arr[], int n, int k) 
{ 
    int index = k; 
  
    while (index < n) 
    { 
        if (index == k) 
            index++; 
        if (arr[index].descript >= arr[index - 1].descript) 
            index++;
        else
        { 
            swap(arr[index], arr[index - 1]); 
            index--; 
        } 
    } 
    return; 
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
            radixSortValue(samples, n, 0);
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
                gnomeSortString(samples, i, begin);
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
            gnomeSortString(samples, n, 0);
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
                radixSortValue(samples, i, begin);
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