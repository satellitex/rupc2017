#include <bits/stdc++.h>
#define N 100001
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
typedef pair<ll,P> PP;
queue<int> num[N];
vector<int> ans(N,-1);
int n;

set<int> mp;
int get_nx(int pos){
  if(ans[pos]==-1)return pos;
  if(mp.upper_bound(pos)==mp.end()) return *mp.begin();
  return *mp.upper_bound(pos);
}

void solve(){
  for(int i=0;i<n;i++)mp.insert(i);
  priority_queue<PP,vector<PP>,greater<PP> > Q;
  for(int i=0;i<n;i++)if(num[i].size())Q.push(PP(0,P(i,i)));
  
  while(!Q.empty()){
    PP t=Q.top();Q.pop();
    ll cost = t.first;
    int pos = t.second.first;
    int I = t.second.second;
    if(ans[pos]==-1)ans[pos]=num[I].front(),num[I].pop(),mp.erase(pos);
    if(num[I].empty())continue;

    int npos=get_nx(pos);
    ll ncost=cost+ (pos<npos? npos-pos:n-(pos-npos));
    Q.push(PP(ncost,P(npos,I)));
  }
}

int main(){
  cin>>n;
  for(int i=0,a;i<n;i++)scanf("%d",&a),num[a-1].push(i);
  solve();
  for(int i=0;i<n;i++)printf("%d\n",ans[i]+1);
  return 0;
}
