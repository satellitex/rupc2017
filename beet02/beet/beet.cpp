#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
#define MAX 2222
ll mystoi(string s){
  if(s=="+") return 1;
  if(s=="-") return -1;
  return stoi(s);
}
signed main(){
  string s;
  cin>>s;
  ll n=s.length();
  ll k=s[2]-'0';
  vector<ll> v;
  string tmp;
  vector<string> vs;
  for(ll i=0;i<n;i++){
    if(s[i]=='+'||s[i]=='-'){
      vs.push_back(tmp);
      tmp=s[i];
    }else tmp+=s[i];
  }
  vs.push_back(tmp);
  vector<P> vp;
  for(ll i=0;i<(ll)vs.size();i++){
    //cout<<vs[i]<<endl;
    ll x=vs[i].find("x"),y=vs[i][vs[i].size()-1]-'0';
    if(x==-1){
      vp.push_back(P(mystoi(vs[i]),0));
      continue;
    }
    if((ll)vs[i].find("^")==-1) y=1;
    if(x==0) vp.push_back(P(1,y));
    else vp.push_back(P(mystoi(vs[i].substr(0,x)),y));
  }
  /*/
  for(ll j=0;j<(ll)vp.size();j++)
    cout<<vp[j].first<<" "<<vp[j].second<<endl;
  //*/
  for(ll i=-MAX;i<MAX;i++){
    ll res=0;
    for(ll j=0;j<(ll)vp.size();j++){
      ll t=1;
      for(ll l=0;l<vp[j].second;l++) t*=i;
      res+=vp[j].first*t;
    }
    //cout<<i<<" "<<res<<endl;
    if(!res) v.push_back(i);
  }
  reverse(v.begin(),v.end());
  for(ll i=0;i<k;i++) printf("(x%+lld)",-v[i]);
  puts("");
  return 0;
}

    
