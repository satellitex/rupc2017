#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  string s;
  ll c[6]={};
  cin>>s;
  s+="!!!!!!!!!";
  int k=0,f=1;
  for(int i=0;i<s.size();i++){
    if(isdigit(s[i]))k*=10,k+=s[i]-'0';
    if(s[i]=='-')f=-1;
    if(s[i]=='x'){
      if(!k)k=1;
      if(s[i+1]=='^')c[s[i+2]-'0']=f*k,i+=2;
      else c[1]=f*k;
      f=1,k=0;
    }
  }
  c[0]=f*k;
  vector<ll> ans;
  for(ll i=2000;i>=-2000;i--){
    ll ss=0;
    for(ll j=0;j<6;j++)
      ss+=c[j]*pow(i,j);
    if(ss==0)ans.push_back(i);
  }
  for(int i=0;i<ans.size();i++){
    cout<<"(x";
    if(ans[i]<0)cout<<"+";
    cout<<-ans[i]<<")";
  }
  cout<<endl;
  return 0;
}
