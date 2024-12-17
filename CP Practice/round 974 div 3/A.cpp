#include<bits/stdc++.h>
using namespace std;
int main() {
  int t; 
  cin>>t;
  while(t--) {
    int n,k;cin>>n>>k;
    vector<int> arr(n);
    int gold=0,ans=0;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        if(arr[i]>=k)   gold+=arr[i];
        else if(arr[i]==0 && gold>0){
            gold--;
            ans++;
        }
    }    
    cout<<ans<<endl;
  }
  return 0;
}