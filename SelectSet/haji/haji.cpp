#include <bits/stdc++.h>
#define N 20001
using namespace std;
int n,num[N];
int cost[1<<22];
set<short> cnt[1<<22];
int flg[1<<22];

void Max(int &a,int b){a=max(a,b);};
int count(int a){return __builtin_popcount(a);}

void mkCost(){
  for(int i=0;i<n;i++) cost[num[i]]|=num[i],cnt[num[i]].insert(i);

  for(int i=(1<<22)-1;i>=0;i--){
    if(cost[i]==0)continue;
    for(int j=0;j<22;j++){
      int nbit = i ^ (1<<j);
      if(((i>>j)&1)==0)continue;
      cost[nbit] |= cost[i];
      if(cnt[nbit].size()>=3)continue;
      if(cnt[i].size()>=3) cnt[nbit] = cnt[i];
      else 
	for(auto it=cnt[i].begin();it!=cnt[i].end();it++)cnt[nbit].insert(*it);
    }
    flg[i] = cnt[i].size();
    cnt[i].clear();
  }
}

int main(){
  cin>>n;
  for(int i=0;i<n;i++){
    int m;
    cin>>m;
    for(int j=0,a;j<m;j++)cin>>a,num[i]|=(1<<(a-1));
  }

  mkCost();

  int ans=0;
  for(int i=0;i<(1<<22);i++){
    if(flg[i]<3)continue;
    Max(ans,count(i)*count(cost[i]));
  }
  cout<<ans<<endl;
  
  return 0;
}
