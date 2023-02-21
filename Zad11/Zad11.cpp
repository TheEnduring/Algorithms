#include <iostream>
#include <fstream>

using namespace std;

struct patient
{
    int id;
    string name, surname;
};


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    fstream file("test.txt");
    if (file.is_open()) cout << "File opened." << endl;

    int n,m;
    file >> n;
    file >> m;

    patient *patients = new patient[n];
    
    for (int i=0; i<n; i++)
    {
        file >> patients[i].id;
        file >> patients[i].name;
        file >> patients[i].surname;
    }

    for (int i=0; i<n; i++)
    {
        cout << patients[i].id << " ";
        cout << patients[i].name << " ";
        cout << patients[i].surname << endl;
    }

    for (int i=0; i<m; i++)
    {
        
    }


    return 0;
}