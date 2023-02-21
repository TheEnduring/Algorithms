#include <iostream>
#include <fstream>


using namespace std;


struct person
{
    int id, priorytet;
};


/* child: 
    2x parent + 1
    2x parent + 2
    parent = floor((child-1)/2)
*/

void heapify(person arr[], int n, int i)
{
    int largest = i; // Initialize largest as root
    int l = 2 * i + 1; // left = 2*i + 1
    int r = 2 * i + 2; // right = 2*i + 2
 
    // If left child is larger than root
    if (l < n && arr[l].priorytet > arr[largest].priorytet)
        largest = l;
 
    // If right child is larger than largest so far
    if (r < n && arr[r].priorytet > arr[largest].priorytet)
        largest = r;
 
    // If largest is not root
    if (largest != i) 
    {
        swap(arr[i], arr[largest]);
 
        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
}
 
// main function to do heap sort
void heapSort(person arr[], int n)
{
    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
 
    // One by one extract an element from heap
    for (int i = n - 1; i > 0; i--) {
        // Move current root to end
        swap(arr[0], arr[i]);
 
        // call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
}

void printArray(person arr[], int n)
{
    for (int i = 0; i < n; ++i)
    {
        cout << arr[i].id << " " << arr[i].priorytet;
        cout << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    fstream file("test.txt");
    if (file.is_open()) cout << "File opened." << endl;

    int d,s;
    file >> s >> d;
    person **persons = new person *[d];
    int *amount = new int[d];
    for (int i=0; i<d; i++)
    {
        file >> amount[i];
    
        cout << amount[i] << endl;
        persons[i] = new person[amount[i]];

        for (int j=0; j<amount[i]; j++)
        {
            file >> persons[i][j].id;
            file >> persons[i][j].priorytet;
            
            cout << persons[i][j].id << " ";
            cout << persons[i][j].priorytet << endl;
        }
    }


    heapSort(persons[0], amount[0]);

    cout << endl;

    printArray(persons[0], amount[0]);
    
    return 0;
}