#include <bits/stdc++.h>
using namespace std;
bool solve(vector<vector<int>> &intervals, int n, int s, int m)
{
  int time = 0;
  for (int i = 0; i < n; i++)
  {
    int l = intervals[i][0], r = intervals[i][1];
    if (l - time >= s)
      return true;
    time = r;
  }
  if (intervals.back()[1] != m && m - time >= s)
    return true;
  return false;
}
int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int n, s, m;
    cin >> n >> s >> m;
    vector<vector<int>> intervals;
    for (int i = 0; i < n; i++)
    {
      int l, r;
      cin >> l >> r;
      intervals.push_back({l, r});
    }
    if (solve(intervals, n, s, m))
      cout << "YES\n";
    else
      cout << "NO\n";
  }
  return 0;
}