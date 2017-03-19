#include <bits/stdc++.h>
#define N 100001
using namespace std;
const int MAX_N = 1<<17;
vector<int>G[N];
vector<int> ord;
void dfs(int pos){
  ord.push_back(pos);
  for(int i=0;i<G[pos].size();i++)dfs(G[pos][i]);
  ord.push_back(pos);
}

int val[N][10];

void add(int L,int R,int x,int y){
  if(x==y)return;
  for(int i=L;i<R;i++) val[i][y]+=val[i][x],val[i][x]=0;
}

int sum(int L,int R,int x,int y){
  int res=0;
  for(int i=L;i<R;i++)
    for(int j=x;j<=y;j++) res+=val[i][j];
  return res;
}

int main(){
  int n,q;
  scanf("%d%d",&n,&q);
  for(int i=0,a,b;i<n-1;i++)scanf("%d%d",&a,&b),G[a].push_back(b);

  dfs(0);
  vector<int>L(n,1e9),R(n,0);
  set<int> S;
  for(int i=0;i<ord.size();i++){
    int cnt = S.size();
    L[ord[i]] = min(L[ord[i]],cnt);
    R[ord[i]] = max(R[ord[i]],cnt);
    S.insert(ord[i]);
  }

  for(int i=0;i<n;i++) val[i][0]=1;

  while(q--){
    int t,r,x,y;
    scanf("%d%d%d%d",&t,&r,&x,&y);
    //cout<<(t==2? "change":"sum")<<" "<<r<<" "<<x<<" "<<y<<endl;
    if(t==2)add(L[r],R[r],x,y);
    else printf("%d\n",sum(L[r],R[r],x,y));
  }
   return 0;
}
