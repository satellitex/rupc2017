#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vec;
typedef pair<ll,ll> P;

ll s2ll(string s){
  ll res;
  stringstream ss;
  ss<<s;
  ss>>res;
  return res;
}

string s;
int p=0;

P change(string s){
  if(s[0]=='+')s=s.substr(1);

  ll fi,se;
  if(s.find('x') == string::npos){
    stringstream ss;
    ss<<s;
    ss>>se;
    fi=0;
    return P(fi,se);
  }
  string tmp="";
  for(int i=0;i<(int)s.size();i++){
    if(s[i]=='x')break;
    tmp+=s[i];
  }
  if(tmp=="")se=1;
  else se=s2ll(tmp);

  if(s.find('^')==string::npos){
    return P(1,se); 
  }
  
  tmp="";
  for(int i=0;i<(int)s.size();i++){
    if(s[i]=='^')tmp="";
    else tmp+=s[i];
  }
  fi=s2ll(tmp);
  return P(fi,se);
}

map< ll, ll > T;
void change(){
  
  int p=0,len=s.size();
  
  while(p<len){
    string tmp="";
    tmp+=s[p];
    p++;
    
    while(p<len&&s[p]!='+'&&s[p]!='-'){
      tmp+=s[p];
      p++;
    }

    //    cout<<tmp<<endl;
    
    P p=change(tmp);
    T[ p.first ]+= p.second;
  }

  //  for(P p:T){
  //    cout<<p.first<<' '<<p.second<<endl;
  //  }
}

ll calc(ll x){
  ll res=0;
  ll B=1;
  for(int i=0;i<=5;i++){
    res+=B*T[i];
    B*=x;
  }
  return res;
}

int main(){
  int N;
  //  cin>>N;
  
  cin>>s;
  change();

  vec v;
  for(ll i=-2000;i<=2000;i++){
    if( calc(i) == 0 )v.push_back(i);
  }

  sort(v.begin(),v.end());
  reverse(v.begin(),v.end());
  
  for(int i=0;i<v.size();i++){
    cout<<"(x";
    v[i]*=-1;
    if(v[i]>0)cout<<"+";
    cout<<v[i]<<")";
  }
  cout<<endl;
  return 0;
}
