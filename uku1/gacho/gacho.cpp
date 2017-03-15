#include<bits/stdc++.h>
#define rank F
#define MAX_N 10005
using namespace std;
int par[MAX_N];
int rank[MAX_N];

void init(int n){
  for(int i=0;i<n;i++){
    par[i]=i;
    rank[i]=0;
  }
}

int find(int x){
  if(par[x]==x)return x;
  return par[x]=find(par[x]);
}

void unite(int x,int y){
  x=find(x);
  y=find(y);
  if(x==y)return;
  if(rank[x]<rank[y])par[x]=y;
  else{
    par[y]=x;
    if(rank[x]==rank[y])rank[x]++;
  }
}

bool same(int x,int y){return find(x)==find(y);}
struct data{
  double x;
  int a,b,c,t;
  bool operator<(const data &r)const{
    return x>r.x;
  };
};

vector<data> G;
int n,m,C,T;

int main(){
  cin>>n>>m;
  init(n);
  data in;
  for(int i=0;i<m;i++){
    cin>>in.a>>in.b>>in.c>>in.t;
    in.x=1.0*in.t/in.c;
    C+=in.c,T+=in.t;
    G.push_back(in);
  }
  sort(G.begin(),G.end());
  for(int i=0;i<G.size();i++){
    data A=G[i];
    if(same(A.a,A.b))continue;
    C-=A.c,T-=A.t;
    unite(A.a,A.b);
  }
  printf("%.8f\n",1.0*T/C);
  return 0;
}
