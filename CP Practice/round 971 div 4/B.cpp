#include <bits/stdc++.h>
using namespace std;
int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    char c;
    vector<int> ans(n, -1);
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < 4; j++)
      {
        cin >> c;
        if (c == '#')
          ans[n - 1 - i] = j + 1;
      }
    }
    for (int i : ans)
      cout << i << " ";
    cout << endl;
  }
  return 0;
}