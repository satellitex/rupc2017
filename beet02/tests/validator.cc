#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

// 制約
const int N_MIN = 2;
const int N_MAX = 100000;

int n;
string s;
void input() {
  s = inf.readString();
  inf.readEof();
}

void check() {
  ensuref(s.size()<=100,"format invalid");
  ensuref(s[0]=='x',"format invalid");
  ensuref(s[1]=='^',"format invalid");
  ensuref('2'<=s[2]&&s[2]<='5',"n invalid");
  for(int i=0;i<(int)s.size();i++){
    if(!isdigit(s[i])) continue;
    int tmp=0;
    while(i<(int)s.size()&&isdigit(s[i])) tmp=tmp*10+s[i++]-'0';
    ensuref(abs(tmp)<=2000,"coefficient invalid");
  }
}

typedef long long ll;
typedef pair<ll,ll> P;
#define MAX 2222
ll mystoi(string s){
  if(s=="+") return 1;
  if(s=="-") return -1;
  return stoi(s);
}
signed solve(){
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

  for(ll i=0;i<(ll)vp.size();i++)
    for(ll j=i+1;j<(ll)vp.size();j++)
      ensuref(vp[i].second>vp[j].second,"ans order invalid");
  
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
  
  ensuref((ll)v.size()==k,"number of ans invalid");
  for(ll i=0;i<(ll)v.size();i++)
    ensuref(v[i]!=0,"ans invalid");
  return 0;
}

    
int main() {
  registerValidation();
  input();
  solve();
  check();
  return 0;
}

