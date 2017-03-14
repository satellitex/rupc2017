#include <bits/stdc++.h>
#define N 10001
#define MAX_N N
#define rank Asdfiasofsad
using namespace std;
typedef long long ll;
const ll INF = 1LL<<55;

class UF{
public:
  vector<int> par,rank;
  UF(){
    par.resize(MAX_N),rank.resize(MAX_N);
    for(int i=0;i<MAX_N;i++)par[i]=i,rank[i]=0;
  }
  UF(int n){
    par.resize(n),rank.resize(n);
    for(int i=0;i<n;i++)par[i]=i,rank[i]=0;
  }

  int find(int x){
    if(par[x]==x)return x;
    return par[x]=find(par[x]);
  }
  
  void unite(int x,int y){
    x=find(x), y=find(y);
    if(x==y)return;
    if(rank[x]<rank[y])par[x]=y;
    else{
      par[y]=x;
      if(rank[x]==rank[y])rank[x]++;
    }
  }
  bool same(int x,int y){return find(x)==find(y);}
};

typedef pair<int,int> P;
typedef pair<double,P> PP;
int A[N],B[N],C[N],t[N];
int n,m;
bool check(double x){
  if(m==n-1)return 1;
  double csum=0,tsum=0;
  vector<PP> edge(m);
  for(int i=0;i<m;i++){
    edge[i] = PP(x*C[i]-t[i],P(A[i],B[i]));
    csum+=C[i];
    tsum+=t[i];
  }
  sort(edge.begin(),edge.end());
  UF U(n);
  double r=0;
  for(int i=0;i<m;i++){
    double cost = edge[i].first;
    int a = edge[i].second.first;
    int b = edge[i].second.second;
    if(U.same(a,b)) continue;
    U.unite(a,b);
    r+=cost;
  }
  return r<=x*csum-tsum;
}

int main(){
  cin>>n>>m;
  for(int i=0;i<m;i++)scanf("%d%d%d%d",&A[i],&B[i],&C[i],&t[i]);

  double L=0,M,R=1e9,cnt=100;
  while(cnt--){
    M = (L+R)/2;
    if(check(M)) R = M;
    else L = M;
  }
  printf("%.10f\n",L);
  return 0;
}
