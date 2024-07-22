#include <iostream>
using namespace std;
bool binarySearch(int arr[], int low, int high, int x)
{
    if (low > high)
        return false;
    int mid = (low + high) / 2;
    if (x == arr[mid])
        return true;
    else if (x > arr[mid])
        return binarySearch(arr, mid + 1, high, x);
    else if (x < arr[mid])
        return binarySearch(arr, low, mid - 1, x);
}
bool binary_Search(int arr[], int n, int x)
{
    int low = 0;
    int high = n - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (x == arr[mid])
            return true;
        else if (x > arr[mid])
        {
            low = mid + 1;
            high = high;
        }
        else if (x < arr[mid])
        {
            low = low;
            high = mid - 1;
        }
    }
    return false;
}
int main()
{
    int arr[5] = {3, 4, 5, 7, 9};
    cout << binarySearch(arr, 0, 4, 9) << endl;
    cout << binary_Search(arr, 5, 9) << endl;
    cout << binarySearch(arr, 0, 4, 8) << endl;
    cout << binary_Search(arr, 5, 8) << endl;
    return 0;
}