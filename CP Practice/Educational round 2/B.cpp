#include <bits/stdc++.h>
using namespace std;
int solve(int l, int r, int L, int R)
{
  if (r < L || R < l)
    return 1;
  int ans = min(r, R) - max(l, L) + 2;
  if (l == L)
    ans--;
  if (r == R)
    ans--;
  return ans;
}
int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int l, r, L, R;
    cin >> l >> r >> L >> R;
    cout << solve(l, r, L, R) << endl;
  }
  return 0;
}