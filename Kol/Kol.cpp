#include <iostream>

using namespace std;

void Fun(float arr[3][3], int n, int arrint[3])
{
    float sum=0;
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<3; j++)
        {
            sum+=arr[i][j];
        }
        if(sum>(float)arrint[i]) cout << sum << endl;
        sum=0;
    }
}


int main()
{
    int n=3;
    float arr2d[3][3];
    int arrint[3];
    Fun(arr2d, n, arrint);
    return 0;
}