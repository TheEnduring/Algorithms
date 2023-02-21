#include <iostream>

using namespace std;

void merge(int *arr, int left, int right, int middle, long &counter)
{
    int lengthL = middle - left+1;
    int lengthR = right - middle;
    int L = 0, R = 0, k = left;
    int *leftArr = new int[lengthL];
    int *rightArr = new int[lengthR];

    for (int i = 0; i < lengthL; i++)
        leftArr[i] = arr[left + i];

    for (int j = 0; j < lengthR; j++)
        rightArr[j] = arr[middle + 1 + j];

 
    while (L < lengthL && R < lengthR) 
    {
        if (leftArr[L] <= rightArr[R]) 
        {
            arr[k] = leftArr[L];
            L++;
        }
        else 
        {
            arr[k] = rightArr[R];
            R++;
            counter += lengthL + L;
        }
        k++;
    }

    while (L < lengthL) 
    {
        arr[k] = leftArr[L];
        L++;
        k++;
    }

    while (R < lengthR) 
    {
        arr[k] = rightArr[R];
        R++;
        k++;
    }
}
 
void mergeSort(int *arr,int left,int right, long &counter)
{
    if(left < right)
    {
        int middle = (left+right-1)/2;
        mergeSort(arr, left, middle, counter);
        mergeSort(arr, middle+1, right, counter);
        merge(arr, left, right, middle, counter);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
 
    long counter = 0;
    mergeSort(arr, 0, n-1, counter);

    cout << counter;


    return 0;
}
 