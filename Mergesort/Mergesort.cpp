#include <iostream>
#include <fstream>

using namespace std;

// Utility function to find minimum of two numbers
int min(int x, int y)
{
    return (x < y) ? x : y;
}
 
// Merge two sorted subarrays A[from .. mid] and A[mid + 1 .. to]
void merge(int arr[], int temp[], int left, int mid, int right)
{
    int k = left, i = left, j = mid + 1;
 
    // loop till there are elements in the left and right runs
    while (i <= mid && j <= right)
    {
        if (arr[i] < arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }
 
    // Copy remaining elements
    while (i < 10 && i <= mid)
        temp[k++] = arr[i++];
 
    // Don't need to copy second half
 
    // copy back to the original array to reflect sorted order
    for (int i = left; i <= right; i++)
        arr[i] = temp[i];
}
 
// Iteratively sort array A[low..high] using temporary array
void mergeSort(int A[], int temp[], int low, int high)
{
    // divide the array into blocks of size m
    // m = [1, 2, 4, 8, 16...]
    for (int m = 1; m <= high - low; m = 2*m)
    {
        // for m = 1, i = 0, 2, 4, 6, 8
        // for m = 2, i = 0, 4, 8
        // for m = 4, i = 0, 8
        // ...
        for (int i = low; i < high; i += 2*m)
        {
            int left = i;
            int mid = i + m - 1;
            int right = min(i + 2*m - 1, high);
 
            merge(A, temp, left, mid, right);
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
    int *arr = new int[n];
    int *temp = new int[n];
    for (int i = 0; i < n; i++)
    {
        file >> arr[i];
        temp[i] = arr[i];
    }

 
    cout << "Given array is " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
 
    long counter = 0;
    mergeSort(arr, temp, 0, n-1);

    cout << endl << counter << endl;

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    delete [] temp;
    delete [] arr;

    return 0;
}
 