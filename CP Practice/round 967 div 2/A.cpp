#include <bits/stdc++.h>
using namespace std;
int solve(vector<int> &arr, int n)
{
  unordered_map<int, int> mpp;
  for (int a : arr)
    mpp[a]++;
  int maxf = INT_MIN;
  for (auto it : mpp)
    maxf = max(maxf, it.second);
  return n - maxf;
}
int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
      cin >> arr[i];
    cout << solve(arr, n) << endl;
  }
  return 0;
}