#include <iostream>
#include <fstream>

using namespace std;


struct values
{
    int value1;
    int value2;
};

int main()
{
    fstream file("test.txt");
    if(file.is_open()) cout << "plik otwarty." << endl;
    int t;
    int n, value1, value2;
    file >> t;
    for (int i=0; i<t; i++)
    {
        file >> n;
        values *arr = new values[n];
        for (int i=0; i<n; i++)
        {
            file >> value1 >> value2;
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