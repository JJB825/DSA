#include <iostream>
using namespace std;
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

// Maximum priority queue

int maximum(int arr[])
{
    return arr[0];
}
int extractmax(int arr[], int &n)
{
    if (n <= 0)
    {
        cout << "Heap Underflow\n";
        return -1;
    }
    int max = maximum(arr);
    int heapSize = n;
    arr[0] = arr[heapSize - 1];
    heapSize--;
    maxHeapify(arr, 0, heapSize);
    n = heapSize;
    return max;
}
void display(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int parent(int i)
{
    if (i % 2 == 0)
        return (i - 2) / 2;
    else
        return (i - 1) / 2;
}
void increaseKey(int arr[], int i, int key)
{
    if (arr[i] > key)
    {
        cout << "Key smaller than initial one\n";
        return;
    }
    arr[i] = key;
    while (i > 0 && arr[i] > arr[parent(i)])
    {
        int temp = arr[i];
        arr[i] = arr[parent(i)];
        arr[parent(i)] = temp;
        i = parent(i);
    }
}
void insert(int arr[], int &n, int key)
{
    n++;
    arr[n - 1] = key;
    increaseKey(arr, n - 1, key);
}

// Minimum Priority Queue

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
int minimum(int arr[])
{
    return arr[0];
}
int extractmin(int arr[], int &n)
{
    if (n <= 0)
    {
        cout << "Heap Underflow\n";
        return -1;
    }
    int min = minimum(arr);
    int heapSize = n;
    arr[0] = arr[heapSize - 1];
    heapSize--;
    minHeapify(arr, 0, heapSize);
    n = heapSize;
    return min;
}   
void decreaseKey(int arr[], int i, int key)
{
    if (arr[i] < key)
    {
        cout << "Key greater than initial one\n";
        return;
    }
    arr[i] = key;
    while (i > 0 && arr[i] < arr[parent(i)])
    {
        int temp = arr[i];
        arr[i] = arr[parent(i)];
        arr[parent(i)] = temp;
        i = parent(i);
    }
}
void insert_min(int arr[], int &n, int key)
{
    n++;
    arr[n - 1] = key;
    decreaseKey(arr, n - 1, key);
}
int main()
{
    int n = 10;
    int arr[n] = {4, 1, 3, 2, 16, 9, 10, 14, 8, 7};
    display(arr, n);
    buildmaxHeap(arr, n);
    cout << maximum(arr) << endl;
    cout << extractmax(arr, n) << endl;
    display(arr, n);
    increaseKey(arr, 3, 25);
    display(arr, n);
    insert(arr, n, 13);
    display(arr, n);
    int n1 = 10;
    int arr1[n1] = {4, 1, 3, 2, 16, 9, 10, 14, 8, 7};
    display(arr1, n1);
    buildminHeap(arr1, n1);
    cout << minimum(arr1) << endl;
    cout << extractmin(arr1, n1) << endl;
    display(arr1, n1);
    decreaseKey(arr1, 3, 5);
    display(arr1, n1);
    insert_min(arr1, n1, 13);
    display(arr1, n1);
    return 0;
}