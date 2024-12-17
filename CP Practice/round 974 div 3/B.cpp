#include<bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin>>t;
  while(t--) {
    int n,k;cin>>n>>k;
    if(((n*(n+1)/2)-((n-k)*(n-k+1)/2))&1) cout<<"NO\n";
    else  cout<<"YES\n"; 
  }
  return 0;
}