#include <bits/stdc++.h>
#define N 20000
using namespace std;
typedef unsigned long long ull;
int n,num[N],cost[1<<22];
bool flg[1<<22];
set<short> cnt[1<<22];
void Max(int &a,int b){a=max(a,b);};
char count(int a){return __builtin_popcount(a);}

void marge(set<short>&a,set<short>&b){
  for(auto it=b.begin();a.size()<3&&it!=b.end();it++) a.insert(*it);
}

void mkCost(){
  for(int i=0;i<n;i++){
    int a = num[i];
    cost[a]|=a;
    if(cnt[a].size()<3)cnt[a].insert(i);
    flg[a]=cnt[a].size()>=3;
  }
  
  for(int i=(1<<22)-1;i>=0;i--){
    for(int j=0;j<22;j++){
      if(((i>>j)&1)==0)continue;
      int nbit = i ^ (1<<j);
      set<short> &I=cnt[i],&J=cnt[nbit];
      cost[nbit] |= cost[i];
      if(flg[nbit])continue;
      if(flg[i])flg[nbit]=1,J.clear();
      else marge(J,I);
      if(J.size()>=3) flg[nbit]=1,J.clear();
    }
    cnt[i].clear();
  }
}

int main(){
  cin>>n;
  for(int i=0,m;i<n;i++){
    scanf("%d",&m);
    for(int j=0,a;j<m;j++)scanf("%d",&a),num[i]|=(1<<(a-1));
  }
  mkCost();
  int ans=0;
  for(int i=0;i<(1<<22);i++)
    if(flg[i])Max(ans,count(i)*count(cost[i]));

  cout<<ans<<endl;
  return 0;
}
