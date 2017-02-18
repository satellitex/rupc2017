#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
  int n;
  cin>>n;
  vector<string> s(n),b;
  for(int i=0;i<n;i++) cin>>s[i];
  b=s;
  sort(b.begin(),b.end());
  for(int i=0;i<n;i++){
    int res=0;
    res+=upper_bound(b.begin(),b.end(),s[i])
      -lower_bound(b.begin(),b.end(),s[i])-1;
    res+=distance(b.begin(),lower_bound(b.begin(),b.end(),s[i]))*3;
    cout<<res<<endl;
  }
  return 0;
}
