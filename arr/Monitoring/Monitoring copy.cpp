#include <iostream>
#include <fstream>

using namespace std;


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

void write(int *temporary, int *result, int n, int index)
{
    for (int j = index + 1; j < n; j++)
    {
        temporary[j] = 0;
        for(int i=0; i<=index; i++)
        {
            cout << temporary[j] << "  ";
            if (temporary[j] == result[i])
            {
                temporary[j]++;
                i=0;
            }
        }
        cout << endl;
    }
}

void search(int *temporary, int *result, int n, int **arr)
{
    for (int i=n-1; i>=0; i--)
    {
        while(result[i]!=n)
        {
            write(temporary, result, n, i);
            cout << result[i] << "  ";
            result[i]++;
        }
    }
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

    int **arr = new int *[n];

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

    cout << endl << endl;
    search(temporary, result, n, arr);



    //wynik
    for (int i=0; i<n; i++)
    {
        cout << result[i] << " ";
    }

    return 0;
}