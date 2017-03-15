#include<bits/stdc++.h>
#define MAX_N 100005
using namespace std;
typedef pair<int,int> P;
const int DAT_SIZE=(1<<18)-1;
int N;
int data[DAT_SIZE],datb[DAT_SIZE];

void add(int a,int b,int x,int k,int l,int r){
  if(a<=l&&r<=b)data[k]+=x;
  else if(l<b&&a<r){
    datb[k]+=(min(b,r)-max(a,l))*x;
    add(a,b,x,k*2+1,l,(l+r)/2);
    add(a,b,x,k*2+2,(l+r)/2,r);
  }
}

int sum(int a,int b,int k,int l,int r){
  if(b<=l||r<=a)return 0;
  if(a<=l&&r<=b)return data[k]*(r-l)+datb[k];
  int res=(min(b,r)-max(a,l))*data[k];
  res+=sum(a,b,k*2+1,l,(l+r)/2);
  res+=sum(a,b,k*2+2,(l+r)/2,r);
  return res;
}

vector<int> G[MAX_N];
int n,q,u,v,num;
P A[MAX_N];

int dfs(int x,int px){
  int res=(1e9);
  for(int i=0;i<G[x].size();i++)
    if(G[x][i]!=px)res=min(res,dfs(G[x][i],x));
  A[x].first=num++;
  res=min(res,num-1);
  A[x].second=res;
  return res;
}

int main(){
  cin>>n>>q;
  for(int i=0;i<n-1;i++){
    cin>>u>>v;
    G[u].push_back(v);
    G[v].push_back(u);
  }
  dfs(0,-1);
  int t,x,y;
  for(int i=0;i<q;i++){
    cin>>t>>x>>y;
    
  }
  return 0;
}
