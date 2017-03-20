#include <bits/stdc++.h>
#define N 20001
using namespace std;
typedef unsigned long long ull;
const ull B = 1777771;
int n,num[N],cost[1<<22],flg[1<<22];
set<short> cnt[1<<22];
void Max(int &a,int b){a=max(a,b);};
int count(int a){return __builtin_popcount(a);}

ull StoH(set<short> &S){
  ull res=0;
  for(auto it=S.begin();it!=S.end();it++)res=res*B+(*it+1);
  return res;  
}

void marge(set<short>&a,set<short>&b){
  for(auto it=b.begin();it!=b.end()&&a.size()<3;it++) a.insert(*it);
}

ull H[1<<22];
void mkCost(){

  for(int i=0;i<n;i++){
    int a = num[i];
    cost[a]|=a;
    if(cnt[a].size()<3)cnt[a].insert(i);
    flg[a]=cnt[a].size()>=3;
    H[a] = StoH(cnt[a]);
  }
  
  for(int i=(1<<22)-1;i>=0;i--){
    for(int j=0;j<22;j++){
      if(((i>>j)&1)==0)continue;
      int nbit = i ^ (1<<j);
      set<short> &I=cnt[i],&J=cnt[nbit];
      cost[nbit] |= cost[i];
      if(flg[nbit]||H[i]==H[nbit])continue;
      if(flg[i])flg[nbit]=1,J.clear();
      else marge(J,I),H[nbit] = StoH(J);
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
