#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    fstream file("test.txt");
    if(file.is_open()) cout << "plik otwarty." << endl;


    return 0;
}