#include <iostream>
using namespace std;
void insertionSort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}
void insertion_Sort(int arr[], int n, int j)
{
    if (j < n - 1)
    {
        int key = arr[j + 1];
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
        j++;
        insertion_Sort(arr, n, j);
    }
}
void bubbleSort(int arr[], int n)
{
    int swapped = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = 1;
            }
        }
        if (swapped == 0)
        {
            break;
        }
    }
}
void merge(int arr[], int p, int q, int r)
{
    int nl = q - p + 1;
    int nr = r - q;
    int left[nl];
    int right[nr];
    for (int i = 0; i < nl; i++)
        left[i] = arr[p + i];
    for (int j = 0; j < nr; j++)
        right[j] = arr[q + 1 + j];
    int i = 0, j = 0, k = p;
    while (i < nl && j < nr)
    {
        if (left[i] <= right[j])
        {
            arr[k] = left[i];
            i++;
        }
        else
        {
            arr[k] = right[j];
            j++;
        }
        k++;
    }
    while (i < nl)
    {
        arr[k] = left[i];
        i++;
        k++;
    }
    while (j < nr)
    {
        arr[k] = right[j];
        j++;
        k++;
    }
}
void mergeSort(int arr[], int p, int r)
{
    if (r > p)
    {
        int q = (r + p) / 2;
        mergeSort(arr, p, q);
        mergeSort(arr, q + 1, r);
        merge(arr, p, q, r);
    }
}
void display(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int main()
{
    int arr[6] = {6, 5, 4, 3, 2, 1};
    display(arr, 6);
    // mergeSort(arr,0,5);
    // insertionSort(arr,6);
    bubbleSort(arr, 6);
    display(arr, 6);
    return 0;
}