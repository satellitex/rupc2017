#include<bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> P;
#define MAX 2222
int mystoi(string s){
  if(s=="+") return 1;
  if(s=="-") return -1;
  return stoi(s);
}
signed main(){
  string s;
  cin>>s;
  int n=s.length();
  int k=s[2]-'0';
  vector<int> v;
  string tmp;
  vector<string> vs;
  for(int i=0;i<n;i++){
    if(s[i]=='+'||s[i]=='-'){
      vs.push_back(tmp);
      tmp=s[i];
    }else tmp+=s[i];
  }
  vs.push_back(tmp);
  vector<P> vp;
  for(int i=0;i<(int)vs.size();i++){
    //cout<<vs[i]<<endl;
    int x=vs[i].find("x"),y=vs[i][vs[i].size()-1]-'0';
    if(x==-1){
      vp.push_back(P(mystoi(vs[i]),0));
      continue;
    }
    if((int)vs[i].find("^")==-1) y=1;
    if(x==0) vp.push_back(P(1,y));
    else vp.push_back(P(mystoi(vs[i].substr(0,x)),y));
  }
  /*/
  for(int j=0;j<(int)vp.size();j++)
    cout<<vp[j].first<<" "<<vp[j].second<<endl;
  //*/
  for(int i=-MAX;i<MAX;i++){
    int res=0;
    for(int j=0;j<(int)vp.size();j++){
      int t=1;
      for(int l=0;l<vp[j].second;l++) t*=i;
      res+=vp[j].first*t;
    }
    //cout<<i<<" "<<res<<endl;
    if(!res) v.push_back(i);
  }
  reverse(v.begin(),v.end());
  for(int i=0;i<k;i++) printf("(x%+lld)",-v[i]);
  puts("");
  return 0;
}

    
