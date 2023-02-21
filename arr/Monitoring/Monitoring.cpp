#include <iostream>
#include <fstream>

using namespace std;

int **arr;

void printArr(int **arr, int n)
{
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<n; j++)
            cout << arr[i][j] << "  ";
        cout << endl;
    }
    cout << endl << endl;
}

int suma(int *result, int n, int **arr)
{
    int sum=0;
    for (int i=0; i<n; i++)
    {
        sum+=arr[i][result[i]];
    }
    return sum;
}

int search(int *result, int n, int index, int min, int current)
{
    if (min > suma(result, n, arr)) min = suma(result, n, arr);

    if(current<n)
    {
        result[index]=current;
        for (int i = index+1; i < n; i++)
        {
            result[i]=0;
            for(int j=i+1; j<n; j++)
            {
                if (current == result[i] || result[j]==result[i])
                {
                    result[i]++;
                    j = i+1;
                }
            }
            
        }


        for(int i=0; i<n; i++)
        {
            cout << result[i] << " ";
        }
        cout << endl;

        if(index>=0) search(result, n, index, min, current+1);
    }
    else
    {
        current=0;
        search(result, n, index-1, min, current);
    } 
    return min;
}





int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    fstream file("test.txt");
    if(file.is_open()) cout << "plik otwarty." << endl;

    int n;
    file >> n;
    arr = new int *[n];

    for (int i=0; i<n; i++)
    {
        arr[i] = new int [n];
        for (int j=0; j<n; j++)
            file >> arr[i][j];
    }

    printArr(arr, n);

    int *result = new int [n];
    int *temporary = new int [n];
    int min, sum=0;

    for (int i = 0; i < n; i++)
    {
        result[i]=0;
        for(int j=0; j<i; j++)
        {
            if(result[i]==result[j])
            {
                result[i]++;
                j=0;
            }

        }
        cout << result[i] << "  ";
    }
    min = suma(result, n, arr);

    search(result, n, n-1, min, result[n-1]-1);

    //wynik
    for (int i=0; i<n; i++)
    {
        cout << result[i] << " ";
    }

    return 0;
}