#include <bits/stdc++.h>
using namespace std;
pair<bool, string> solve(string s, string t)
{
  int i = 0, j = 0;
  string ans = "";
  while (i < s.size() && j < t.size())
  {
    if (s[i] == '?')
    {
      ans += t[j];
      i++;
      j++;
    }
    else if (s[i] == t[j])
    {
      ans += t[j];
      i++;
      j++;
    }
    else if (s[i] != t[j])
    {
      ans += s[i];
      i++;
    }
  }
  while (i < s.size())
  {
    if (s[i] == '?')
      ans += 'a';
    else
      ans += s[i];
    i++;
  }
  return {j == t.size(), ans};
}
int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    string s, t;
    cin >> s >> t;
    pair<bool, string> ans = solve(s, t);
    if (ans.first)
      cout << "YES\n"
           << ans.second << endl;
    else
      cout << "NO\n";
  }
  return 0;
}