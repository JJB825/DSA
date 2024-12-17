#include <bits/stdc++.h>
using namespace std;
vector<int> solve(int n)
{
  vector<int> ans;
}
int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    vector<int> ans = solve(n);
    if (ans.empty())
      cout << -1 << endl;
    else
    {
      for (int a : ans)
        cout << a << " ";
      cout << endl;
    }
  }
  return 0;
}