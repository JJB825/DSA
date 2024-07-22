#include <bits/stdc++.h>
using namespace std;
int findLargest(vector<int> &arr, int n) 
{
  int low = 0;
  int high = n - 1;
  while (low < high) {
    int mid = (low + high) / 2;
    // Check if arr[mid] is largest element
    if (mid < high && arr[mid + 1] < arr[mid]) 
      return arr[mid];
    // Check if arr[mid - 1] is maximum element
    if (mid > low && arr[mid] < arr[mid - 1]) 
      return arr[mid - 1];
    if (arr[low] > arr[mid]) 
      high = mid - 1;
    else 
      low = mid + 1;
  }
  // If there is only one element in arr
  return arr[low];
}
int main()
{
  vector<int> arr = {1, 2, 3, 4, 5};
  cout << "Largest: " << findLargest(arr, 5) << endl;
  return 0;
}
