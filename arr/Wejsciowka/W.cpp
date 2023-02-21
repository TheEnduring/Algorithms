#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <time.h>

using namespace std;

void write_data(string directory, int K)
{
    ofstream file(directory, std::ios::out | std::ios::binary);
    int *n = new int[K];
    for (int i=0; i<K; i++)
    {
        n[i] = rand()%10+1;
        file.write((const char *)&n[i],sizeof(float));
        float *x = new float[n[i]];
        for (int j=0; j<n[i]; j++)
        {
            x[j] = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
            file.write((const char *)&x[j],sizeof(float));
        }
    }
}

float process_data(string directory, int K)
{
    ifstream file(directory, std::ios::in | ios_base::binary);
    int *n = new int [K];
    float **x = new float *[K];
    for (int i=0; i<K; i++)
    {
        file.read((char *)&n[i],sizeof(float));
        x[i] = new float[n[i]];
        for (int j=0; j<n[i]; j++)
        {
            file.read((char *)&x[i][j],sizeof(float));
        }
    }

    float *min = new float[K];

    for (int i=0; i<K; i++)
    {
        min[i] = 2;
        for (int j=0; j<n[i]; j++)
        {
            if(min[i] > x[i][j]) min[i] = x[i][j];
        }
    }

    float sum = 0;
    for (int i=0; i<K; i++)
    {
        sum += min[i];
    }
    cout << sum/(float)K;

    return (sum/(float)K);


}



int main()
{
    srand(time(NULL));
    string directory;
    cin >> directory;
    write_data(directory, 5);
    process_data(directory, 5);
    
    return 0;
}