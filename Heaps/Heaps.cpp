#include <iostream>
using namespace std;

// Max Heap

void maxHeapify(int arr[], int i, int heapSize)
{
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int largest;
    if (left < heapSize && arr[left] > arr[i])
        largest = left;
    else
        largest = i;
    if (right < heapSize && arr[right] > arr[largest])
        largest = right;
    if (largest != i)
    {
        int temp = arr[largest];
        arr[largest] = arr[i];
        arr[i] = temp;
        maxHeapify(arr, largest, heapSize);
    }
}
void buildmaxHeap(int arr[], int n)
{
    int heapSize = n;
    for (int i = (heapSize / 2) - 1; i >= 0; i--)
    {
        maxHeapify(arr, i, heapSize);
    }
}
void heapSort(int arr[], int n)
{
    buildmaxHeap(arr, n);
    int heapSize = n;
    for (int i = 1; i <= n - 1; i++)
    {
        int temp = arr[heapSize - 1];
        arr[heapSize - 1] = arr[0];
        arr[0] = temp;
        heapSize--;
        maxHeapify(arr, 0, heapSize);
    }
}

// Min Heap

void minHeapify(int arr[], int i, int heapSize)
{
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int smallest;
    if (left < heapSize && arr[left] < arr[i])
        smallest = left;
    else
        smallest = i;
    if (right < heapSize && arr[right] < arr[smallest])
        smallest = right;
    if (smallest != i)
    {
        int temp = arr[smallest];
        arr[smallest] = arr[i];
        arr[i] = temp;
        minHeapify(arr, smallest, heapSize);
    }
}
void buildminHeap(int arr[], int n)
{
    int heapSize = n;
    for (int i = (heapSize / 2) - 1; i >= 0; i--)
    {
        minHeapify(arr, i, heapSize);
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
    int arr1[10] = {16, 4, 10, 14, 7, 9, 3, 2, 8, 1};
    display(arr1, 10);
    maxHeapify(arr1, 1, 10);
    display(arr1, 10);
    int arr2[10] = {4, 1, 3, 2, 16, 9, 10, 14, 8, 7};
    display(arr2, 10);
    buildmaxHeap(arr2, 10);
    display(arr2, 10);
    heapSort(arr2, 10);
    display(arr2, 10);
    heapSort(arr1, 10);
    display(arr1, 10);
    int arr0[10] = {16, 4, 10, 14, 7, 9, 3, 2, 8, 1};
    display(arr0, 10);
    minHeapify(arr0, 1, 10);
    display(arr0, 10);
    int arr3[10] = {4, 1, 3, 2, 16, 9, 10, 14, 8, 7};
    display(arr3, 10);
    buildminHeap(arr3, 10);
    display(arr3, 10);
    return 0;
}