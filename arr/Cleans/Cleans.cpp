#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

//bucket sort

void bucketSort(float arr[], int n) 
{  
    vector<float> *b = new vector<float>[n]; 
  
    for (int i = 0; i < n; i++) 
    { 
        int bi = n * arr[i];  
        b[bi].push_back(arr[i]); 
    } 

    for (int i = 0; i < n; i++) 
        sort(b[i].begin(), b[i].end()); 

    int index = 0; 
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < b[i].size(); j++) 
            arr[index++] = b[i][j]; 
} 


int main()
{
    fstream file("test.txt");
    if(file.is_open()) cout << "Plik otwarty." << endl;
    int n,m,p;
    file >> n >> m >> p;

    float **arr = new float *[n];

    for (int i = 0; i < n; i++)
    {
        arr[i] = new float [m];
    }

    for (int i=0; i<n; i++)
    {
        for (int j=0; j<m; j++)
        {
            file >> arr[i][j];
            cout << arr[i][j] << "  ";
        }
        cout << endl;
    }

    for (int i=0; i<n; i++)
    {
        delete [] arr[i];
    }
    delete [] arr;
    return 0;
}