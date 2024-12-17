#include <bits/stdc++.h>
using namespace std;
int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int x, y, k;
    cin >> x >> y >> k;
    int resx = x / k + (x % k > 0), resy = y / k + (y % k > 0);
    if (resx > resy)
      cout << 2 * resx - 1 << endl;
    else
      cout << 2 * resy << endl;
  }
  return 0;
}