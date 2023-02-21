#include <iostream>

using namespace std;


struct values
{
    int value1;
    int value2;
};

int main()
{
    int t;
    int n, value1, value2;
    cin >> t;
    for (int i=0; i<t; i++)
    {
        cin >> n;
        values *arr = new values[n];
        for (int i=0; i<n; i++)
        {
            cin >> value1 >> value2;
            arr[i].value1 = value1;
            arr[i].value2 = value2;
        }

        for (int i = 0; i < n; i++)
        {
            
        }
        
        delete [] arr;
    }

    return 0;
}