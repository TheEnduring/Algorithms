#include <iostream>
#include <fstream>

using namespace std;

// Merge sort 
void merge(int *arr, int low, int high, int mid, long &counter)
{
    int L, R, LR;
    int *temp = new int[100];
    L = low;
    LR = low;
    R = mid + 1;
    while (L <= mid && R <= high) 
    {
        if (arr[L] < arr[R]) 
        {
            temp[LR] = arr[L];
            LR++;
            L++;
        }
        else  
        {
            temp[LR] = arr[R];
            counter += R-L;
            LR++;
            R++;
        }
    }
    while (L <= mid) 
    {
        temp[LR] = arr[L];
        LR++;
        L++;
    }
    while (R <= high) 
    {
        temp[LR] = arr[R];
        LR++;
        R++;
    }
    for (L = low; L < LR; L++)  
    {
        arr[L] = temp[L];
    }
    delete [] temp;
}





void mergeSort(int *arr, int low, int high, long &counter)
{
    int mid;
    if (low < high)
    {
        mid=(low+high)/2;
        mergeSort(arr,low,mid, counter);
        mergeSort(arr,mid+1,high, counter);
        merge(arr,low,high,mid, counter);
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
    for (int i = 0; i < n; i++)
    {
        file >> arr[i];
    }

 
    cout << "Given array is " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
 
    long counter = 0;
    mergeSort(arr, 0, n-1, counter);

    cout << endl << counter << endl;

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}
 